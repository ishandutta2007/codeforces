#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
int a[mxn];
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);


	int t; cin >> t;
	while(t--) {
		solve();
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	bool works = false;
	for(int i=0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		
		if(b == c) works = true;
	}
	if(m & 1) {
		cout << "NO\n";
		return;
	}



	cout << (works ? "YES\n" : "NO\n");
}