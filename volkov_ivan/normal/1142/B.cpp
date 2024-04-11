#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 2e5 + 7;
int perm[MAX_N], p_prime[MAX_N], a[MAX_N], dpl[MAX_N], dpr[MAX_N], last[MAX_N], ans[MAX_N], pref[MAX_N];
vector <int> poses[MAX_N];

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	//freopen("Desktop/input.txt", "r", stdin);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> perm[i];
		p_prime[perm[i]] = i;
	}
	for (int i = 1; i <= m; i++) cin >> a[i];
	memset(last, 0, sizeof(last));
	dpl[0] = -1;
	for (int i = 1; i <= m; i++) {
		if (perm[1] == a[i]) dpl[i] = i;
		else dpl[i] = dpl[last[perm[p_prime[a[i]] - 1]]];
		last[a[i]] = i;
	}
	memset(last, 0, sizeof(last));
	dpr[0] = -1;
	for (int i = m; i >= 1; i--) {
		if (perm[n] == a[i]) dpr[i] = i;
		else dpr[i] = dpr[last[perm[p_prime[a[i]] + 1]]];
		last[a[i]] = i;
	}
	for (int i = m; i >= 1; i--) poses[a[i]].push_back(i);
	if (!poses[perm[1]].empty()) {
		for (int elem : poses[perm[1]]) {
			ans[elem] = dpr[elem];
		}
	}
	/*for (int i = 1; i <= m; i++) {
		cout << dpl[i] << ' ' << dpr[i] << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		if (i == perm[1]) continue;
		int l = -1;
		int prv = perm[p_prime[i] - 1];
		for (int j = 0; j < (int) poses[i].size(); j++) {
			if (dpr[poses[i][j]] == -1) {
				ans[poses[i][j]] = -1;
				continue;
			}
			while (l + 1 != (int) poses[prv].size() && dpl[poses[prv][l + 1]] > dpr[poses[i][j]]) l++;
			if (l == -1) ans[poses[i][j]] = -1;
			else ans[poses[i][j]] = poses[prv][l];//, cout << "!!! " << poses[i][j] << ' ' << poses[prv][l] << endl;
		}
	}
	pref[m + 1] = MAX_N;
	for (int i = m; i >= 1; i--) {
		pref[i] = pref[i + 1];
		if (ans[i] != -1) pref[i] = min(pref[i], ans[i]);
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (pref[l] <= r) cout << "1";
		else cout << "0";
	}
	return 0;
}