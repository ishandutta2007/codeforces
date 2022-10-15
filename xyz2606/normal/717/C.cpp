#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; ++ i) (ans += 1LL * a[i] * a[n - i - 1] % 10007) %= 10007;
	printf("%d\n", ans);
}