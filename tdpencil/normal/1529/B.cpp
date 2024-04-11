#include <bits/stdc++.h>
const int INF = 1000000000;
using namespace std;

using ll = long long;
#define vt vector
#define all(x) x.begin(),x.end()
#define ull unsigned ll
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

const int MAXN = 2e5+1;
int a[MAXN];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);	
	int t; cin >> t;
	while(t--) {
		cin >> n;
		for(int i =0 ; i < n; ++i)
			cin >> a[i];
		sort(a, a+n);
		vi b;
		b.pb(a[0]);
		int mx=2e9;
		for(int i =1; i < n; ++i) {
			if(a[i] > mx || abs(a[i] - b.back()) < a[i]) {
				break;
			} else {
				mx = min(mx, abs(a[i] - b.back()));
				b.pb(a[i]);
			}
		}
		cout << b.size() << "\n";

	}
}