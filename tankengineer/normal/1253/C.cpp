#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n, m, a[N];

long long sum[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		sum[i % m] += a[i];
		ans += sum[i % m];
		printf("%I64d%c", ans, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}