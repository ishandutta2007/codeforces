#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int N = (int)5e5 + 100;
const int B = (int)2e3;
const int S = N / B + 10;
const int INF = (int)1e9 + 3;
int a[N];
int b[S];
map<int, int> mp[S];
int n, q, m;

void read()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	m = (n + B - 1) / B;
	for (int i = 0; i < m; i++)
	{
		for (int j = i * B; j < (i + 1) * B && j < n; j++)
			mp[i][a[j]]++;
	}
	return;
}

void add(int l, int r, int x)
{
	int L = l / B;
	int R = r / B;
	if (L == R)
	{
		for (int i = l; i < r; i++)
		{
			if (a[i] < INF)
			{
				mp[L][a[i]]--;
				if (mp[L][a[i]] == 0)
					mp[L].erase(a[i]);
			}
			a[i] = min(INF, a[i] + x);
			if (a[i] < INF)
				mp[L][a[i]]++;
		}
		return;
	}
	for (int i = l; i < (L + 1) * B; i++)
	{
		if (a[i] < INF)
		{
			mp[L][a[i]]--;
			if (mp[L][a[i]] == 0)
				mp[L].erase(a[i]);
		}
		a[i] = min(INF, a[i] + x);
		if (a[i] < INF)
			mp[L][a[i]]++;
	}
	for (int i = R * B; i < r; i++)
	{
		if (a[i] < INF)
		{
			mp[R][a[i]]--;
			if (mp[R][a[i]] == 0)
				mp[R].erase(a[i]);
		}
		a[i] = min(INF, a[i] + x);
		if (a[i] < INF)
			mp[R][a[i]]++;
	}
	for (int i = L + 1; i < R; i++)
		b[i] = min(INF, b[i] + x);
	return;
}

void answer(int x)
{
	int L = -1, R = -1;
	for (int i = 0; i < m; i++)
	{
		if (b[i] > x) continue;
		int y = x - b[i];
		if (mp[i].count(y) > 0)
		{
			if (L == -1)
				L = i;
			R = i;
		}
	}
	if (L == -1)
	{
		cout << "-1\n";
		return;
	}
	int l = -1;
	for (int i = L * B; l == -1; i++)
		if (a[i] + b[L] == x)
			l = i;
	int r = -1;
	for (int i = R * B; i < (R + 1) * B && i < n; i++)
		if (a[i] + b[R] == x)
			r = i;
	cout << r - l << endl;
	return;
}

void query()
{
	int t;
	cin >> t;
	if (t == 1)
	{
		int l, r;
		int x;
		cin >> l >> r >> x;
		l--;
		add(l, r, x);
	}
	else
	{
		int x;
		cin >> x;
		answer(x);
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	read();
	while(q--)
		query();

	return 0;
}