#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define ar array

const int mxN = 3e5 + 5;


random_device rd;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

int a[mxN];
vector<int> p[mxN];
void solve() {
	int n, q;
	cin >> n >> q;
	
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		p[a[i]].push_back(i);
	}
	
	while(q--) {
		int l, r; cin >> l >> r;
		--l, --r;
		uniform_int_distribution<> randGen(l, r);
		vector<int> toTake;
		for(int i = 0; i < 50; i++) {
			toTake.push_back(a[randGen(gen)]);
		}
		int x = (r - l + 1);
		int ans = 1;
		for(int i = 0; i < 50; i++) {
			int dist1 = lower_bound(p[toTake[i]].begin(), p[toTake[i]].end(), l) - p[toTake[i]].begin();
			int dist2 = upper_bound(p[toTake[i]].begin(), p[toTake[i]].end(), r) - p[toTake[i]].begin();
			
			int found = dist2 - dist1;
			if(found > (x+1) / 2) {
				int res = 2*(x-found) + 1;
				// max you can take
				ans = max(ans, (x-res) + 1);
			}
		}
		
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}