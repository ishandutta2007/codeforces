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
ll a[mnN];
void solve() {
	int n; cin >> n;
	int k; cin >> k;
	for(int i=0; i < n; i++)
		cin >> a[i];

	ll mn = 0;
	for(int i = (1<<30); i >= 1; i >>= 1) {
		if((mn+i)*(mn+i+1) / 2 < k) {
			mn += i;
		}
	}
	int res = k - (mn)*(mn+1)/2;

	cout << a[res-1] << "\n";
	
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)
		solve();
}