#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

int t, n, a[2005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		ll res = 0;
		rep(i, 1, n)
			rep(j, i + 1, n)
				res += (__gcd(a[i], a[j]) > 1 || (a[i] % 2 == 0) || (a[j] % 2 == 0));
		cout << res << "\n";
	}
		
	return 0;
}