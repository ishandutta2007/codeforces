#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
const int mxN = 2e5+5;
const int mnN = 1e5+5;
const int grn = 105;
const int grN = 505;
const int griN = 1005;
const int mxGriN= 5005;
const int mxDP = 7005;

int ar[mxN];
ll dp3[grn][grn][grn];
ll dp2[griN][griN];
ll dp1[mnN];
int n, m;
int a[mxN];
int gr[griN][2];

void solve() {
	cin >> n;
	int k1, k2; cin >> k1 >> k2;
	
	int w, b;
	cin >> w >> b;
	
	int left = k1+k2;
	left /= 2;
	int res = 2*n-(k1+k2);
	res /= 2;
	if(w > left || b > res) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}