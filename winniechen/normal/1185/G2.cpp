#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 2505
typedef long long ll;
const int mod = 1000000007;
int q_pow(int x,int n=mod-2){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
vector<int >v[4];
int f[4][N][M],n,m,g[N][N][M],h[N][N][N][2],u[N][N][M],s[4],fac[N],inv[N];
void get_h()
{
	h[0][0][0][0]=h[1][0][0][0]=h[0][1][0][1]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=i+j&&k<=n;k++)
			{
				if(!h[i][j][k][0])
					h[i][j][k][0]=((i>0?h[i-1][j][k][1]:0)+(i>1&&k>0?h[i-1][j][k-1][0]:0))%mod;
				if(!h[i][j][k][1])
					h[i][j][k][1]=((j>0?h[i][j-1][k][0]:0)+(j>1&&k>0?h[i][j-1][k-1][1]:0))%mod;
			}
}
void get_f()
{
	for(int l=1;l<=3;l++)
	{
		f[l][0][0]=1;int sum=0;
		for(int i=0;i<v[l].size();sum+=v[l][i],i++)
			for(int j=i;~j;j--)
				for(int k=0;k<=sum;k++)
					(f[l][j+1][k+v[l][i]]+=f[l][j][k])%=mod;
		s[l]=sum;
	}
}
void get_g()
{
	for(int i=0;i<=v[1].size();i++)for(int j=0;j<=s[1];j++)u[i][0][j]=f[1][i][j];
	for(int i=0;i<=v[1].size();i++)
		for(int j=0;j<v[2].size();j++)
			for(int k=j;~k;k--)
				for(int l=0;l<=s[1]+s[2];l++)
					(u[i][k+1][l+v[2][j]]+=u[i][k][l])%=mod;
	for(int i=0;i<=v[1].size();i++)
		for(int j=0;j<=v[2].size();j++)
			for(int k=0;k<=s[1]+s[2];k++)if(u[i][j][k])
				for(int l=0;l<=i+j;l++)
					g[i+j][l][k]=(g[i+j][l][k]+(ll)u[i][j][k]*(h[i][j][l][0]+h[i][j][l][1])%mod*fac[i]%mod*fac[j])%mod;
}
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),v[y].push_back(x);
	if(v[1].size()>v[2].size())swap(v[1],v[2]);
	if(v[1].size()>v[3].size())swap(v[1],v[3]);
	if(v[2].size()>v[3].size())swap(v[2],v[3]);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=q_pow(fac[n]);for(int i=n;i;i--)inv[i-1]=(ll)inv[i]*i%mod;
	get_h();get_f();get_g();int ans=0;
	for(int i=0;i<=min(m,s[3]);i++)
		for(int j=0;j<=v[3].size();j++)if(f[3][j][i])
		{
			int tmp=(ll)f[3][j][i]*fac[j]%mod,lim=v[1].size()+v[2].size();
			for(int k=max(0,j-1);k<=lim;k++)
				for(int l=0;l<=min(j,k);l++)if(g[k][l][m-i])
				// {
					ans=(ans+(ll)g[k][l][m-i]*tmp%mod*C(k+1-l,j-l))%mod;
					// printf("%d %d\n",k,l);
					// printf("%d %d %d %d %d\n",i,j,tmp,ans,g[k][l][m-i]);
				// }
		}
	printf("%d\n",ans);
}