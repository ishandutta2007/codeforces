#include <bits/stdc++.h>
using namespace std;

typedef long long ull;
typedef vector<int> vi;
typedef vector<ull> vl;

#define ar array
#define ll ull
#define vt vector
#define ii pair<int, int>
#define vpii vt<ii>
#define pll pair<ll, ll>
#define vpll vt<pll>
#define pr pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while(t-- ){
		int n; cin >> n;
		vi a(n);
		for(auto &i : a) {
			cin >> i;
		}
		
		int MX = 1e9+7;
		vt<ar<int, 4>> query;
		for(int i = 0; i + 1 < n; i += 2) {
			query.pb({i + 1, i + 2, min(a[i], a[i+1]), MX});
		}
		cout << query.size() << "\n";
		for(auto &qu : query) {
			cout << qu[0] << " " << qu[1] << " " << qu[2] << " " << qu[3] << "\n";
		}
	}
}