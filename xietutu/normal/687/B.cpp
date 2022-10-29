#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000010;
int n, c[maxn];
LL cur, K; 
LL lcm(LL x, LL y) {
	return x * y / __gcd(x, y);
}
int main() {
	scanf("%d%I64d", &n, &K);
	cur = 1;
	for (int i = 1; i <= n; ++i) { 
		scanf("%d", c + i);
		cur = __gcd(K, lcm(cur, c[i]));
	}
	if (cur == K) puts("Yes");
	else puts("No"); 
}