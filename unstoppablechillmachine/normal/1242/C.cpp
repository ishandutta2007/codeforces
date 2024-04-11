#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

unordered_map<int, int> have;
const int N = 1 << 15;
const int M = 16;
bool can[N];
vector<pair<int, int>> swaps[N];
int used[M], sum[M], from[N];
vector<int> arr[M];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return have[a.F] < have[b.F];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int all = 0;
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		arr[i].resize(cnt);
		for (auto &it : arr[i]) {
			cin >> it;
			have[it] = i;
			sum[i] += it;
		}
		all += sum[i];
	}
	if (abs(all) % n != 0) {
		cout << "No\n";
		exit(0);
	}
	int kek = all / n, timer = 0;
	for (int i = 1; i <= n; i++) {
		for (auto x : arr[i]) {
			timer++;
			int need = kek - (sum[i] - x);
			bool ok = false;
			vector<pair<int, int>> flex;
			int prv = i, mask = 1 << (i - 1);
			used[i] = timer;
			for (;;) {
				if (have.find(need) == have.end()) {
					break;
				}
				int id = have[need];
				if (id == i) {
					if (need == x) {
						flex.pb({x, prv});
						ok = true;
						break;
					}
				}
				if (used[id] == timer) {
					break;
				}
				mask |= 1 << (id - 1);
				used[id] = timer;
				flex.pb({need, prv});
				prv = id;
				need = kek - (sum[id] - need);
			}
			if (ok) {
				can[mask] = true;
				swaps[mask] = flex;
			}
		}
	}
	can[0] = true;
	for (int i = 1; i < (1 << n); i++) {
		if (can[i]) {
			continue;
		}
		for (int j = i; j > 0; j = (j - 1) & i) {
			if (can[j] && can[i ^ j]) {
				can[i] = true;
				from[i] = j;
				break;
			}
		}
	}
	if (!can[(1 << n) - 1]) {
		cout << "No\n";
		exit(0);
	}
	int now = (1 << n) - 1;
	vector<pair<int, int>> ans;
	while (now) {
		int msk = now ^ from[now];
		assert(can[msk]);
		for (auto it : swaps[msk]) {
			ans.pb(it);
		}
		now = from[now];
	}
	sort(all(ans), cmp);
	cout << "Yes\n";
	for (auto it : ans) {
		cout << it.F << ' ' << it.S << '\n';
	}
}