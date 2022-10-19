#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], m, i, f2;

map <int, int> dp[N];

vector <int> val[N], val2[N];

int dfs(int l, int r){
	if(dp[r].count(l)) return dp[r][l];
	
	int res = 0;
	
	for(auto x : val[r])
		if(r - x * 2 + 1 >= l)
		res = max(res, dfs(l, r - x) + 1);
	
	for(auto x : val2[l]) 
	if(l + x * 2 - 1 <= r)
	res = max(res, dfs(l + x, r) + 1);
	
	return dp[r][l] = res;
}
int main(){
	cin >> n;
	for(int i = 1, c; i <= n; ++ i) {
		scanf("%d", &c);
		a[m + 1] = c;
		if(a[m] == c)
		val[m + 1].clear(), val[m + 1].push_back(1);
		for(auto x : val[m]) 
		if(a[m - x * 2] == c) val[m + 1].push_back(x + 1);
		++ m; int pos = 0;
		for(auto x : val[m]) {
			int now = lower_bound(val[m - x].begin(), val[m - x].end(), x) - val[m - x].begin();
			if(now != val[m - x].size() && val[m - x][now] == x)
			pos = x; // 
		} 
		for(auto x : val[m]) 
		val2[m - x * 2 + 1].push_back(x);
		if(pos) 
		for(pos <<= 1, ++ f2; pos --;) {
			for(auto x : val[m]) 
			val2[m - x * 2 + 1].pop_back();
			val[m].clear(), dp[m].clear(), -- m;
		}else dfs(1, m);
		printf("%d ", f2 * 2 + dp[m][1]);
	}
	puts("");
}