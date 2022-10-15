#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100;
int n, m;
ll a[mxN][mxN], dp[mxN][mxN];

ll ev(int x, int y, int i, int j) {
	ll nh=a[x][y]+(i+j)-(x+y);
	if(nh>a[i][j])
		return 1e18;
	return a[i][j]-nh;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				cin >> a[i][j];
		ll ans=1e18;
		for(int x=0; x<n; ++x) {
			for(int y=0; y<m; ++y) {
				//dp[0][0]=ev(x, y, 0, 0);
				for(int i=0; i<n; ++i) {
					for(int j=0; j<m; ++j) {
						if(i||j)
							dp[i][j]=1e18;
						else
							dp[i][j]=0;
						if(i)
							dp[i][j]=min(dp[i-1][j], dp[i][j]);
						if(j)
							dp[i][j]=min(dp[i][j-1], dp[i][j]);
						dp[i][j]+=ev(x, y, i, j);
						dp[i][j]=min(dp[i][j], (ll)1e18);
					}
				}
				ans=min(dp[n-1][m-1], ans);
			}
		}
		cout << ans << "\n";
	}
}