#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

ll sum[N + 5];
char s[N + 5]; int n, q;

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (s[i] - 'a' + 1);
	for (int i = 1, l, r; i <= q; i++)
		scanf("%d%d", &l, &r), printf("%lld\n", sum[r] - sum[l - 1]);
}