#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, ans=0;
	cin >> n >> m >> k;
	string *grid = new string[n];
	for(int i=0; i<n; ++i) {
		cin >> grid[i];
		int numEmpty=0;
		for(int j=0; j<m; ++j) {
			if(grid[i][j]=='.')
				++numEmpty;
			if(j>=k&&grid[i][j-k]=='.')
				--numEmpty;
			if(numEmpty==k)
				++ans;
		}
	}
	if(k>1) {
		for(int i=0; i<m; ++i) {
			int numEmpty=0;
			for(int j=0; j<n; ++j) {
				if(grid[j][i]=='.')
					++numEmpty;
				if(j>=k&&grid[j-k][i]=='.')
					--numEmpty;
				if(numEmpty==k)
					++ans;
			}
		}
	}
	cout << ans;
}