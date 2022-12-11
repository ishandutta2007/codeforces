#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10, mod = 998244353;
namespace Math{
	long long fac[N],inv[N];
	long long fp(long long x,long long y){
		long long res=1;
		while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
		return res;
	}
	void init(){
		fac[0]=inv[0]=1;
		for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=fp(fac[N-1],mod-2);
		for(int i=N-2;i>=1;i--){
			inv[i]=inv[i+1]*(i+1)%mod;
		}
	}
	long long C(long long x,long long y){
		return fac[x]*inv[y]%mod*inv[x-y]%mod;
	}
	long long A(long long x,long long y){
		return fac[x]*inv[x-y]%mod;
	}
};
using namespace Math;
int n, a[N],ct[N][2],mi=1e9,mx;
int main() {
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]),mi=min(mi,a[i]);
	int t=mi+n-1;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ct[a[i]][x]++;
	}
	if(mx>t)return puts("0"),0;
	if(mx==mi)return printf("%lld\n",fac[n]),0;
	int ans=fac[n]*inv[n-ct[t][1]]%mod,cnt=0;
	for(int i=mi;i<=mx;i++){
		if(ct[i][0]&&cnt<t-i)ans=0;
		cnt+=ct[i][0];
		ans=ans*fac[ct[i][0]]%mod;
		if(i!=t&&ct[i][1]&&(ct[i][1]>1||cnt<i-mi))ans=0;
		cnt+=ct[i][1];
	}
	printf("%d\n",ans);
	return 0;
}