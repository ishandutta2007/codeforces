#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MaxN = 100;

inline void trans(int *p, int *q, const int &n)
{
	static int t[MaxN + 1];
	for (int i = 1; i <= n; i++)
		t[i] = p[q[i]];
	copy(t + 1, t + n + 1, p + 1);
}

int main()
{
	int n, k;
	static int q[MaxN + 1], r[MaxN + 1];
	static int s[MaxN + 1];
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &q[i]), r[q[i]] = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	
	static int p[MaxN + 1];
	
	int fs = INT_MAX, bs = INT_MAX;
	
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i <= k; i++)
	{
		if (equal(p + 1, p + n + 1, s + 1))
		{
			fs = i;
			break;
		}
		trans(p, q, n);
	}
	
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i <= k; i++)
	{
		if (equal(p + 1, p + n + 1, s + 1))
		{
			bs = i;
			break;
		}
		trans(p, r, n);
	}
	
	bool res = false;
	if (fs != INT_MAX)
	{
		int rest = k - fs;
		if (rest == 0 || (rest % 2 == 0 && (fs > 1 || bs > 1)))
			res = true;
	}
	if (bs != INT_MAX)
	{
		int rest = k - bs;
		if (rest == 0 || (rest % 2 == 0 && (fs > 1 || bs > 1)))
			res = true;
	}
	
	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}