#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

#define left LEFT
#define right RIGHT
int n, a[N], left[N], right[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	left[0] = 1;
	for (int i = 1; i < n; ++i) {
		left[i] = min(left[i - 1] + 1, a[i]);
	}
	right[n - 1] = 1;
	for (int i = n - 1; i >= 0; --i) {
		right[i] = min(right[i + 1] + 1, a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, min(left[i], right[i]));
	}
	printf("%d\n", ans);
	return 0;
}