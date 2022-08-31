#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n, m;
bool ans[N];
bool u[N];
int a[N];
int cnt;
int b[N][2];

void solve()
{
	scanf("%d%d", &m, &n);
	m--;
	for (int i = 0; i < n; i++)
	{
		ans[i] = u[i] = 0;
		scanf("%d", &a[i]);
	}
	cnt = 0;
	int idx = -1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &b[i][j]);
		b[i][0]--;
		if (b[i][1] && idx == -1)
			idx = i;
		if (idx != -1 && b[i][0] != -1)
			u[b[i][0]] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (i == idx)
		{
			int t = -1;
			for (int j = 0; j < n; j++)
			{
				if (u[j]) continue;
				if (a[j] <= cnt)
					ans[j] = 1;
				if (t == -1 || a[j] < a[t])
					t = j;
			}
			if (a[t] > cnt) throw;
			cnt -= a[t];
			a[t] = 0;
		}
		if (b[i][0] == -1)
			cnt++;
		else
			a[b[i][0]]--;
	}
	for (int i = 0; i < n; i++)
		if (a[i] <= cnt)
			ans[i] = 1;
	for (int i = 0; i < n; i++)
		if (ans[i])
			printf("Y");
		else
			printf("N");
	printf("\n");
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();

	return 0;
}