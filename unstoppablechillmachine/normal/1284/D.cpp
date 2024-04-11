#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 1e5 + 10;
int a[N], b[N], c[N], d[N];
vector<pair<int, int>> add[4 * N];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> srt;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		srt.pb(a[i]);
		srt.pb(b[i]);
		srt.pb(c[i]);
		srt.pb(d[i]);
	}
	sort(all(srt));
	srt.resize(unique(all(srt)) - srt.begin());
	unordered_map<int, int> vl;
	for (int i = 0; i < SZ(srt); i++) {
		vl[srt[i]] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		a[i] = vl[a[i]];
		b[i] = vl[b[i]];
		c[i] = vl[c[i]];
		d[i] = vl[d[i]];
	}
	for (int iter = 0; iter < 2; iter++) {
		vector<pair<int, int>> kek;
		for (int i = 0; i < n; i++) {
			kek.pb({a[i], i});
			add[b[i]].pb({c[i], d[i]});
		}
		sort(all(kek));
		int ptr = 0;
		set<int> unused, used;
		for (int i = 1; i <= SZ(srt); i++) {
			unused.insert(i);
		}
		for (int i = 0; i < n; i++) {
			while (ptr + 1 < kek[i].F) {
				ptr++;
				for (auto seg : add[ptr]) {
					for (;;) {
						auto it = unused.lower_bound(seg.F);
						if (it == unused.end() || *it > seg.S) {
							break;
						}
						used.insert(*it);
						unused.erase(it);
					}
				}
			}
			auto it = used.lower_bound(c[kek[i].S]);
			if (it != used.end() && *it <= d[kek[i].S]) {
				cout << "NO\n";
				exit(0);
			}
		}
		for (int i = 1; i <= SZ(srt); i++) {
			add[i] = {};
		}
		for (int i = 0; i  <n; i++) {
			swap(a[i], c[i]);
			swap(b[i], d[i]);
		}
	}
	cout << "YES\n";
}