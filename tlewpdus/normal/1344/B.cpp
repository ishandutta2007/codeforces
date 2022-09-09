#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
char str[1010][1010];
int vis[1010][1010];
int px[] = {1,0,-1,0};
int py[] = {0,1,0,-1};

bool ok(int x, int y) {
	return x>=0&&x<n&&y>=0&&y<m&&str[x][y]=='#';
}
void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i=0;i<4;i++) {
		int nx=x+px[i], ny=y+py[i];
		if (ok(nx,ny)&&!vis[nx][ny]) {
			dfs(nx,ny);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",str[i]);
	int mang = 0, ac = 0, bc = 0;
	for (int i=0;i<n;i++) {
		int mini = m, maxi = -1, cnt = 0;
		for (int j=0;j<m;j++) {
			if (str[i][j]=='#') {
				mini = min(mini,j);
				maxi = max(maxi,j);
				cnt++;
			}
		}
		if (cnt==0) ac++;
		if (cnt==0||(maxi-mini+1==cnt)) continue;
		mang = 1;
		break;
	}
	for (int j=0;j<m;j++) {
		int mini = n, maxi = -1, cnt = 0;
		for (int i=0;i<n;i++) {
			if (str[i][j]=='#') {
				mini = min(mini,i);
				maxi = max(maxi,i);
				cnt++;
			}
		}
		if (cnt==0) bc++;
		if (cnt==0||(maxi-mini+1==cnt)) continue;
		mang = 1;
		break;
	}
	if (mang) {
		puts("-1");
		return 0;
	}
	if ((ac!=0&&bc==0)||(ac==0&&bc!=0)) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (str[i][j]=='#'&&!vis[i][j]) {
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}