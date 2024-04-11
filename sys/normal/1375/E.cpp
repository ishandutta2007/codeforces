#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, ct, ans, tmp[Maxn], ord[Maxn], a[Maxn], b[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i], ord[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i] > a[j]) ans++;
	printf("%d\n", ans);
	sort(ord + 1, ord + 1 + n, [](int x, int y){return a[x] == a[y] ? x < y : a[x] < a[y];});
	for (int i = 1; i <= n; i++)
	{
		ct = 0;
		for (int j = ord[i] + 1; j <= n; j++)
			if (a[ord[i]] > a[j]) tmp[++ct] = j;
		sort(tmp + 1, tmp + 1 + ct, [](int x, int y){return b[x] == b[y] ? x < y : b[x] < b[y];});
		for (int j = ct; j >= 1; j--)
			printf("%d %d\n", ord[i], tmp[j]), swap(b[ord[i]], b[tmp[j]]);
	}
	return 0;
}