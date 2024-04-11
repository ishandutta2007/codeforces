#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int k, n = 12, a[12];
	scanf("%d", &k);
	if (k == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	reverse(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum >= k) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
 	return 0;
}