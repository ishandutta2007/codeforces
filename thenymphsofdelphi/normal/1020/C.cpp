#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 3005, mod = 1e9 + 7, inf = 1e18;
int n, m, dp[N][N], take[N];
vector <int> v[N];
multiset <int> s;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		x--;
		v[x].pb(y);
		if (x != 0){
		    s.insert(y);
		}
	}
	for (int i = 0; i < m; i++){
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++){
			dp[i][j] = (j != 0 ? dp[i][j-1] : 0) + v[i][j];
		}
	}
	int ans = inf;
	for (int i = max(1LL, (int)v[0].size()); i <= n; i++){
		int cur = 0, picked = v[0].size();
		for (int j = 1; j < m; j++){
			if (v[j].size() < i){
			    take[j] = 0;
			}
			else{
			    take[j] = v[j].size() - i + 1;
			}
			if (take[j]){
			    cur += dp[j][take[j] - 1];
			}
			picked += take[j];
		}
		if (picked >= i){
		    ans = min(ans, cur);
		}
		else{
			queue <int> q;
			for (int j = 1; j < m; j++){
				for (int k = 0; k < take[j]; k++){
					s.erase(s.find(v[j][k]));
					q.push(v[j][k]);
				}
			}
			while (picked < i){
				cur += *s.begin();
				q.push(*s.begin());
				s.erase(s.begin());
				picked++;
			}
			while (!q.empty()){
				s.insert(q.front());
				q.pop();
			}
			ans = min(ans, cur);
		}
	}
	cout << ans;
}