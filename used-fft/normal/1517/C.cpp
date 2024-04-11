#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g(500, vector<int> (500, -1));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n;

int dfs(int i, int j, int left, int ID){
	if(min(i, j) < 0 or max(i, j) == n or g[i][j] >= 0 or !left) return 0;
	int res = 1; --left;
	g[i][j] = ID;
	for(int k=0; k<4; ++k){
		int x = i + dx[k];
		int y = j + dy[k];
		int curr = dfs(x, y, left, ID);
		left -= curr;
		res += curr;
	}
	return res;
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int a[n]; for(int &i : a) cin >> i;

	bool ok = true;

	for(int i=0; i<n; ++i){
		if(dfs(i, i, a[i], a[i]-1) < a[i]) ok = false;
	}

	if(!ok){
		cout << -1 << '\n';
	}else{
		for(int i=0; i<n; ++i){
			for(int j=0; j<=i; ++j){
				cout << g[i][j] + 1 << ' ';
			}cout << '\n';
		}
	}
}