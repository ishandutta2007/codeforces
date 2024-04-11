
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
set<ll> nums1, nums2;
void solve() {
	int n, k;
	cin >> n >> k;

	if(k == 1) {
		cout << (*nums1.lower_bound(n));
	} else {
		cout << (*nums2.lower_bound(n));
	}
	cout << "\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	for(int i=0;i<10;i++) {
		for(int j=i;j<10;j++) {
			if(i==j&&i!=0) {
				ll k = j;
				for(;k<1e10;k*=10,k+=j) nums1.insert(k), nums2.insert(k);
			} else {
				for(int len=1;len<=10;len++) {
					for(int mask=0; mask < (1<<len); mask++) {
						ll num=0;
						for(ll k = 0, l = 1; k < len; k++, l *= 10) {
							if(mask&(1<<k))
								num += i * l;
							else
								num += j * l;
						}
						nums2.insert(num);
					}
				}
			}
		}
	}
	while(t--) {
		solve();
	}
}