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


int n, m;
ll a;
void solve() {
	int c[2];
	cin >> n >> c[0] >> c[1] >> m;
	
	for(int i=0;i<n;i++) {
		char x; cin >> x;
		if(x=='0') {
			a += min(c[0], c[1] + m);
		} else {
			a += min(c[1], c[0] + m);
		}
	}
	cout << a << '\n';
	a=0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}