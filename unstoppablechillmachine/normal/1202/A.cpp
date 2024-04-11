#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
const int INF = 1e9 + 10;
 
signed main() {
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int c1 = 0, c2 = 0;
		while (s2.back() != '1') {
			s2.pop_back();
			c2++;
		}
		int mn = INF;
		reverse(all(s1));
		for (int i = c2; i < SZ(s1); i++) {
			if (s1[i] == '1') {
				mn = i;
				break;
			}
		}
		if (mn == INF) {
			cout << 0 << '\n';
		}
		else {
			cout << mn - c2 << '\n';
		}
	}
}