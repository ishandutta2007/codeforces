#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
const int B = 3 * sqrt(1e5);
ll add1[N], add2[N], sum[N];
bool kek[N / B + 10][N];
vector<int> have[N], inter[N];

signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;
		have[i].resize(cnt);
		for (auto &it : have[i]) {
			cin >> it;
		}
		sort(all(have[i]));
	}
	vector<int> big;
	for (int i = 0; i < m; i++) {
		if (SZ(have[i]) > B) {
			big.pb(i);
			int cur = SZ(big) - 1;
			inter[i].resize(m);
			for (int x : have[i]) {
				kek[cur][x] = true;
			}
			for (int j = 0; j < m; j++) {
				if (SZ(have[j]) > B) {
					int ptr = 0;
					for (int k = 0; k < SZ(have[i]); k++) {
						while (ptr < SZ(have[j]) && have[j][ptr] < have[i][k]) {
							ptr++;
						}
						if (have[j][ptr] == have[i][k]) {
							inter[i][j]++;
						}
					}
				}
				else {
					for (auto it : have[j]) {
						if (kek[cur][it]) {
							inter[i][j]++;
						}
					}
				}
			}
		}
		for (auto x : have[i]) {
			sum[i] += a[x];
		}
	}
	for (int i = 0; i < q; i++) {
		char c;
		cin >> c;
		if (c == '?') {
			int id;
			cin >> id;
			id--;
			if (SZ(have[id]) > B) {
				cout << sum[id] << '\n';
			}
			else {
				ll ans = sum[id];
				for (int i = 0; i < SZ(have[id]); i++) {
					ans += add1[have[id][i]];
				}
				for (int num : big) {
					ans += add2[num] * inter[num][id];
				}
				cout << ans << '\n';
			}
		}
		else {
			int id, vl;
			cin >> id >> vl;
			id--;
			for (int num : big) {
				sum[num] += vl * 1ll * inter[num][id];
			}
			if (SZ(have[id]) > B) {
				add2[id] += vl;
			}
			else {
				for (auto x : have[id]) {
					add1[x] += vl;
				}
			}
		}
	}
}