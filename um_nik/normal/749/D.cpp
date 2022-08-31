#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200200;
bool used[N];
int n;
vector<int> a[N];
int ord[N];
int ordSz;
int b[N];
int m;

void solve()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		used[b[i]] = 1;
	}
	int p = 0;
	while(p < ordSz && used[ord[p]]) p++;
	if (p == ordSz)
	{
		printf("0 0\n");
		return;
	}
	int q = p + 1;
	p = ord[p];
	while(q < ordSz && used[ord[q]]) q++;
	if (q == ordSz)
	{
		printf("%d %d\n", p, a[p][0]);
		return;
	}
	printf("%d %d\n", p, *lower_bound(a[p].begin(), a[p].end(), a[ord[q]].back()));
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		ord[i] = x;
	}
	reverse(ord, ord + n);
	for (int i = 0; i < n; i++)
	{
		if (used[ord[i]]) continue;
		used[ord[i]] = 1;
		ord[ordSz++] = ord[i];
	}
	for (int i = 1; i <= n; i++)
		used[i] = 0;
	int q;
	scanf("%d", &q);
	while(q--)
	{
		solve();
		for (int i = 0; i < m; i++)
			used[b[i]] = 0;
	}

	return 0;
}