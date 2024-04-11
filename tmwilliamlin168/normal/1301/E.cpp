#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500;
int n, m, q, c[256], a[254][mxN+1][mxN+1];
string g[mxN];

int ps(int k, int l1, int r1, int l2, int r2) {
	return a[k][l2+1][r2+1]-a[k][l2+1][r1]-a[k][l1][r2+1]+a[k][l1][r1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	c['R']=0, c['G']=1, c['Y']=2, c['B']=3;
	cin >> n >> m >> q;
	for(int i=0; i<n; ++i) {
		cin >> g[i];
		for(int j=0; j<m; ++j)
			++a[c[g[i][j]]][i+1][j+1];
	}
	for(int k=0; k<4; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j)
				a[k][i][j]+=a[k][i][j-1];
			for(int j=1; j<=m; ++j)
				a[k][i][j]+=a[k][i-1][j];
		}
	}
	for(int i=0; i+1<n; ++i) {
		for(int j=0; j+1<m; ++j) {
			if(g[i][j]^'R'||g[i][j+1]^'G'||g[i+1][j]^'Y'||g[i+1][j+1]^'B')
				continue;
			int x=1;
			while(i-x>=0&&i+x+1<n&&j-x>=0&&j+x+1<m&&ps(0, i-x, j-x, i, j)==(x+1)*(x+1)&&ps(1, i-x, j+1, i, j+x+1)==(x+1)*(x+1)&&ps(2, i+1, j-x, i+x+1, j)==(x+1)*(x+1)&&ps(3, i+1, j+1, i+x+1, j+x+1)==(x+1)*(x+1))
				++x;
			for(int k=1; k<=x; ++k)
				++a[3+k][i+1][j+1];
		}
	}
	for(int k=4; k<254; ++k) {
		for(int i=1; i<n; ++i) {
			for(int j=1; j<m; ++j)
				a[k][i][j]+=a[k][i][j-1];
			for(int j=1; j<m; ++j)
				a[k][i][j]+=a[k][i-1][j];
		}
	}
	while(q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2, --r1, --c1;
		int lb=0, rb=250;
		while(lb<rb) {
			int mb=(lb+rb+1)/2;
			if(r1+mb<=r2-mb&&c1+mb<=c2-mb&&ps(3+mb, r1+mb-1, c1+mb-1, r2-mb-1, c2-mb-1))
				lb=mb;
			else
				rb=mb-1;
		}
		cout << 4*lb*lb << "\n";
	}
}