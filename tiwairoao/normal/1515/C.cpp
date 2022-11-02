#include <bits/stdc++.h>

const int N = 100000;

typedef std::pair<int, int> pii;


int n, m, x;
void solve() {
	scanf("%d%d%d", &n, &m, &x);

	puts("YES");
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> >que;
	for (int i = 1, h; i <= m; i++) {
		scanf("%d", &h);
		printf("%d ", i);
		que.push(std::make_pair(h, i));
	}
	for (int i = m + 1, h; i <= n; i++) {
		scanf("%d", &h); pii p = que.top(); que.pop();
		printf("%d ", p.second);
		que.push(std::make_pair(h + p.first, p.second));
	}
	puts("");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}