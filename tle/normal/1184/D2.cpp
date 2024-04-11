//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
const int maxn = 252;
const int mod = 1e9+7;
ll qpow(ll x, ll k){return k==0?1:qpow(x*x%mod, k>>1)*(k&1?x:1)%mod;}
int n, k;
int inv[maxn];
int sumL[maxn][maxn][maxn], sumR[maxn][maxn][maxn];
int coef[maxn][maxn][maxn];
void calc_sumR(int row)
{
	for (int i=1; i<n-row; i++)
	{
		for (int j=0; j<=n; j++) sumR[row][i][j] = (sumR[row][i-1][j]+coef[row][i-1][j])%mod;
	}
}
void calc_sumL(int row, int col)
{
	for (int i=0; i<=n; i++)
	{
		sumL[row][col][i] = (sumL[row-1][col][i]+coef[row-1][col][i])%mod;
	}
}
void upd(int &x, ll v) {x=(x+v)%mod;}
int a[maxn][maxn], val[maxn];
void gauss(int n)
{
	for (int i=1; i<=n; i++)
	{
		int pivot = -1;
		for (int j=i; j<=n; j++)
		{
			if (a[j][i]%mod!=0)
			{
				pivot = j;
				break;
			}	
		}
		assert(pivot!=-1);
		swap(a[i], a[pivot]);
		int coef = qpow(a[i][i], mod-2);
		for (int j=0; j<=n; j++) a[i][j] = 1ll*a[i][j]*coef%mod;
		for (int j=1; j<=n; j++)
		{
			if (i==j) continue;
			int coef = a[j][i];
			for (int k=0; k<=n; k++)
			{
				a[j][k] = (a[j][k]-1ll*coef*a[i][k])%mod;
			}
		}
	}
	val[0] = 1;
	for (int i=1; i<=n; i++) val[i] = -a[i][0];
}
int query(int x, int y)
{
	int ret = 0;
	for (int t=0; t<=n; t++)
	{
		upd(ret, 1ll*val[t]*coef[x][y][t]);
	}
	return (ret%mod+mod)%mod;
}
int main()
{
	for (int i=1; i<maxn; i++) inv[i] = qpow(i, mod-2);
	int sx, sy, sl, sk;
	cin>>sl>>sk>>n;
	sx = sk-1;
	sy = sl-sk;
	for (int i=1; i<=n-2; i++)
	{
		coef[1][i][i] = 1;
	}
	coef[0][0][0] = 1;
	for (int i=1; i<n; i++)
	{
		coef[0][i][0] = i+1;
		coef[i][0][0] = i+1;
	}
	calc_sumR(1);
	for (int i=1; i<=n; i++) calc_sumL(1, i);
	for (int i=2; i<n; i++)
	{
		for (int j=1; j<=n-i; j++)
		{
			int x = i-1, y = j;
			int dp = 1ll*(x+y+1)*inv[n]%mod;
			int cp = (1-dp)%mod;
//			cerr<<"i="<<i<<" j="<<j<<" cp="<<cp<<" dp="<<dp<<endl;
			for (int t=0; t<=n; t++)
			{
				int &cur = coef[i][j][t];
				upd(cur, -coef[x][y][t]);
				upd(cur, 1ll*(y+1)*inv[x+y+2]%mod*coef[x][y+1][t]%mod*cp);
				upd(cur, 1ll*sumL[x][y][t]*inv[x+y]%mod*dp);
				upd(cur, 1ll*sumR[x][y][t]*inv[x+y]%mod*dp);
			}
			int self_coef = 1ll*(x+1)*inv[x+y+2]%mod*cp%mod;
			if (self_coef%mod!=0)
			{
				int c = qpow(-self_coef, mod-2);
				for (int t=0; t<=n; t++) coef[i][j][t] = 1ll*coef[i][j][t]*c%mod;
			}
			calc_sumL(i, j);
		}
		calc_sumR(i);
	}
	for (int i=1; i<=n-2; i++)
	{
//		cerr<<"grid:"<<i+1<<","<<n-1-i<<endl;
		for (int j=0; j<=n; j++) a[i][j] = coef[i+1][n-1-i][j];
//		for (int j=0; j<=n; j++) cerr<<a[i][j]<<" ";
//		cerr<<endl;
	}
	gauss(n-2);
	cout<<query(sx, sy)<<endl;
	return 0;
}