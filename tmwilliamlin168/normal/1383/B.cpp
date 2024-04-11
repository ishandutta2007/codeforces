#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool dp[2][9][9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
	dp[0][0][0]=1;
	for(int i=0; i<9; ++i) {
		for(int j=0; j<9; ++j) {
			if(i) {
				dp[0][i][j]|=!dp[(i-1)&1][i-1][j];
				dp[1][i][j]|=!dp[(i-1)&1^1][i-1][j];
			}
			if(j) {
				dp[0][i][j]|=!dp[(i-1)&1^1][i][j-1];
				dp[1][i][j]|=!dp[(i-1)&1][i][j-1];
			}
			cout << dp[1][i][j] << " ";
		}
		cout << endl;
	}
	*/
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; ++i)
			cin >> a[i];
		for(int k=29; ~k; --k) {
			int o=0;
			for(int i=0; i<n; ++i)
				o+=a[i]>>k&1;
			if(o&1) {
				if(o%4==1||o%4==3&&(n-o)%2==1) {
					cout << "WIN\n";
				} else {
					cout << "LOSE\n";
				}
				break;
			}
			if(!k)
				cout << "DRAW\n";
		}
	}
}