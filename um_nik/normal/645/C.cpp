#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100100;
int n, k;
char s[N];
int l[N], r[N];
int ans = N;

void solve(int L, int M, int R)
{
	if (M == -1) throw;
	ans = min(ans, max(M - L, R - M));
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	k++;
	scanf("%s", s);
	int x = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
			x = i;
		l[i] = x;
	}
	x = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '0')
			x = i;
		r[i] = x;
	}
	int R = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '0') continue;
		while(R < n && sum < k)
		{
			if (s[R] == '0') sum++;
			R++;
		}
		if (sum < k) break;

		int m = (i + R) / 2;
		solve(i, l[m], R - 1);
		solve(i, r[m], R - 1);

		sum--;
	}
	printf("%d\n", ans);

	return 0;
}