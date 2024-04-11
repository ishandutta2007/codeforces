#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

ll fun(int x, int k) {
	int a = x / (k + 1), b = x % (k + 1);
	return 1ll * a * a * (k + 1) + 2ll * a * b + b;
}

std::priority_queue<std::pair<ll, int> >que;

int a[N + 5], b[N + 5], n, k;

void insert(int x) {
	if( b[x] == a[x] - 1 ) return ;
	que.push(std::make_pair(fun(a[x], b[x]) - fun(a[x], b[x] + 1), x));
}

int main() {
	scanf("%d%d", &n, &k); ll ans = 0;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), ans += fun(a[i], 0), insert(i);
	for(int i=1;i<=k-n;i++) {
		std::pair<ll, int>p = que.top(); que.pop();
		ans -= p.first, b[p.second]++, insert(p.second);
	}
	printf("%lld\n", ans);
}