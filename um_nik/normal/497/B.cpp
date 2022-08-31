#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int N = 100100;
int a[N];
vector<int> ans[N];
int s1[N], s2[N];

int solve(int t)
{
	int idx = 0;
	int B = 0, C = 0;
	int last = -1;
	while (idx < n)
	{
		int b = s1[n] - s1[idx];
		int c = s2[n] - s2[idx];
		if (b < t && c < t) return 0;
		int l = idx;
		int r = n;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			b = s1[m] - s1[idx];
			c = s2[m] - s2[idx];
			if (b >= t || c >= t)
				r = m;
			else
				l = m;
		}
		if (s1[r] - s1[idx] == t)
		{
			B++;
			last = 1;
		}
		else
		{
			C++;
			last = 2;
		}
		idx = r;
	}
	if (C == B) return 0;
	if (B > C)
	{
		if (last == 2) return 0;
		return B;
	}
	else
	{
		if (last == 1) return 0;
		return C;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	s1[0] = s2[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		s1[i] = s1[i - 1];
		s2[i] = s2[i - 1];
		if (a[i - 1] == 1)
			s1[i]++;
		else
			s2[i]++;
	}
	int cnt = 0;
	for (int t = 1; t <= n; t++)
	{
		int s = solve(t);
		if (s == 0) continue;
		ans[s].push_back(t);
		cnt++;
	}
	printf("%d\n", cnt);
	for (int s = 1; s <= n; s++)
		for (int i = 0; i < (int)ans[s].size(); i++)
			printf("%d %d\n", s, ans[s][i]);

	return 0;
}