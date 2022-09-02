#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int N=100005,B=780,INF=0X3F3F3F3F;
int n,K,len,x[N],y[N],id[N];
int dp[2][B+5],w[B+5];
int main(){
	scanf("%d%d",&n,&K);
	int low=max(1,n-775);
	int ans=0;
	rep(i,1,K){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<low){
			ans+=3;
		}else{
			::x[++len]=n-x+1;
			::y[len]=y;
		}
	}
	iota(id+1,id+len+1,1);
	sort(id+1,id+len+1,[&](int lhs,int rhs){return y[lhs]!=y[rhs]?y[lhs]<y[rhs]:x[lhs]<x[rhs];});
	int pos=1;
	memset(dp[0],63,sizeof(dp[0]));
	dp[0][0]=0;
	rep(i,1,n){
		memset(dp[i&1],63,sizeof(dp[i&1]));
		fill(w,w+B,0);
		while(pos<=len&&y[id[pos]]<=i){
			w[x[id[pos]]]+=3;
			++pos;
		}
		per(j,B-2,0)w[j]+=w[j+1];
		umin(dp[i&1][0],dp[(i-1)&1][0]+w[1]);
		rep(j,1,B-1){
			umin(dp[i&1][j-1],dp[(i-1)&1][j]+w[j]);
		}
		int mn=*min_element(dp[(i-1)&1],dp[(i-1)&1]+B);
		rep(j,0,B-1){
			umin(dp[i&1][j],mn+w[j+1]+j*(j+1)/2+2);
		}
	}
	printf("%d\n",ans+*min_element(dp[n&1],dp[n&1]+B));
	return 0;
}