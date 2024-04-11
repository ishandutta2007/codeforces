#include<bits/stdc++.h>
using namespace std;
const int N=3000005,mod=1e9+7,mx=3000001;
int n,q,fc[N],iv[N],i3,f[N][3];
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int c(int n,int m){return n<m?0:1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
int main()
{
	fc[0]=1;
	for(int i=1;i<=mx;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	iv[mx]=qp(fc[mx],mod-2);
	for(int i=mx-1;i>=0;i--)
		iv[i]=1ll*iv[i+1]*(i+1)%mod;
	i3=qp(3,mod-2);
	scanf("%d%d",&n,&q);
	f[0][0]=f[0][1]=f[0][2]=n;
	for(int i=1;i<=3*n;i++)
	{
		int v1=c(3*n+1,i+1),v2=f[i-1][1],v3=f[i-1][2];
		f[i][0]=1ll*(2ll*v2+v3+v1)%mod*i3%mod;
		f[i][1]=(f[i][0]-v2+mod)%mod;
		f[i][2]=(f[i][1]-v3+mod)%mod;
	}
	while(q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x][0]);
	}
	return 0;
}