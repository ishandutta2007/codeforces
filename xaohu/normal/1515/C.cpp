#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int n, m, x;

void solve() {
	cin >> n >> m >> x;
	set<pair<int, int>> T;
	rep(i, 1, m)
		T.insert({0, i});
	cout << "YES\n";
	rep(i, 1, n) {
		int z;
		cin >> z;
		auto [a, b] = *T.begin();
		T.erase(T.begin());
		cout << b << " ";
		T.insert({a + z, b});
	}	
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) 
		solve();
	
	return 0;
}