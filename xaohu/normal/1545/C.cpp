#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1005;

int T, n, cnt[N][N], a[N][N], e[N][N], vis[N];
vector<int> res;

void dfs(int u, int p) {
	vis[u] = 1;
	if (p == 0)
		res.push_back(u);
	rep(i, 0, 2 * n)
		if (!vis[i] && e[u][i])
			dfs(i, p ^ 1);
}

void solve() {
	rep(i, 0, N) {
		vis[i] = 0;
		rep(j, 0, N)
			cnt[i][j] = a[i][j] = e[i][j] = 0;
	}
	res.clear();

	cin >> n;
	rep(i, 0, 2 * n) {
		rep(j, 0, n) {
			cin >> a[i][j];
			cnt[j][a[i][j]]++;
		}
		rep(k, 0, i)
			rep(j, 0, n)
				if (a[i][j] == a[k][j]) {
					e[i][k] = e[k][i] = 1;
				}
	}

	while (1) {
		int id = -1;
		rep(i, 0, 2 * n)
			if (!vis[i])
				rep(j, 0, n)
					if (cnt[j][a[i][j]] == 1)
						id = i;
		if (id == -1)
			break;

		auto upd = [&](int x) {
			vis[x] = 1;
			rep(i, 0, n)
				cnt[i][a[x][i]]--;
		};

		res.push_back(id);
		upd(id);
		rep(i, 0, 2 * n)
			if (!vis[i] && e[id][i])
				upd(i);
	}

	int ans = 1;
	rep(i, 0, 2 * n)
		if (!vis[i]) {
			dfs(i, 0);
			ans = 2 * ans % 998244353;
		}

	cout << ans << "\n";
	for (auto x : res)
		cout << x + 1 << " ";
	cout << "\n";
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--)
		solve();
	return 0;
}