#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll f[5][55][55][55],f1[55][2505],f2[55][2505],f3[55][2505],s[55][55][55],fact[55];
int n,T,t[55],g[55],num1,num2,num3;
int main()
{
	fact[0]=1;
	for(int i=1;i<=50;i++)
	  fact[i]=fact[i-1]*i%MOD;
	f[1][1][0][0]=f[2][0][1][0]=f[3][0][0][1]=1;
	for(int i=0;i<=50;i++)
	for(int j=0;j<=50;j++)
	for(int k=0;k<=50;k++)
	{
		s[i][j][k]=(f[1][i][j][k]+f[2][i][j][k]+f[3][i][j][k])%MOD*fact[i]%MOD*fact[j]%MOD*fact[k]%MOD;
		if(f[1][i][j][k])
		{
			f[1][i][j][k]%=MOD;
			f[2][i][j+1][k]+=f[1][i][j][k];
			f[3][i][j][k+1]+=f[1][i][j][k];
		}
		if(f[2][i][j][k])
		{
			f[2][i][j][k]%=MOD;
			f[1][i+1][j][k]+=f[2][i][j][k];
			f[3][i][j][k+1]+=f[2][i][j][k];
		}
		if(f[3][i][j][k])
		{
			f[3][i][j][k]%=MOD;
			f[1][i+1][j][k]+=f[3][i][j][k];
			f[2][i][j+1][k]+=f[3][i][j][k];
		}
	}
	scanf("%d%d",&n,&T);
	f1[0][0]=f2[0][0]=f3[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&g[i]);
		if(g[i]==1)
		{
			num1++;
			for(int x=i;x>=1;x--)
			for(int j=T;j>=t[i];j--)
			{
				f1[x][j]+=f1[x-1][j-t[i]];
				if(f1[x][j]>=MOD)f1[x][j]-=MOD;
			}
		}
		if(g[i]==2)
		{
			num2++;
			for(int x=i;x>=1;x--)
			for(int j=T;j>=t[i];j--)
			{
				f2[x][j]+=f2[x-1][j-t[i]];
				if(f2[x][j]>=MOD)f2[x][j]-=MOD;
			}
		}
		if(g[i]==3)
		{
			num3++;
			for(int x=i;x>=1;x--)
			for(int j=T;j>=t[i];j--)
			{
				f3[x][j]+=f3[x-1][j-t[i]];
				if(f3[x][j]>=MOD)f3[x][j]-=MOD;
			}
		}
	}
	ll ans=0,ans2=0,ans3=0;
	for(int t1=0;t1<=T;t1++)
	for(int i=0;i<=num1;i++)
	{
		if(f1[i][t1]==0)continue;
		ans2=0;
		for(int t2=0;t1+t2<=T;t2++)
		{
			int t3=T-t1-t2;
			for(int j=0;j<=num2;j++)
			{
				if(f2[j][t2]==0)continue;
				ans3=0;
				for(int k=max(0,max(i-j,j-i)-1);k<=min(num3,i+j+1);k++)
				  ans3+=s[i][j][k]*f3[k][t3];
				ans3%=MOD;
				ans2+=ans3*f2[j][t2]%MOD;
			}
		}
		ans+=ans2*f1[i][t1]%MOD;
	}
	printf("%I64d\n",ans%MOD);
	return 0;
}