#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1005;
int val[Maxn][Maxn], n, a[Maxn], id[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), id[i] = i;
	sort(id + 1, id + 1 + n, [](int x, int y){return a[x] > a[y];});
	printf("%d\n", n + 1);
	for (int i = 1; i <= n; i++)
			for (int j = i + 1; a[id[i]]; j = j % (n + 1) + 1)
				val[j][id[i]] = 1, a[id[i]]--;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d", val[i][j]);
		printf("\n");
	}
	return 0;
}