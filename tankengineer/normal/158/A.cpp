#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k, a[105];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	while (k < n && a[k + 1] == a[k]) ++k;
	while (k && a[k] <= 0) --k;
	printf("%d\n", k);
	return 0;
}