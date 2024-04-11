#include <bits/stdc++.h>
using namespace std;

set<int> st[100005];
int a[100005];
int n;
unordered_map<int, long long> fw2d[100005];

void addfw(int L, int R, long long diff)
{
	for (int x = L; x <= n; x += x & -x)
	{
		for (int y = R; y <= n; y += y & -y)
		{
			auto res = fw2d[x].emplace(y, diff);
			if (res.second == false) res.first->second += diff;
		}
	}
}

void add(int L, int R)
{
	addfw(n - L + 1, R, R - L);
}

void sub(int L, int R)
{
	addfw(n - L + 1, R, L - R);
}

long long query(int L, int R)
{
	long long ret = 0;
	for (int x = L; x; x -= x & -x)
	{
		for (int y = R; y; y -= y & -y)
		{
			auto itr = fw2d[x].find(y);
			if (itr != fw2d[x].end()) ret += itr->second;
		}
	}
	return ret;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		st[a[i]].insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == *st[a[i]].rbegin()) continue;
		int R = *st[a[i]].upper_bound(i);

		add(i, R);
	}

	for (int i = 0; i < m; i++)
	{
		int T, b, c;
		scanf("%d%d%d", &T, &b, &c);
		if (T == 1) 
		{
			if (a[b] == c) continue;

			auto itr = st[a[b]].find(b);

			if (next(itr) != st[a[b]].end()) sub(b, *next(itr));
			if (itr != st[a[b]].begin()) sub(*prev(itr), b);
			if (itr != st[a[b]].begin() && next(itr) != st[a[b]].end()) add(*prev(itr), *next(itr));

			st[a[b]].erase(itr);

			a[b] = c;
			itr = st[c].insert(b).first;

			if (itr != st[c].begin()) add(*prev(itr), b);
			if (next(itr) != st[c].end()) add(b, *next(itr));
			if (itr != st[c].begin() && next(itr) != st[c].end()) sub(*prev(itr), *next(itr));
		}
		else
		{
			printf("%lld\n", query(n - b + 1, c));
		}
	}

	fflush(stdout);
	_Exit(0);
}