#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int max_n=4e3+5;
int S[max_n][max_n],B[max_n],C[max_n][max_n],f[max_n],g[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	S[0][0]=B[0]=C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1;
		int res=0;
		for(int j=1;j<=i;++j)
		{
			S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
			res+=S[i][j],res-=res>=mod?mod:0;
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]-=C[i][j]>=mod?mod:0;
		}
		B[i]=res;
	}
	for(int i=0;i<=n;++i)
		f[i]=1ll*C[n][i]*B[n-i]%mod;
	for(int i=0;i<=n;++i)
	{
		int res=0;
		for(int j=i;j<=n;++j)
			res=(res+((j-i)&1?-1ll:1ll)*C[j][i]*f[j])%mod;
		res+=res<0?mod:0;
		g[i]=res;
	}
	int Pow=1,ans=0;
	for(int i=1;i<=n;++i)
	{
		Pow<<=1,Pow-=Pow>=mod?mod:0;
		ans=(ans+(Pow-1ll)*g[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}