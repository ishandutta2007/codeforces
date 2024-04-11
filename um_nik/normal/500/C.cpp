#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 2000;
int n, m;
int a[N], b[N];
int ans;
bool used[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		b[i]--;
	}
	ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			used[j] = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (b[j] == b[i]) break;
			used[b[j]] = 1;
		}
		for (int j = 0; j < n; j++)
			if (used[j])
				ans += a[j];
	}
	printf("%d\n", ans);

	return 0;
}