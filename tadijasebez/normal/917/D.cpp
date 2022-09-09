#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
const int mod=1e9+7;
int powmod(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int inv(int x){ return powmod(x,mod-2);}
struct Matrix
{
	int n,m,a[N][N],sw;
	Matrix(int a=0, int b=0):n(a),m(b),sw(0){}
	Matrix Del(int x, int y)
	{
		Matrix ans(n-1,m-1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==x || j==y) continue;
				ans.a[i-(i>x)][j-(j>y)]=a[i][j];
			}
		}
		return ans;
	}
	void Gauss()
	{
		for(int i=1;i<=min(n,m);i++)
		{
			bool ok=0;
			for(int j=i;j<=n;j++) if(a[j][i])
			{
				if(j!=i)
				{
					for(int k=i;k<=m;k++) swap(a[i][k],a[j][k]);
					sw++;
				}
				ok=1;
				break;
			}
			if(!ok) break;
			for(int j=i+1;j<=n;j++)
			{
				int mul=(ll)(mod-a[j][i])*inv(a[i][i])%mod;
				for(int k=i;k<=m;k++) a[j][k]+=(ll)a[i][k]*mul%mod,a[j][k]%=mod;
			}
		}
	}
	int det()
	{
		if(n!=m) return 0;
		Gauss();
		int ans=sw&1?mod-1:1;
		for(int i=1;i<=n;i++) ans=(ll)ans*a[i][i]%mod;
		return ans;
	}
	void SolveEq(int ans[])
	{
		Gauss();
		for(int i=1;i<=min(n,m-1);i++) if(!a[i][i]) return;
		for(int i=min(n,m-1);i>=1;i--)
		{
			ans[i]=a[i][m];
			for(int j=i+1;j<m;j++)
			{
				ans[i]-=(ll)a[i][j]*ans[j]%mod;
				if(ans[i]<0) ans[i]+=mod;
			}
			ans[i]=(ll)ans[i]*inv(a[i][i])%mod;
		}
	}
};
int ans[N];
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	Matrix work(n,n),adj(n,n),poly(n+1,n+1);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),adj.a[u][v]=adj.a[v][u]=1;
	for(int i=0;i<=n;i++)
	{
		work.sw=0;
		for(int j=1;j<=n;j++) work.a[j][j]=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++) if(j!=k)
			{
				work.a[j][k]=(adj.a[j][k]?-i:-1);
				work.a[j][j]-=work.a[j][k];
				if(work.a[j][k]<0) work.a[j][k]+=mod;
			}
		}
		poly.a[i+1][n+1]=work.Del(n,n).det();
		for(int j=1;j<=n;j++) poly.a[i+1][j]=powmod(i,j-1);
	}
	poly.SolveEq(ans);
	for(int i=1;i<=n;i++) printf("%i ",ans[i]);
	return 0;
}