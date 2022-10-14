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
		int n;
		cin >> n;
		int q;
		cin >> q;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<int, int> first, lasts;
		for (int i = 0; i < n; i++) {
			if(first.find(a[i]) == first.end())
				first[a[i]] = i;
			lasts[a[i]] = i;
		}
		while(q--) {
			int x, y;
			cin >> x >> y;
			if(first.find(x) != first.end() && first[x] < lasts[y]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}