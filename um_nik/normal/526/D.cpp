#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = (int)1e6 + 100;
int n;
char s[N];
int z[N];
int a[N];
char ans[N];
int k;

void calc_z()
{
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
		if (i <= r)
			z[i] = min(r - i, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d %d %s", &n, &k, s);
	calc_z();
	ans[n] = (char)0;

	if (k == 1)
	{
		for (int i = 0; i < n; i++)
			ans[i] = '1';
		printf("%s\n", ans);
		return 0;
	}

	for (int d = 1; d * k <= n; d++)
	{
		if (z[d] < d * (k - 1)) continue;
		int l = d * k;
		int r = min(d + z[d], d * (k + 1)) + 1;
		a[l]++;
		a[r]--;
	}
	int bal = 0;
	for (int i = 1; i <= n; i++)
	{
		bal += a[i];
		if (bal > 0)
			ans[i - 1] = '1';
		else
			ans[i - 1] = '0';
	}
	printf("%s\n", ans);

	return 0;
}