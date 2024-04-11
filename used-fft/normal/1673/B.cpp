#include <bits/stdc++.h>
using namespace std;

const int B = 26;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s; cin >> s;

		int n = size(s);
		vector<int> g[B];
		for(int i = 0; i < n; ++i)
			g[s[i] - 'a'].push_back(i);

		bool ok = 1;
		for(int i = 0; i < B && ok; ++i) if(!empty(g[i])) {
			for(int j = 0; j < B; ++j) if(i != j && !empty(g[j])) {
				vector<int> cur;
				int k = 0, sz = size(g[j]);
				for(int &u : g[i]) {
					while(k < sz && g[j][k] < u) cur.push_back(-1), ++k;
					cur.push_back(1);
				}
				while(k < sz) cur.push_back(-1), ++k;

				int dp {};
				for(int v : cur) {
					dp = v + max(dp, 0);
					if(dp > 1) ok = 0;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}