#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,M=998244353;
int n,k,fac[N],a[N],inv[N];
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;	
}
int C(int x,int y){
	return fac[x]*inv[y]%M*inv[x-y]%M;
}
signed main(){
	scanf("%lld%lld",&n,&k);int cnt=0;
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<n;i++)
		if (a[i]!=a[i+1])cnt++;
	if (a[1]!=a[n])cnt++;
	int ans=ksm(k,n),v=0;
	for (int i=0;i<=cnt/2;i++)(v+=ksm(k-2,cnt-i*2)*C(cnt,i)%M*C(cnt-i,i))%=M;
	v=v*ksm(k,n-cnt)%M;
	printf("%lld\n",(ans-v+M)*(M/2+1)%M);
}