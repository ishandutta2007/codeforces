#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 300005;

int t, n, m, p[N], a[N], cnt[N], vis[N];

int solve(int k) {
	for (int i = 0; i < n; i++)
		p[(i + k) % n] = a[i], vis[i] = 0;
	int cyc = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i]) {
			cyc++;
			int u = i;
			while (!vis[u]) {
				vis[u] = 1;
				u = p[u];
			}
		}
	return n - cyc <= m;
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
			a[p[i]] = i;
		}

		fill(cnt, cnt + n, 0);
		for (int i = 0; i < n; i++) {
			int k = a[i] - i;
			if (k < 0) k += n;
			cnt[k]++;
		}

		vector<int> res;
		for (int i = 0; i < n; i++)
			if (cnt[i] >= n / 3 && solve(i))
				res.push_back(i);

		cout << res.size() << " ";
		for (auto x : res)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}