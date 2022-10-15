/**
4 5
2 3 1 4 4
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int l[m + 1];
	int a[n + 1];
	fill_n(a, n + 1, -1);
	for (int i = 1; i <= m; i++)
		cin >> l[i];
	for (int i = 1; i < m; i++)
	{
		int A = (l[i + 1] - l[i] + n) % n;
		if (A == 0)
			A = n;
		if (a[l[i]] == A || a[l[i]] == -1)
			a[l[i]] = A;
		else
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i] == a[j] && a[i] != -1)
			{
				cout << -1;
				return 0;
			}
	set<int>X;
	for (int i = 1; i <= n; i++)
	{
		X.insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != -1)
			X.erase(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == -1)
		{
			a[i] = *(X.begin());
			X.erase(X.begin());
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}