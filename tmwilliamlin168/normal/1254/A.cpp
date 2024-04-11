#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, k;
string g[100];
vector<char> vc;
char ans[100][100];

void solve() {
	cin >> n >> m >> k;
	int tr=0;
	for(int i=0; i<n; ++i) {
		cin >> g[i];
		for(char c : g[i]) {
			tr+=c=='R';
		}
	}
	vector<ar<int, 2>> cs;
	for(int i=0; i<n; ++i) {
		if(i&1) {
			for(int j=m-1; ~j; --j) {
				cs.push_back({i, j});
			}
		} else {
			for(int j=0; j<m; ++j) {
				cs.push_back({i, j});
			}
		}
	}
	for(int i=0, j=0; i<k; ++i) {
		int tg=(tr+i)/k;
		while(tg||j<cs.size()&&i==k-1) {
			ans[cs[j][0]][cs[j][1]]=vc[i];
			if(g[cs[j][0]][cs[j][1]]=='R') {
				--tg;
			}
			++j;
		}
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j)
			cout << ans[i][j];
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<26; ++i) {
		vc.push_back('a'+i);
		vc.push_back('A'+i);
	}
	for(int i=0; i<10; ++i) {
		vc.push_back('0'+i);
	}

	int t;
	cin >> t;
	while(t--)
		solve();
}