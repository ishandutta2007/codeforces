#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define sz(x) (int(x.size()))
#define all(x) begin(x),end(x)
#define rep(i,j,k) for(int i=j; i<k; i++)
#define vi vector<int>
#define pii pair<int, int>



void solve() {
	ll a, b;
	cin >> a >> b;
	if(3*a<=b) {
		cout << a << "\n"; return;
	} else if(3*b<=a) {
		cout << b << "\n";
		return;
	}
	// now max(a,b)*3>>=a meaning that they must fall within each others range
	// now just set these two equations equal = max(a,b)-3x = min(a,b)-x -> 2x = max(a,b) - min(a,b) x = 
	int x = max(a,b);
	int y = min(a,b);
	int ans=0;
	int spins = (x-y)/2;
	x -= 3 * spins;
	y -= spins;
	cout << min(x,y) / 2 + spins << "\n";
	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--)
		solve();
}