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
	ll n, s;
	cin >> n >> s;
	ll a[n], p[n];
	rep(i,0,n) cin >> a[i],p[i]=0;
	ll c=s;
	int l=0,r=0;
	ll ans=0;
	pii mx(0,-1);
	while(max(l,r)<n) {
		c += a[r];
		while(l<=r&&c<0) {
			c-=a[l++];
		}
		if((r-l+1)>mx.second-mx.first+1) {
			mx.first=l;
			mx.second=r;
		}
		r++;
	}
	if(mx.second - mx.first < 0) {
		cout << -1 << "\n"; return;
	}
	cout << mx.first + 1 << " " << mx.second + 1<< "\n";
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--)
		solve();
}