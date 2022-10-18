#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 200000;

int main()
{
	static char a[1 + MaxN + 1], b[1 + MaxN + 1];
	scanf("%s %s", a + 1, b + 1);
	int n = strlen(a + 1), m = strlen(b + 1);
	
	static int l[1 + MaxN + 1], r[1 + MaxN + 1];
	
	for (int i = 1, j = 1; i <= n; i++)
	{
		if (j <= m && a[i] == b[j])
			j++;
		l[i] = j - 1;
	}
	for (int i = n, j = m; i >= 1; i--)
	{
		if (j > 0 && a[i] == b[j])
			j--;
		r[i] = j + 1;
	}
	
	static int sum[1 + MaxN + 1][26];
	fill(sum[0], sum[0] + 26, 0);
	for (int i = 1; i <= m; i++)
	{
		copy(sum[i - 1], sum[i - 1] + 26, sum[i]);
		sum[i][b[i] - 'a']++;
	}
	
	bool ok = true;
	for (int i = 1; i <= n; i++)
		if (l[i] < r[i] || sum[l[i]][a[i] - 'a'] - sum[r[i] - 1][a[i] - 'a'] == 0)
		{
			ok = false;
			break;
		}
	
	if (ok)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}