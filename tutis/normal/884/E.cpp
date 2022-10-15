/*input
2 8
5F
E3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pa[32768];
int root(int i)
{
	if (pa[i] == i)
		return i;
	return pa[i] = root(pa[i]);
}
void merge(int x, int y)
{
	pa[root(x)] = root(y);
}
bool X[16384];
bool S[16384];
bool nenaudojami[16384];
int x[32768];
int y[32768];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 32768; i++)
		pa[i] = i;
	int ans = 0;
	for (int t = 0; t < n; t++)
	{
		string s;
		cin >> s;
		for (int i = 0; i < m / 4; i++)
		{
			int nr;
			if (s[i] >= 'A' && s[i] <= 'F')
				nr = s[i] - 'A' + 10;
			else
				nr = s[i] - '0';
			S[4 * i + 3] = nr % 2;
			nr /= 2;
			S[4 * i + 2] = nr % 2;
			nr /= 2;
			S[4 * i + 1] = nr % 2;
			nr /= 2;
			S[4 * i + 0] = nr % 2;
		}
		for (int i = 0; i < m; i++)
		{
			if (S[i] && X[i])
			{
				merge(i, i + m);
			}
		}
		for (int i = 1; i < m; i++)
		{
			if (S[i] && S[i - 1])
			{
				merge(i + m - 1, i + m);
			}
		}
		fill_n(nenaudojami, m, true);
		for (int i = 0; i < m; i++)
		{
			if (root(m + i) < m)
				nenaudojami[root(m + i)] = false;
		}
		for (int i = 0; i < m; i++)
			if (X[i] && nenaudojami[i] && (root(i) == i))
			{
				ans++;
			}

		for (int i = 0; i < m; i++)
			y[i] = root(i + m);
		for (int i = 0; i < m; i++)
			x[y[i]] = i;
		for (int i = 0; i < m; i++)
			pa[i] = x[y[i]];
		for (int i = m; i < 2 * m; i++)
			pa[i] = i;



		if (t == n - 1)
		{
			for (int i = 0; i < m; i++)
			{
				ans += (S[i] && (root(i) == i));
			}
		}
		for (int i = 0; i < m; i++)
			X[i] = S[i];
	}
	cout << ans << "\n";
}