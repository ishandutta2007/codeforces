#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3, di[4]={-1, 1, 0, 0}, dj[4]={0, 0, -1, 1};
const char dc[4]={'U', 'D', 'L', 'R'};
int n, x[mxN][mxN], y[mxN][mxN];
char ans[mxN][mxN];
bool vis[mxN][mxN];

void dfs1(int i, int j) {
	for(int k=0; k<4; ++k) {
		int ni=i+di[k], nj=j+dj[k];
		if(ni<0||ni>=n||nj<0||nj>=n)
			continue;
		if(x[ni][nj]^x[i][j]||y[ni][nj]^y[i][j])
			continue;
		if(ans[ni][nj])
			continue;
		ans[ni][nj]=dc[k^1];
		dfs1(ni, nj);
	}
}

ar<int, 2> dfs2(int i, int j, int pi=-1, int pj=-1) {
	vis[i][j]=1;
	for(int k=0; k<4; ++k) {
		int ni=i+di[k], nj=j+dj[k];
		if(ni<0||ni>=n||nj<0||nj>=n)
			continue;
		if(x[ni][nj]^x[i][j]||y[ni][nj]^y[i][j])
			continue;
		//if(ni==pi&&nj==pj)
			//continue;
		if(vis[ni][nj]) {
			ans[ni][nj]=dc[k^1];
			return {ni, nj};
		}
		ar<int, 2> cu=dfs2(ni, nj, i, j);
		if(~cu[0])
			return cu;
	}
	return {-1};
}

void dfs3(int i, int j) {
	for(int k=0; k<4; ++k) {
		int ni=i+di[k], nj=j+dj[k];
		if(ni<0||ni>=n||nj<0||nj>=n)
			continue;
		if(x[ni][nj]^x[i][j]||y[ni][nj]^y[i][j])
			continue;
		if(ans[ni][nj])
			continue;
		ans[ni][nj]=dc[k^1];
		dfs3(ni, nj);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> x[i][j] >> y[i][j];
		}
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(x[i][j]-1==i&&y[i][j]-1==j) {
				ans[i][j]='X';
				dfs1(i, j);
			}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(~x[i][j]&&!ans[i][j]) {
				//can't reach target
				cout << "INVALID";
				return 0;
			}
		}
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(ans[i][j])
				continue;
			//make sure cycle in component
			ar<int, 2> cu=dfs2(i, j);
			if(cu[0]<0) {
				cout << "INVALID";
				return 0;
			}
			dfs3(cu[0], cu[1]);
		}
	}
	cout << "VALID\n";
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j)
			cout << ans[i][j];
		cout << "\n";
	}
}