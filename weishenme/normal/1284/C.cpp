#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005;
int fac[N],n,M,ans,inv[N];
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
signed main(){
	scanf("%lld%lld",&n,&M);
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for (int i=1;i<=n;i++)(ans+=fac[i]*(n-i+1)%M*(n-i+1)%M*fac[n-i])%=M;
	printf("%lld\n",ans);
}