#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector

int n, m;
void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
void solve() {
	cin >> n >> m;

	if(m > n) {
		cout << -1 << "\n";
		return;
	}
	int moves = 0;
	if(n % 2) {
		moves += n / 2 + 1;
	} else {
		moves += n / 2;
	}

	while(moves % m) {
		moves++;
	}
	cout << moves << "\n";
}

int main() {
	io();
	int t = 1;
	//cin >> t;
	while(t--) solve();
}