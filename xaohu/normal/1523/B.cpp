#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

int n;

void solve() {
	cin >> n;
	rep(i, 1, n) {
		int x;
		cin >> x;
	}
	cout << 3 * n << "\n";
	rep(i, 0, n / 2 - 1) {
		int a = 2 * i + 1;
		int b = 2 * i + 2;
		rep(j, 0, 2) {
			cout << 2 << " " << a << " " << b << "\n";
			cout << 1 << " " << a << " " << b << "\n";
		}
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}