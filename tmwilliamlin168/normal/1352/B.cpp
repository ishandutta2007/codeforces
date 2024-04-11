#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n, k;
	cin >> n >> k;
	if(n&1&&k&1^1) {
		cout << "NO\n";
		return;
	}
	if(n&1^1&&k&1) {
		if(n<2*k) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for(int i=1; i<k; ++i)
			cout << "2 ";
		cout << n-2*(k-1) << "\n";
	} else {
		if(n<k) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for(int i=1; i<k; ++i)
			cout << "1 ";
		cout << n-(k-1) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}