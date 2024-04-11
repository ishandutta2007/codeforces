#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<string> mp;
char buf[1000100];
vector<vector<int>> vis[2];

int main() {
	scanf("%d%d",&n,&m);
	mp.assign(n,string());
	for (int i=0;i<n;i++) {
		scanf(" %s",buf);
		mp[i] = string(buf);
	}
	vis[0].assign(n,vector<int>(m,0));
	vis[1].assign(n,vector<int>(m,0));
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (i==0&&j==0) {
				vis[0][i][j] = 1;
				continue;
			}
			if (mp[i][j]=='.') {
				vis[0][i][j] = (i?vis[0][i-1][j]:0)||(j?vis[0][i][j-1]:0);
			}
		}
	}
	for (int i=n-1;i>=0;i--) {
		for (int j=m-1;j>=0;j--) {
			if (i==n-1&&j==m-1) {
				vis[1][i][j] = 1;
				continue;
			}
			if (mp[i][j]=='.') {
				vis[1][i][j] = (i<n-1?vis[1][i+1][j]:0)||(j<m-1?vis[1][i][j+1]:0);
			}
		}
	}
	int ans = 2;
	for (int s=1;s<n+m-2;s++) {
		int cnt = 0;
		for (int i=max(s-m+1,0);i<=n&&i<=s;i++) {
			int j = s-i;
			if (i<0||i>=n||j<0||j>=m) continue;
			if (!vis[0][i][j]||!vis[1][i][j]) continue;
			cnt++;
		}
		ans = min(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}