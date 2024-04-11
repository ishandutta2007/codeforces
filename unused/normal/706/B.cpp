#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int price[100005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &price[i]);
	sort(price + 1, price + 1 + n);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		printf("%d\n", (int)(upper_bound(price + 1, price + 1 + n, t) - price - 1));
	}
}