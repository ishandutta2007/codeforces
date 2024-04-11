#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n, m;
ll c[mxN][mxN], c1[mxN], c2[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> c[i][j];
			c1[i]+=c[i][j];
			c2[j]+=c[i][j];
		}
	}
	ar<ll, 2> a1={(ll)1e18}, a2={(ll)1e18};
	for(int i=0; i<=n; ++i) {
		ll ca=0;
		int i2=4*i;
		for(int j=0; j<n; ++j) {
			int j2=4*j+2;
			ca+=c1[j]*(j2-i2)*(j2-i2);
		}
		a1=min(ar<ll, 2>{ca, i}, a1);
	}
	for(int i=0; i<=m; ++i) {
		ll ca=0;
		int i2=4*i;
		for(int j=0; j<m; ++j) {
			int j2=4*j+2;
			ca+=c2[j]*(j2-i2)*(j2-i2);
		}
		a2=min(ar<ll, 2>{ca, i}, a2);
	}
	cout << a1[0]+a2[0] << "\n";
	cout << a1[1] << " " << a2[1];
}