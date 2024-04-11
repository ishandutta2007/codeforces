#include<bits/stdc++.h>
using namespace std;

const int N = 605;
const int M = 20005 * 2;

int dis[N][N] , n , m , k , tour , x , y , t;
int st[N] , nowdis[205][605]  , link[605];
bool vis[N];

bool dfs(int x) {
	if(vis[x]) return 0;
	vis[x] = 1;
	for(int i = 1;i <= n;i ++) if(nowdis[x][i]){
		if(!link[i] || dfs(link[i])) {
			link[i] = x;
			return 1;
		}
	}
	return 0;
}

bool pd(int x) {
	memset(link,0,sizeof(link));
	for(int i = 1;i <= tour;i ++) {
		for(int j = 1;j <= n;j ++) {
			nowdis[i][j] = (dis[st[i]][j] > x) ? 0 : 1;
		}
	}
	
	int res = 0;
	for(int i = 1;i <= tour;i ++) {
		memset(vis,0,sizeof(vis));
		if(dfs(i)) res ++;
	}
	
	return (res >= k);
}

int main() {
	cin>>n >> m >> tour>>k;
	memset(dis,63,sizeof(dis));
	for(int i = 1;i <= n;i ++) dis[i][i] = 0;
	for(int i = 1;i <= tour;i ++) scanf("%d",&st[i]);
	for(int i = 1;i <= m;i ++) {
		scanf("%d%d%d",&x,&y,&t);
		dis[y][x] = dis[x][y] = min(dis[x][y] , t);
	}
	for(int k = 1;k <= n;k ++)
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
		}
	}
	
	int ans = -1;
	
	int l = 0 , r = 1731311;
	while(l <= r) {
//		cout<<l<<" "<<r<<endl;
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			ans = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	cout<<ans<<endl;
}