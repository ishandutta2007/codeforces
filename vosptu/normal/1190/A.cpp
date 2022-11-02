#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
long long p[100010];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		p[i]--;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int offset = i - 1;
		long long curpage = (p[i] - offset) / k;
		while (i < m && (p[i + 1] - offset) / k == curpage)
			i++;
		ans++;
	}
	printf("%d\n", ans);
}