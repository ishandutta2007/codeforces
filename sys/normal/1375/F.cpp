#include <bits/stdc++.h>
using namespace std;

int x, ord[5];
long long a[5];
int main()
{
	scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
	ord[1] = 1, ord[2] = 2, ord[3] = 3;
	sort(ord + 1, ord + 1 + 3, [](int x, int y){return a[x] < a[y];});
	printf("First\n");
	fflush(stdout);
	printf("100000000000\n");
	fflush(stdout);
	scanf("%d", &x);
	a[x] += 100000000000LL;
	ord[1] = 1, ord[2] = 2, ord[3] = 3;
	sort(ord + 1, ord + 1 + 3, [](int x, int y){return a[x] < a[y];});
	printf("%lld\n", a[ord[3]] * 2 - a[ord[2]] - a[ord[1]]);
	fflush(stdout);
	scanf("%d", &x);
	a[x] += a[ord[3]] * 2 - a[ord[2]] - a[ord[1]];
	ord[1] = 1, ord[2] = 2, ord[3] = 3;
	sort(ord + 1, ord + 1 + 3, [](int x, int y){return a[x] < a[y];});
	printf("%lld\n", a[ord[3]] - a[ord[2]]);
	fflush(stdout);
	scanf("%d", &x);
	return 0;
}