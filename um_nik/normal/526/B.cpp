#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 3000;
int n;
int a[N];
int ans = 0;

int main()
{
	scanf("%d", &n);
	int sz = 1 << (n + 1);
	for (int i = 2; i < sz; i++)
		scanf("%d", &a[i]);
	for (int i = sz - 2; i > 0; i -= 2)
	{
		if (2 * i < sz)
		{
			a[i] += a[2 * i];
			a[i + 1] += a[2 * (i + 1)];
		}
		ans += max(a[i], a[i + 1]) - min(a[i], a[i + 1]);
		a[i] = a[i + 1] = max(a[i], a[i + 1]);
	}
	printf("%d\n", ans);

	return 0;
}