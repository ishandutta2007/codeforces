#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long n,a[N],nxt[N<<1];
int main(){
    scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	n=unique(a+1,a+1+n)-a-1;
	for(long long i=1;i<=n;i++)nxt[a[i]-1]=i;
	nxt[2*N-1]=n+1;
	for(long long i=N*2-1;i;i--)if(!nxt[i])nxt[i]=nxt[i+1];
	for(long long i=1;i<=2e6+10;i++){
		long long L=1ll*i*i,R=1ll*i*i+i;
		if(R<a[1])continue;
		long long l=max(0ll,L-a[1]),r=R-a[1];
		long long ansl=l,ansr=r;
		for(long long o=2;o<=n;){
			long long k=ceil((sqrt(1+4*a[o]+4*l)-1)/2);
			long long kk=1ll*k*k+k-l;
			long long nx=kk<N*2?nxt[kk]:n+1;
			if(nx==o)o=nx;
			ansl=max(ansl,1ll*k*k-a[o]);
			ansr=min(ansr,1ll*k*k+k-a[nx-1]);
			o=nx;
		}
		if(ansl<=ansr)return printf("%lld\n",ansl),0;
	}
}