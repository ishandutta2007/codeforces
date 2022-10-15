#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2000, mxM=200, M=1e9+696969, B=69;
int n, m;
string g1[mxN], g2[mxM];
ll h1[mxN], h2[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> g1[i];
	for(int i=0; i<m; ++i)
		cin >> g2[i];
	for(int i1=0; i1<=n-m; ++i1) {
		ll b=1;
		for(int i=0; i<m; ++i)
			for(int j=0; j<m; ++j, b=b*B%M)
				h1[i1]+=b*g1[i1+i][j];
		b=1;
		for(int i=0; i<m; ++i)
			for(int j=0; j<m; ++j, b=b*B%M)
				h2[i1]+=b*g2[i][i1+j];
	}
	for(int i=0; i<=n-m; ++i) {
		h1[i]%=M;
		h2[i]%=M;
	}
	for(int i=0; i<=n-m; ++i) {
		for(int j=0; j<=n-m; ++j) {
			if(h1[i]==h2[j]) {
				cout << i+1 << " " << j+1;
				return 0;
			}
		}
	}
}