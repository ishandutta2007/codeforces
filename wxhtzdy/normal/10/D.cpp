#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++){
		cin >> b[i];
	}
	vector<vector<int>> dp(n, vector<int>(m));
	vector<vector<pair<int, int>>> nxt(n, vector<pair<int, int>>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i] != b[j]){
				dp[i][j] = (i == 0 ? 0 : dp[i - 1][j]);
				nxt[i][j] = (i == 0 ? make_pair(i, j) : make_pair(i - 1, j));
			} else{
				dp[i][j] = 1;
				nxt[i][j] = {i, j};
				for(int k = 0; k < j; k++){
					int ndp = (i == 0 ? 0 : dp[i - 1][k]) + 1;
					if (b[k] < b[j] && dp[i][j] < ndp){
						dp[i][j] = ndp;
						nxt[i][j] = (i == 0 ? make_pair(i, k) : make_pair(i - 1, k));
					}
				}
			}
		}
	}
	tuple<int, int, int> ans = {-1, 0, 0};
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ans = max(ans, {dp[i][j], i, j});
		}
	}
	cout << get<0>(ans) << endl;
	if(get<0>(ans) == 0) return 0;
	set<int> S;
	function<void(int, int)> dfs = [&](int x, int y){
		S.insert(b[y]);
		if (nxt[x][y] == make_pair(x, y)) return;
		dfs(nxt[x][y].first, nxt[x][y].second);
	};
	dfs(get<1>(ans), get<2>(ans));
	for (int x : S) cout << x << " ";
}