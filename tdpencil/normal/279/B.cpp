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

int l, r, ans;

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i],c[i+1]=c[i]+a[i];
	
	l = 0, r = 0;
	while(l < n && r < n) {
		if(c[r + 1] - c[l] > k) {
			++l;	
		} else {
			++r;
		}
		ans = max(r - l, ans);
	}

	cout << ans << "\n";
}