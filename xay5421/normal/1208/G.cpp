// author: xay5421
// created: Fri Oct 29 08:35:02 2021
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
const int N=1000005;
int n,K,p[N],phi[N],id[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1,phi[1]=1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
			}else{
				phi[i*p[j]]=phi[i]*(p[j]-1);
			}
		}
	}
}
int main(){
	sieve();
	scanf("%d%d",&n,&K);
	rep(i,1,n-2)id[i]=i+2;
	sort(id+1,id+n-1,[&](int x,int y){return phi[x]<phi[y];});
	LL ans=2;
	rep(i,1,K){
		ans+=phi[id[i]];
	}
	{
		LL tmp=1;
		rep(i,1,n-2)if(id[i]&1){
			if(K>0)--K,tmp+=phi[id[i]];
		}
		if(!K)ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}