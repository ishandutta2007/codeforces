#include <iostream>
#include <cstdio>
using namespace std;
int n, a[10000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	int s = 0, ans = 0;
	for (int i = 0; i < 10000; i++) {
		s += a[i];
		s--;
		if (s < 0) {
			s = 0;
		}
		ans += s;
	}
	printf("%d\n", ans);
	return 0;
}