#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		sum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		b[i] = sum / n;
	}
	for (int i = 0; i < sum % n; ++i) {
		++b[n - i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < b[i]) {
			ans += b[i] - a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}