#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n;

bool sq(int x) {
	int y = sqrt(x);
	return y * y == x;
}

void solve() {
	cin >> n;
	if ((n % 2 == 0 && sq(n / 2)) || (n % 4 == 0 && sq(n / 4))) {
			cout << "YES\n";
		}
	else {
		cout << "NO\n";
	}
}

int main() {
	cin >> t;
	while (t--) 
		solve();
	
	return 0;
}