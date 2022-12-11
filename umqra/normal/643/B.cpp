#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a, b, c, d;
vector<int> w;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &a, &b, &c, &d);

	if (n == 4 || m == n - 1 || m == n)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == a || i == b || i == c || i == d) continue;
		w.push_back(i);
	}
	printf("%d %d ", a, c);
	for (int x : w)
		printf("%d ", x);
	printf("%d %d\n", d, b);
	printf("%d %d ", c, a);
	for (int x : w)
		printf("%d ", x);
	printf("%d %d\n", b, d);

	return 0;
}