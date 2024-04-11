#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
//#define F first
#define S second

const int N = 2010;
int a[N], used[N];

signed main() {
	int n;
	cin >> n;
	vector<int> a(n),srt;
	for (auto &it : a) {
		cin >> it;
		srt.pb(it);
	}
	sort(all(srt));
	srt.resize(unique(all(srt)) - srt.begin());
	unordered_map<int, int> to;
	for (int i = 0; i < SZ(srt); i++) {
		to[srt[i]] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		a[i] = to[a[i]];
	}
	int ans = 0, timer = 0;
	for (int pref = 0; pref <= n; pref++) {
		timer++;
		bool ok = true;
		int sum = pref;
		for (int i = 0; i < pref; i++) {
			if (used[a[i]] == timer) {
				ok = false;
				break;
			}
			used[a[i]] = timer;
		}
		if (!ok) {
			break;
		}
		int ptr = n - 1;
		while (ptr >= pref && used[a[ptr]] < timer) {
			used[a[ptr]] = timer;
			ptr--;
			sum++;
		}
		ans = max(ans, sum);
	}
	cout << n - ans << '\n';
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}