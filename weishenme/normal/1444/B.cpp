#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300005,M=998244353;
int n,fac[N],ans,a[N],inv[N];
inline int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=2*n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+2*n+1);
	fac[0]=inv[0]=1;
	for (int i=1;i<=2*n;i++)fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for (int i=1;i<=n;i++)(ans+=a[2*n+1-i]-a[i])%=M;
	printf("%lld\n",ans*fac[2*n]%M*inv[n]%M*inv[n]%M);
}