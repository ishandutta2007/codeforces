#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, T, a, b;
ar<int, 2> c[mxN];

int rc(int x) {
	return x?b:a;
}

void solve() {
	cin >> n >> T >> a >> b;
	ll ts=0;
	int al[2]={};
	for(int i=0; i<n; ++i) {
		cin >> c[i][1];
		ts+=rc(c[i][1]);
		++al[c[i][1]];
	}
	for(int i=0; i<n; ++i)
		cin >> c[i][0];
	sort(c, c+n);
	int ans=0;
	ll sf=0;
	for(int i=0; i<n; ++i) {
		if(!i||c[i-1][0]^c[i][0]) {
			if(sf<c[i][0]) {
				int ca=i;
				int lt=c[i][0]-1-sf;
				int tk=min(lt/a, al[0]);
				lt-=tk*a;
				ca+=tk;
				tk=min(lt/b, al[1]);
				ca+=tk;
				ans=max(ca, ans);
			}
		}
		sf+=rc(c[i][1]);
		//if(sf>c[i][0])
			//break;
		--al[c[i][1]];
	}
	cout << (ts<=T?n:ans) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}