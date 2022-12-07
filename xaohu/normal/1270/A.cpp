#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int T, n, k1, k2;

int input(int x) {
	int mx = 0;
	while (x--) {
		int a;
		cin >> a;
		mx = max(mx, a);
	}
	return mx;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while (T--) {
		cin >> n >> k1 >> k2;
		cout << (input(k1) > input(k2) ? "YES\n" : "NO\n");
	}
	return 0;
}