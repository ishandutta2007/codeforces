#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,k,s,fc[N],iv[N];
int c(int n,int m){if(m<0||n<m||n<0)return 0;return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
void sol()
{
	scanf("%d%d",&n,&k);
	k--;
	s=1;
	for(int i=1;i<=n&&n-(i-1)*k>=0;i++)
		s=(s+1ll*c(n-(i-1)*k,i)*qp(c(n,i),mod-2)%mod)%mod;
	printf("%d\n",s);
}
int main()
{
	fc[0]=iv[0]=1;
	for(int i=1;i<=100000;i++)
		fc[i]=1ll*fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}