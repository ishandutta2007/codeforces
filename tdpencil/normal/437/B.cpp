#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ar array
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector
#define lb lower_bound
#define ub upper_bound
#define pb push_back

void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
int n, m;
const int mxN = 2e5 + 1;
int a[mxN], cnt[mxN];
void solve() {
	cin >> n >> m;
	vector<int> cur;
	for(int i = m; i >= 1; i--) {

		int lpf = i & -i;
		if(n >= lpf) {
			n -= lpf;
			cur.push_back(i);
		}
	}
	if(n > 0) {
		cout << -1 << "\n";
	} else {
		cout << cur.size() << "\n";
		for(int i : cur) {
			cout << i << " ";
		}
	}
	
} 

int main() {
	io();
	int t = 1;
	// cin >> t;
	while(t--) solve();
}