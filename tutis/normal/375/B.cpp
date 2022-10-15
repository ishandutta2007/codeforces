/*input
4 3
100
011
000
101
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct Fenwick
{
	vector<int>A;
	int n;
	Fenwick(int n = 1): n(n)
	{
		A = vector<int>(n + 1, 0);
	}
	inline int lsb(int x)
	{
		return ((x) & (-x));
	}
	void add(int i, int w)
	{
		for (; i <= n; i += lsb(i))
		{
			A[i] += w;
		}
	}
	int get(int i)
	{
		i = min(i, n);
		int ret = 0;
		for (; i > 0; i -= lsb(i))
		{
			ret += A[i];
		}
		return ret;
	}
	int get(int a, int b)
	{
		return get(b) - get(a - 1);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	string A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int ans = 0;
	vector<pair<int, int>>prid[m + 1];
	vector<pair<int, int>>atim[m + 1];
	for (int i = 0; i < n; i++)
	{
		int l = 0;
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == '0')
			{
				l = j + 1;
				continue;
			}
			if (j == m - 1 || A[i][j + 1] == '0')
			{
				int a = l;
				int b = j;
				prid[a].push_back({a, b});
				atim[b + 1].push_back({a, b});
			}
		}
	}
	Fenwick Z(m + 1);
	for (int l = 0; l < m; l++)
	{
		for (pair<int, int> a : prid[l])
		{
			Z.add(1, 1);
			Z.add(a.second + 2, -1);
		}
		for (pair<int, int> a : atim[l])
		{
			Z.add(1, -1);
			Z.add(a.second + 2, 1);
		}
		for (int r = l; r < m; r++)
		{
			ans = max(ans, (r - l + 1) * Z.get(r + 1));
		}
	}
	cout << ans << "\n";
}