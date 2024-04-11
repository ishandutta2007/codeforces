#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
ll dp1[mxN+1][10], dp2[4][4][2];
//moves, cost, double damaged

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	memset(dp1, 0xc0, sizeof(dp1));
	dp1[0][0]=0;
	for(int _=0; _<n; ++_) {
		memset(dp2, 0xc0, sizeof(dp2));
		dp2[0][0][0]=0;
		int k;
		cin >> k;
		for(int __=0, c, d; __<k; ++__) {
			cin >> c >> d;
			for(int x=2; x>=0; --x) {
				for(int y=0; y<4-c; ++y) {
					for(int z=0; z<2; ++z) {
						dp2[x+1][y+c][z]=max(dp2[x][y][z]+d, dp2[x+1][y+c][z]);
						if(!z)
							dp2[x+1][y+c][1]=max(dp2[x][y][z]+2*d, dp2[x+1][y+c][1]);
					}
				}
			}
		}
		for(int x=0; x<4; ++x) {
			for(int y=1; y<4; ++y) {
				for(int z=0; z<2; ++z) {
					dp2[x][0][z]=max(dp2[x][y][z], dp2[x][0][z]);
				}
			}
		}
		for(int i=0; i<10; ++i) {
			for(int x=0; x<4; ++x) {
				int ni=(i+x)%10, z=i+x>=10;
				dp1[_+1][ni]=max(dp1[_+1][ni], dp1[_][i]+dp2[x][0][z]);
			}
		}
	}
	ll ans=0;
	for(int i=0; i<10; ++i)
		ans=max(dp1[n][i], ans);
	cout << ans;
}