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
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> s;
		map<pair<int, int>, int> m;
		int a = 0, b = 0;
		rep(i, 0, n - 1) {
			if (s[i] == 'D') a++;
			else b++;
			int c = a, d = b;
			int g = __gcd(c, d);
			c /= g;
			d /= g;
			cout << ++m[{c, d}] << " ";
		}
		cout << "\n";
	}
	return 0;
}