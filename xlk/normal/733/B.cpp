#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int ans, n;
int a[100020];
int b[100020];
int sa, sb;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		sa += a[i];
		sb += b[i];
	}
	ans = abs(sa - sb);
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (ans < abs(sa - a[i] + b[i] - (sb - b[i] + a[i]))) {
			ans = abs(sa - a[i] + b[i] - (sb - b[i] + a[i]));
			index = i;
		}
	}
	printf("%d\n", index + 1);
	return 0;
}