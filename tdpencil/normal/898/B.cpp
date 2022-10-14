
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int n, a, b;
void solve() {

	cin >> n >> a >> b;
	for(int i = 0; i <= n; ++i) {
		ll res = n - (ll)a*i;
		if(res<0 || res%b) continue;
		int times=res/b;
		cout << "YES\n";
		cout << i << " " << times << "\n";
		return;
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	//cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}