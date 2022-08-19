#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ans;
int n, k;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		ans += max(x - 3 * k, x % k);
	}
	printf("%d\n", ans);

	return 0;
}