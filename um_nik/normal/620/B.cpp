#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans;
int l, r;

int solve(int x)
{
	int res = 0;
	while(x > 0)
	{
		res += a[x % 10];
		x /= 10;
	}
	return res;
}

int main()
{
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; i++)
		ans += solve(i);
	printf("%d\n", ans);

	return 0;
}