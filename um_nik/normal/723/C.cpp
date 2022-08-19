#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 2020;
int n, m;
int a[N];
int b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] <= m)
			b[a[i]]++;
	}
	int k = n / m;
	int it = 1;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= m && b[a[i]] <= k) continue;
		while(it <= m && b[it] >= k) it++;
		if (it > m) break;
		ans++;
		if (a[i] <= m) b[a[i]]--;
		a[i] = it;
		b[it]++;
	}
	printf("%d %d\n", k, ans);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}