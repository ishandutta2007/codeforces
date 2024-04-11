#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int t=1;

const int mxN=2e5;
int a[mxN];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		set<char> c;
		int ans = 1;
		for(int i = 0; i < (int)s.size(); i++) {
			if(c.size() == 3 && c.find(s[i]) == c.end()) {
				ans++;
				c.clear();
				c.insert(s[i]);
			} else {
				c.insert(s[i]);
			}
		}
		cout << ans << "\n";
	}
}