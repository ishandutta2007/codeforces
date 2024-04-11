#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, x, a[Maxn], b[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		printf("%d ", b[i] + x);
		x = max(x, b[i] + x);
	}
	return 0;
}