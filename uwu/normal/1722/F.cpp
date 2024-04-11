#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool good(int x, int y){
	if(1<=x&&x<=n&&y>=1&&m>=y)return true;
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<vector<char>>mp(n+1,vector<char>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				mp[i][j] = s[j-1];
			}
		}
		vector<int>dx = {-1,0,1,0,1,1,-1,-1};
		vector<int>dy = {0,1,0,-1,-1,1,1,-1};
		bool f = true;
		vector<vector<bool>>vis(n+1,vector<bool>(m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				queue<pair<int,int>>q;
				if(vis[i][j])continue;
				if(mp[i][j]!='*')continue;
				q.push({i,j});
				vis[i][j] = true;
				set<int>sx;
				set<int>sy;
				sx.insert(i);
				sy.insert(j);
				int cnt = 1;
				while(q.size()){
					pair<int,int>cur = q.front(); q.pop();
					int x = cur.first; int y = cur.second;
					for(int d = 0; d<8; d++){
						int nx = x+dx[d];
						int ny = y+dy[d];
						if(!good(nx,ny))continue;
						if(vis[nx][ny])continue;
						if(mp[nx][ny]=='.')continue;
						q.push({nx,ny});
						sx.insert(nx); sy.insert(ny);
						vis[nx][ny] = true;
						cnt++;
					}
				}
				if(cnt==3&&sx.size()==2&&sy.size()==2)continue;
				f = false;
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}