#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=1e6+3;
const int g=2;
int pow(int x, int k)
{
	int ans=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ans=(ll)ans*x%mod;
	return ans;
}
int inv(int x){ return pow(x,mod-2);}
const int N=100;
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
int poly[N];
int main()
{
	/*int n=mod,g;
	vector<int> f;
	int tmp=n-1;
	for(int i=2;i*i<=tmp;i++)
	{
		if(tmp%i==0)
		{
			f.pb(i);
			f.pb(tmp/i);
		}
	}
	for(g=2;g<n;g++)
	{
		bool ok=1;
		for(auto j:f) if(pow(g,j)==1) ok=0;
		if(ok){ printf("%i\n",g);break;}
	}*/
	Matrix mt;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	mt.n=50;
	mt.m=12;
	for(int i=1;i<=50;i++)
	{
		int x=rng()%mod;
		printf("? %i\n",x);
		fflush(stdout);
		int ans;
		scanf("%i",&ans);
		if(ans==0)
		{
			printf("! %i\n",x);
			fflush(stdout);
			return 0;
		}
		mt.a[i][12]=ans;
		for(int j=1;j<=11;j++) mt.a[i][j]=pow(x,j-1);
	}
	mt.SolveEq(poly);
	for(int i=0;i<mod;i++)
	{
		int tmp=0,mul=1;
		for(int j=1;j<=11;j++)
		{
			tmp+=(ll)mul*poly[j]%mod;
			if(tmp>=mod) tmp-=mod;
			mul=(ll)mul*i%mod;
		}
		if(tmp==0)
		{
			printf("! %i\n",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1\n");
	fflush(stdout);
	return 0;
}