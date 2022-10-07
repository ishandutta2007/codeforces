#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll f[705][705][2][2],digit[705],num,ans;
ll quick_pow(ll a,ll x)
{
	ll ans=1;
	while(x)
	{
		if(x&1)ans=ans*a%MOD;
		a=a*a%MOD;
		x>>=1;
	}
	return ans;
}
void dp(int x)
{
	memset(f,0,sizeof(f));
	f[0][0][0][1]=1;
	for(int i=0;i<=num;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(k>digit[i+1])
				{
					if(k>x)
					{
						f[i+1][j+1][0][0]+=f[i][j][0][0];
						f[i+1][j+1][1][0]+=f[i][j][1][0];
					}
					else if(k==x)
					{
						f[i+1][j][1][0]+=f[i][j][0][0];
						f[i+1][j][0][0]+=f[i][j][0][0];
						f[i+1][j+1][1][0]+=f[i][j][1][0];
					}
					else
					{
						f[i+1][j][0][0]+=f[i][j][0][0];
						f[i+1][j][1][0]+=f[i][j][1][0];
					}
				}
				else if(k==digit[i+1])
				{
					if(k>x)
					{
						f[i+1][j+1][0][0]+=f[i][j][0][0];
						f[i+1][j+1][0][1]+=f[i][j][0][1];
						f[i+1][j+1][1][0]+=f[i][j][1][0];
						f[i+1][j+1][1][1]+=f[i][j][1][1];
					}
					else if(k==x)
					{
						f[i+1][j][1][0]+=f[i][j][0][0];
						f[i+1][j][0][0]+=f[i][j][0][0];
						f[i+1][j][1][1]+=f[i][j][0][1];
						f[i+1][j][0][1]+=f[i][j][0][1];
						f[i+1][j+1][1][0]+=f[i][j][1][0];
						f[i+1][j+1][1][1]+=f[i][j][1][1];
					}
					else
					{
						f[i+1][j][0][0]+=f[i][j][0][0];
						f[i+1][j][0][1]+=f[i][j][0][1];
						f[i+1][j][1][0]+=f[i][j][1][0];
						f[i+1][j][1][1]+=f[i][j][1][1];
					}
				}
				else
				{
					if(k>x)
					{
						f[i+1][j+1][0][0]+=f[i][j][0][0];
						f[i+1][j+1][0][0]+=f[i][j][0][1];
						f[i+1][j+1][1][0]+=f[i][j][1][0];
						f[i+1][j+1][1][0]+=f[i][j][1][1];
					}
					else if(k==x)
					{
						f[i+1][j][1][0]+=f[i][j][0][0];
						f[i+1][j][0][0]+=f[i][j][0][0];
						f[i+1][j][1][0]+=f[i][j][0][1];
						f[i+1][j][0][0]+=f[i][j][0][1];
						f[i+1][j+1][1][0]+=f[i][j][1][0];
						f[i+1][j+1][1][0]+=f[i][j][1][1];
					}
					else
					{
						f[i+1][j][0][0]+=f[i][j][0][0];
						f[i+1][j][0][0]+=f[i][j][0][1];
						f[i+1][j][1][0]+=f[i][j][1][0];
						f[i+1][j][1][0]+=f[i][j][1][1];
					}
				}
				f[i+1][j+1][0][0]%=MOD;
				f[i+1][j+1][0][1]%=MOD;
				f[i+1][j+1][1][0]%=MOD;
				f[i+1][j+1][1][1]%=MOD;
				f[i+1][j][0][0]%=MOD;
				f[i+1][j][0][1]%=MOD;
				f[i+1][j][1][0]%=MOD;
				f[i+1][j][1][1]%=MOD;
			}
		}
	}
	for(int i=0;i<=num;i++)
	{
		ans+=(f[num][i][1][0]+f[num][i][1][1])%MOD*quick_pow(10,i)%MOD*x%MOD;
		ans%=MOD;
	}
}
char s[1005];
void read()
{
	scanf("%s",s);
	num=strlen(s);
	for(int i=0;i<num;i++)
	  digit[i+1]=s[i]-'0';
}
int main()
{
	read();
	for(int i=1;i<10;i++)dp(i);
	printf("%lld\n",ans);
	return 0;
}