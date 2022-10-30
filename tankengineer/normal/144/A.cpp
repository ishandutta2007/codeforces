#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[105], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int mins = 1, maxs = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= a[mins]) mins = i;
		if (a[i] > a[maxs]) maxs = i;
	}
	printf("%d\n", n - mins + maxs - 1 - (mins < maxs));
	return 0;
}