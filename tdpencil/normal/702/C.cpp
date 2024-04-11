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
const int MAXN = 1e5;
ll a[MAXN], c[MAXN], d[MAXN], ch[MAXN];


bool check(ll r) {
	// check for last d[i] which doesn't support it
	bool works = 1;
	for(int i = 0; i < n; ++i) {
		ll l=lower_bound(d, d + k, a[i]) - d;
		ll u=lower_bound(d, d + k, a[i] - r) - d;
		bool res = 0;
		res |= (l < k && d[l] <= a[i] + r);
		res |= (u < k && d[u] <= a[i]);
		works &= res;
	}
	return works;
}
int main() {
	cin >> n >> k;
	for(int i =0 ; i < n; ++i)
		cin >> a[i];
	for(int i =0; i < k; ++i)
		cin >> d[i];
	ll l = 0, r = 2e9;

	while(l < r) {
		ll mid = l + (r - l) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}

	cout << l;
}