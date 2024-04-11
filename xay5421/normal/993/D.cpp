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
using LL=long long;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
const int N=55;
int n;
struct node{
	int a,b;
	bool operator<(const node&rhs)const{
		return a!=rhs.a?a>rhs.a:b>rhs.b;
	}
}p[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i].a);
	}
	rep(i,1,n){
		scanf("%d",&p[i].b);
	}
	sort(p+1,p+1+n);
	int sum=0;
	vector<vector<LL> >dp(1,vector<LL>(sum+1,INFLL));
	dp[0][0]=0;
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&p[i].a==p[j].a)++j;
		int nsum=sum;
		rep(k,i,j-1){
			nsum+=p[k].b;
		}
		vector<vector<LL> >ndp(j,vector<LL>(nsum+1,INFLL));
		LL sa=0;
		int sb=0;
		rep(k,i,j){ // [i,k),[k,j)
			rep(big,j-k,i-1){
				rep(tt,0,sum){
					umin(ndp[big-(j-k)+(k-i)][tt+sb],dp[big][tt]+sa);
				}
			}
			sa+=p[k].a;
			sb+=p[k].b;
		}
		sum=nsum;
		dp=move(ndp);
	}
	double ans=1e100;
	rep(big,0,n)rep(tt,0,sum)if(dp[big][tt]<INFLL){
		umin(ans,1.*dp[big][tt]/tt);
	}
	printf("%.0f\n",ceil(ans*1000));
	return 0;
}