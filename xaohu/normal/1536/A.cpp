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

int t, n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int neg = 0;
		while (n--) {
			int x;
			cin >> x;
			neg |= (x < 0);
		}
		if (neg)
			cout << "NO\n";
		else {
			cout << "YES\n";
			cout << 101 << "\n";
			rep(i, 0, 100)
				cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}