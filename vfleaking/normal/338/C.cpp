#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 8;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

inline int getMinV(s64 n)
{
	int res = 0;
	for (int i = 2; (s64)i * i <= n; i++)
		while (n % i == 0)
			res++, n /= i;
	if (n != 1)
		res++;
	return res;
}

int n;
s64 a[MaxN + 1];
int minV[MaxN + 1];

int outcome;
int fa[MaxN + 1];

inline void dfs(const int &v, const int &cur, const int &cntRoot)
{
	if (v == n + 1)
	{
		int t = cur;
		if (cntRoot > 1)
			t++;
		tension(outcome, t);
		return;
	}

	for (fa[v] = 0; fa[v] < v; fa[v]++)
		if (fa[v] == 0 || a[fa[v]] % a[v] == 0)
		{
			int t = cur;
			if (fa[v] == 0)
				t += minV[v];
			else
				a[fa[v]] /= a[v];
			if (minV[v] != 1)
				t++;
			dfs(v + 1, t, cntRoot + (fa[v] == 0));

			if (fa[v] != 0)
				a[fa[v]] *= a[v];
		}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1, greater<s64>());
	for (int i = 1; i <= n; i++)
		minV[i] = getMinV(a[i]);

	outcome = INT_MAX;
	dfs(1, 0, 0);
	
	cout << outcome << endl;

	return 0;
}