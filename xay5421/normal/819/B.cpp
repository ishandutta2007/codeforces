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
using LL=long long;
const int N=1000005;
int n,p[N],cnt[N];
LL s1[N],ans=5e18,res,cur,dt;
/*struct line{
	LL k,b;
	line operator()(LL x)const{
		return k*x+b;
	}
	line operator+(const line&rhs)const{
		return (line){k+rhs.k,b+rhs.b};
	}
}l1[N],l2[N];*/
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i]);
		cur+=abs(i-p[i]);
		dt+=p[i]>i?-1:1;
		cnt[(p[i]-i+n)%n]+=1;
	}
	ans=cur,res=0;
	int j=n;
	rep(i,1,n-1){
		cur+=dt;
		cur-=abs(p[j]-(n+1));
		cur+=abs(p[j]-1);
		if(umin(ans,cur)){
			res=i;
		}
		dt+=2*cnt[i]-2;
		j=(j+n-2)%n+1;
	}
	printf("%lld %lld\n",ans,res);
	return 0;
}