#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
#define pb push_back
#define vt vector
#define rs resize
#define all(x) x.begin(),x.end()
#define sum(x) accumulate(all(x), 0LL)
const int MAXN = 2e5;

void solve() {
	int n; cin >> n;
	int s =0 ;
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		s += x;
	}
	if(s<n) {
		cout << 1 << "\n";
	} else {
		cout << -(n - s) << "\n";
	}
}

int main() {
	int t; cin >> t;

	while(t--) {
		solve();
	}
}