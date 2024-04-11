#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 100100;
int n, m;
vector<int> g[N];
int deg[N];
int col[N];
int a[2 * N];

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
		deg[v]++;
		deg[u]++;
	}
	return;
}

bool dfs(int v)
{
	for (int u : g[v])
	{
		if (col[u] == -1)
		{
			col[u] = col[v] ^ 1;
			if (!dfs(u)) return false;
		}
		else
			if (col[v] ^ col[u] ^ 1)
				return false;
	}
	return true;
}

bool bicol()
{
	int C = 0;
	for (int i = 0; i < n; i++)
		col[i] = -1;
	for (int i = 0; i < n; i++)
	{
		if (col[i] != -1) continue;
		col[i] = C;
		if (!dfs(i)) return false;
		C += 2;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	if (!bicol())
	{
		printf("0 1\n");
		return 0;
	}
	if (m == 0)
	{
		ll x = 1;
		x *= (ll)n;
		x *= (ll)(n - 1);
		x *= (ll)(n - 2);
		x /= 6LL;
		cout << "3 " << x << endl;
		return 0;
	}
	bool flag = true;
	for (int v = 0; v < n; v++)
		flag &= (deg[v] <= 1);
	if (flag)
	{
		ll x = m;
		x *= (ll)(n - 2);
		cout << "2 " << x << endl;
		return 0;
	}
	for (int v = 0; v < n; v++)
		a[col[v]]++;
	ll ans = 0;
	for (int i = 0; i < 2 * N; i++)
		ans += (ll)a[i] * (ll)(a[i] - 1) / 2LL;
	cout << "1 " << ans << endl;
	
	return 0;
}