#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ar array
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector
#define lb lower_bound
#define ub upper_bound
#define pb push_back

void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
int n, m;
const int mxN = 2e5 + 1;
int a[mxN], b[mxN], cnt[mxN];


void solve() 
{
	ll x, y; cin >> x >> y;
	if(x > y) swap(x, y);
	ll d; cin >> d;

	ll amountToSub = (1 + d) * x;
	y -= amountToSub;
	

	cout << (y <= 0 ? "YES" : "NO") << "\n";
} 

int main() {
	io();
	int t = 1;
	cin >> t;
	while(t--) solve();
}