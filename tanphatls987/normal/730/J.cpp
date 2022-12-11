#include <bits/stdc++.h>

#define fs first
#define sc second

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 110;

pii a[MAXN];
int f[2][MAXN][MAXN*MAXN];
int n, s, st, k;

void nhap()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i].sc);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i].fs);
}

int cal()
{
	st = 0;
	for(int i=1; i<=n; i++)
		st += a[i].sc;
	int tmp = 0;
	for(int i=1; i<=n; i++)
	{
		tmp += a[i].fs;
		if (tmp >= st)
			return i;
	}
	return n+1;
}

void solve()
{
	s = 0;
	for(int i=1; i<=n; i++)
		s += a[i].fs;
	int now = 0;
	for(int i=0; i<=k; i++)
		for(int j=0; j<=s; j++)
			f[now][i][j] = -1;
	f[now][0][0] = 0;
	for(int i=1; i<=n; i++)
	{
		now = 1-now;
		for(int ip=0; ip<=k; ip++)
			for(int jp=0; jp<=s; jp++)
				f[now][ip][jp] = -1;
		f[now][0][0] = 0;
		for(int ip=1; ip<=k; ip++)
		{
			for(int jp=0; jp<=s; jp++)
			{
				if (f[1-now][ip][jp] != -1)
					f[now][ip][jp] = max(f[now][ip][jp], f[1-now][ip][jp]);
				if (jp - a[i].fs >= 0 && f[1-now][ip-1][jp - a[i].fs] != -1)
				{
					f[now][ip][jp] = max(f[now][ip][jp], f[1-now][ip-1][jp - a[i].fs] + a[i].sc);
				}
			}
		}
	}
	int res = 0;
	for(int i=st; i<=s; i++)
	if (f[now][k][i] != -1)
		res = max(res, f[now][k][i]);
	printf("%d %d\n", k, st - res);
}

int main()
{
	//freopen("test.inp", "r", stdin);
	nhap();
	sort(a+1, a+n+1, greater < pii > ());
	k = cal();
	solve();
	return 0;
}