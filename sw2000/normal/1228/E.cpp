#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=255;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll C[maxn][maxn],dp[maxn][maxn];
ll mm[maxn],mmm[maxn];

int main()
{
	ll n,m;
	cin>>n>>m;

    for(int I=0;I<maxn;I++)
	{
		C[I][0]=C[I][I]=1;
		for(int J=1;J<I;J++)
            C[I][J]=(C[I-1][J]+C[I-1][J-1])%mod;
	}
	mm[0]=mmm[0]=1;
	for(int i=1;i<maxn;i++)
    {
        mm[i]=mm[i-1]*(m-1)%mod;
        mmm[i]=mmm[i-1]*m%mod;
    }

    for(int i=1;i<=n;i++)
        dp[1][i]=C[n][i]*mm[n-i]%mod;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                ll a=dp[i-1][k]*mmm[k]%mod;
                a=a*C[n-k][j-k]%mod;
                a=a*mm[n-j]%mod;
                dp[i][j]=(dp[i][j]+a)%mod;
            }
            ll a=dp[i-1][j]*mm[n]%mod;
            dp[i][j]=(dp[i][j]+mod-a)%mod;
        }
    }

   cout<<dp[n][n];

    return 0;
}