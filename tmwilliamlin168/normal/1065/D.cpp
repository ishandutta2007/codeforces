#include <bits/stdc++.h>
using namespace std;

const int mxN=10;
int n, ai, p[mxN*mxN];
array<int, 2> d[mxN*mxN*3][mxN*mxN*3], dp[mxN*mxN][3];

array<int, 2> operator+(const array<int, 2> a, const array<int, 2> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n*n; ++i) {
		cin >> ai, --ai;
		p[ai]=i;
	}
	memset(d, 1, sizeof(d));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			for(int k=0; k<3; ++k)
				for(int l=0; l<3; ++l)
					d[(i*n+j)*3+k][(i*n+j)*3+l]={1, 1};
			for(int k=0; k<n; ++k) {
				for(int l=0; l<n; ++l) {
					if(i==k||j==l)
						d[(i*n+j)*3][(k*n+l)*3]={1, 0};
					else if(abs(i-k)+abs(j-l)==3)
						d[(i*n+j)*3+2][(k*n+l)*3+2]={1, 0};
					if(i+j==k+l||i-j==k-l)
						d[(i*n+j)*3+1][(k*n+l)*3+1]={1, 0};
				}
			}
		}
	}
	for(int k=0; k<n*n*3; ++k)
		for(int i=0; i<n*n*3; ++i)
			for(int j=0; j<n*n*3; ++j)
				d[i][j]=min(d[i][k]+d[k][j], d[i][j]);
	memset(dp, 1, sizeof(dp));
	dp[0][0]=dp[0][1]=dp[0][2]={};
	for(int i=1; i<n*n; ++i)
		for(int j=0; j<3; ++j)
			for(int k=0; k<3; ++k)
				dp[i][j]=min(dp[i-1][k]+d[p[i-1]*3+k][p[i]*3+j], dp[i][j]);
	array<int, 2> a=min({dp[n*n-1][0], dp[n*n-1][1], dp[n*n-1][2]});
	cout << a[0] << " " << a[1];
}