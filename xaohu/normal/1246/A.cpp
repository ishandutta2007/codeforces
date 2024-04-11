#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

ll n, p;

int main() {
	cin >> n >> p;
	rep(i, 1, 1024) {
		ll x = n - i * p;
		if (x > 0 && i <= x && __builtin_popcountll(x) <= i) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}