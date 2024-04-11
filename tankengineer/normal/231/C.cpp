#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

const int N = 100005;
int a[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int l = 0, ans = 1, anst = a[0];
	long long cost = 0;
	for (int r = 1; r < n; ++r) {
		cost += (long long)(r - l) * (a[r] - a[r - 1]);
		while (cost > k) {
			cost -= a[r] - a[l];
			++l;
		}
		if (r - l + 1 > ans) {
			ans = r - l + 1, anst = a[r];
		}
	}
	printf("%d %d\n", ans, anst);
	return 0;
}