#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1000000;
vector<int>vec[MAXN + 5], vis[MAXN + 5];
char str[MAXN + 5];
int n, m;
bool dfs(pii x) {
	if( x == make_pair(n, m) ) return true;
	vis[x.first][x.second] = true;
	if( vec[x.first][x.second] == -1 ) return false;
	if( vec[x.first][x.second] == 0 ) {
		if( (!vis[x.first + 1][x.second] && dfs(make_pair(x.first + 1, x.second)))
			|| (!vis[x.first][x.second + 1] && dfs(make_pair(x.first, x.second + 1))) ) {
				if( x.first == 1 && x.second == 1 ) ;
				else vec[x.first][x.second] = 1;
				return true;
			}
	}
	else {
		vec[x.first][x.second] = 1;
		if( (!vis[x.first - 1][x.second] && dfs(make_pair(x.first - 1, x.second)))
			|| (!vis[x.first][x.second - 1] && dfs(make_pair(x.first, x.second - 1))) ) {
				if( x.first == 1 && x.second == 1 ) ;
				else vec[x.first][x.second] = 0;
				return true;
			}
	}
	return false;
}
void init() {
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			vis[i][j] = false;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=0;i<=m+1;i++)
		vec[0].push_back(-1), vis[0].push_back(false);
	for(int i=1;i<=n;i++) {
		vec[i].push_back(-1), vis[i].push_back(false);
		scanf("%s", str + 1);
		for(int j=1;j<=m;j++)
			if( str[j] == '.' )
				vec[i].push_back(0), vis[i].push_back(false);
			else vec[i].push_back(-1), vis[i].push_back(false);
		vec[i].push_back(-1), vis[i].push_back(false);
	}
	for(int i=0;i<=m+1;i++)
		vec[n+1].push_back(-1), vis[n+1].push_back(false);
	int ans = 0; while( dfs(make_pair(1, 1)) ) ans++, init();
	printf("%d\n", ans);
}