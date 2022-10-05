#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q, f[Maxn], deg[Maxn];
long long t[Maxn], val[Maxn];
set <pair <long long, int> > A, B, Se[Maxn];
void insert(int x)
{
	Se[f[x]].insert(make_pair(val[x], x));
	Se[f[f[x]]].insert(make_pair(val[f[x]], f[x]));
	Se[f[f[f[x]]]].insert(make_pair(val[f[f[x]]], f[f[x]]));
	if (Se[f[x]].size())
	{
		A.insert(make_pair(Se[f[x]].begin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
		B.insert(make_pair(Se[f[x]].rbegin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
	}
	if (Se[f[f[x]]].size())
	{
		A.insert(make_pair(Se[f[f[x]]].begin() -> first + t[f[f[x]]] / (deg[f[f[x]]] + 2), f[f[x]]));
		B.insert(make_pair(Se[f[f[x]]].rbegin() -> first + t[f[f[x]]] / (deg[f[f[x]]] + 2), f[f[x]]));
	}
	if (Se[f[f[f[x]]]].size())
	{
		A.insert(make_pair(Se[f[f[f[x]]]].begin() -> first + t[f[f[f[x]]]] / (deg[f[f[f[x]]]] + 2), f[f[f[x]]]));
		B.insert(make_pair(Se[f[f[f[x]]]].rbegin() -> first + t[f[f[f[x]]]] / (deg[f[f[f[x]]]] + 2), f[f[f[x]]]));
	}
}
void erase(int x)
{
	if (Se[f[x]].size())
	{
		A.erase(make_pair(Se[f[x]].begin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
		B.erase(make_pair(Se[f[x]].rbegin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
	}
	if (Se[f[f[x]]].size())
	{
		A.erase(make_pair(Se[f[f[x]]].begin() -> first + t[f[f[x]]] / (deg[f[f[x]]] + 2), f[f[x]]));
		B.erase(make_pair(Se[f[f[x]]].rbegin() -> first + t[f[f[x]]] / (deg[f[f[x]]] + 2), f[f[x]]));
	}
	if (Se[f[f[f[x]]]].size())
	{
		A.erase(make_pair(Se[f[f[f[x]]]].begin() -> first + t[f[f[f[x]]]] / (deg[f[f[f[x]]]] + 2), f[f[f[x]]]));
		B.erase(make_pair(Se[f[f[f[x]]]].rbegin() -> first + t[f[f[f[x]]]] / (deg[f[f[f[x]]]] + 2), f[f[f[x]]]));
	}
	Se[f[x]].erase(make_pair(val[x], x));
	Se[f[f[x]]].erase(make_pair(val[f[x]], f[x]));
	Se[f[f[f[x]]]].erase(make_pair(val[f[f[x]]], f[f[x]]));
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &t[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i]), deg[f[i]]++;
	for (int i = 1; i <= n; i++)
	{
		val[f[i]] += t[i] / (deg[i] + 2);
		val[i] += t[i] - t[i] / (deg[i] + 2) * (deg[i] + 1);
	}
	for (int i = 1; i <= n; i++)
		Se[f[i]].insert(make_pair(val[i], i));
	for (int i = 1; i <= n; i++)
		if (Se[i].size())
		{
			A.insert(make_pair(Se[i].begin() -> first + t[i] / (deg[i] + 2), i));
			B.insert(make_pair(Se[i].rbegin() -> first + t[i] / (deg[i] + 2), i));
		}
	for (int i = 1; i <= q; i++)
	{
		int opt, x, y;
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d%d", &x, &y);
			erase(x);
			
			val[f[x]] -= t[x] / (deg[x] + 2);
			
			val[f[f[x]]] -= t[f[x]] / (deg[f[x]] + 2);
			val[f[x]] -= t[f[x]] - t[f[x]] / (deg[f[x]] + 2) * (deg[f[x]] + 1);
			deg[f[x]]--;
			val[f[x]] += t[f[x]] - t[f[x]] / (deg[f[x]] + 2) * (deg[f[x]] + 1);
			val[f[f[x]]] += t[f[x]] / (deg[f[x]] + 2);
			
			insert(x);
			A.erase(make_pair(Se[f[x]].begin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
			B.erase(make_pair(Se[f[x]].rbegin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
			Se[f[x]].erase(make_pair(val[x], x));
			if (Se[f[x]].size())
			{
				A.insert(make_pair(Se[f[x]].begin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
				B.insert(make_pair(Se[f[x]].rbegin() -> first + t[f[x]] / (deg[f[x]] + 2), f[x]));
			}
			
			f[x] = y;
			
			erase(x);
			
			val[f[x]] += t[x] / (deg[x] + 2);
			
			val[f[f[x]]] -= t[f[x]] / (deg[f[x]] + 2);
			val[f[x]] -= t[f[x]] - t[f[x]] / (deg[f[x]] + 2) * (deg[f[x]] + 1);
			deg[f[x]]++;
			val[f[x]] += t[f[x]] - t[f[x]] / (deg[f[x]] + 2) * (deg[f[x]] + 1);
			val[f[f[x]]] += t[f[x]] / (deg[f[x]] + 2);
			
			insert(x);
		}
		else if (opt == 2)
		{
			scanf("%d", &x);
			printf("%lld\n", val[x] + t[f[x]] / (deg[f[x]] + 2));
		}
		else printf("%lld %lld\n", A.begin() -> first, B.rbegin() -> first);
	}
	return 0;
}