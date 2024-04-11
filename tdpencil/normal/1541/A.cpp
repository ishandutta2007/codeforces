#include <bits/stdc++.h>
const int INF = 1000000000;
using namespace std;

using ll = long long;
#define vt vector
#define all(x) x.begin(),x.end()
#define ull unsigned ll
#define sz(x) (int(x.size()))
#define vi vector<int>
#define pb push_back
#define vl vector<ll>
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vpi vt<pi>
#define vpl vt<pl>
#define vvi vt<vi>
#define vvvi vt<vvi>
#define ar array

int n, k;
vvi min_dist(vi &a) {
	int cost =0;
	int mx=2e9;
	vvi rr;
	do {
		ll res =0 ;
		for(int j = 0; j < int(a.size()); j++)
			if(a[j] == j + 1)
				res = 2e9;
		for(int j = 0; j < int(a.size()); j++) {
			res += abs(a[j] - (j + 1));
		}	
		if(res>=int(a.size())&&res<mx)
			mx=res;
	} while(next_permutation(all(a)));
	do {
		ll res =0 ;
		for(int j = 0; j < int(a.size()); j++)
			if(a[j] == j + 1)
				res = 2e9;
		for(int j = 0; j < int(a.size()); j++) {
			res += abs(a[j] - (j + 1));
		}	
		if(res>=int(a.size())&&res==mx)
			mx=res, rr.pb(a);
	} while(next_permutation(all(a)));
	return rr;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);	
	int t; cin >> t;
	while(t--) {
		cin >> n;
		vi a(n);
		iota(all(a), 1);
		if(n%2) {
			for(int i = 0; i + 3 < n; i += 2) {
				cout << a[i + 1] << " " << a[i] << " ";;
			}	
			cout << a[n - 1] << " " << a[n - 3] << " " << a[n - 2] << "\n";
		} else {
			for(int i = 0; i + 1 < n; i += 2)
				cout << a[i + 1] << " " << a[i] << " ";
			cout << "\n";
		}
		cout << "\n";
	}


}