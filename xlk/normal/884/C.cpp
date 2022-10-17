#include <bits/stdc++.h>
using namespace std;
int n, a[100001];
int b[100001], c;
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int s = i, l = 0;
		while (a[s] > 0) {
			int t = a[s];
			a[s] = 0;
			s = t;
			l++;
		}
		b[i] = l;
		ans += (long long)l * l;
	}
	sort(b + 1, b + 1 + n);
	ans += 2LL * b[n - 1] * b[n];
	printf("%lld\n", ans);
}