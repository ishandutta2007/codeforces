#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	cin >> R >> C;
	vector<string> S(R);
	for(int i = 0; i < R; i++) cin >> S[i];
	vector< vector<char> > reach(R, vector<char>(C, 0));
	reach[0][0] |= 1;
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) if(S[i][j] == '.') {
		if(i < R-1 && S[i+1][j] == '.') reach[i+1][j] |= reach[i][j]&1;
		if(j < C-1 && S[i][j+1] == '.') reach[i][j+1] |= reach[i][j]&1;
	}
	reach[R-1][C-1] |= 2;
	for(int i = R-1; i >= 0; i--) for(int j = C-1; j >= 0; j--) if(S[i][j] == '.') {
		if(i > 0 && S[i-1][j] == '.') reach[i-1][j] |= reach[i][j]&2;
		if(j > 0 && S[i][j-1] == '.') reach[i][j-1] |= reach[i][j]&2;
	}
	if(reach[0][0] != 3) {
		cout << "0\n";
		return 0;
	}
	for(int d = 1; d < R-1+C-1; d++) {
		int cnt = 0;
		// max(0, d-C+1) <= r <= min(d, R-1)
		for(int r = max(0, d-C+1); r <= min(d, R-1); r++) {
			int c = d-r;
			if(reach[r][c] == 3) cnt++;
		}
		if(cnt == 1) {
			cout << "1\n";
			return 0;
		}
	}
	cout << "2\n";
}