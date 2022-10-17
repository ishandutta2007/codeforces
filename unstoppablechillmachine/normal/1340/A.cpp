#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		multiset<int> st;
		vector<int> cnt(n + 1, 1);
		for (int i = 1; i <= n; i++) {
			st.insert(1);
		}
		vector<int> pos(n + 1);
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			pos[x] = i;
		}
		bool ok = true;
		set<int> unused;
		for (int i = 1; i <= n; i++) {
			unused.insert(i);
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[pos[i]] != *st.rbegin()) {
				ok = false;
				break;
			}
			auto it = unused.upper_bound(pos[i]);
			st.erase(st.find(cnt[pos[i]]));
			st.insert(0);
			if (it != unused.end()) {
				int kek = *it;
				st.erase(st.find(cnt[kek]));
				cnt[kek] += cnt[pos[i]];
				st.insert(cnt[kek]);
			}
			cnt[pos[i]] = 0;
			unused.erase(pos[i]);
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}  
}