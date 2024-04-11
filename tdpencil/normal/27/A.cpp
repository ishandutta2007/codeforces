#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ar array
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector
#define lb lower_bound
#define ub upper_bound
int n, m,a, b;
void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}

void solve() {
	int n; cin >> n;
	vt<int> a(n);
	for(auto &i : a)
		cin >> i;
	sort(all(a));
	for(int i = 1; i <= 3001; i++) {
		if(!binary_search(a.begin(), a.end(), i)) {
			cout << i << "\n";
			return;
		}
	}

	assert(false);
}

int main() {
	io();
	int t = 1;
	//cin >> t;
	while(t--) solve();
}