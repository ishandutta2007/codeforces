#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 83;
const int MAXM = 2e3 + 3;
const int inf = 1e9 + 9;

int n, k, m;
int w[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][2];
bool was[MAXN][MAXN][MAXN][2];

void dfs(int i, int j, int cnt, int bnd){
	was[i][j][cnt][bnd] = true;
	if(cnt == 1){
		dp[i][j][cnt][bnd] = 0;
		ret;
	}
	if(i == j)ret;
	int l = i, r = j;
	if(bnd == 0)l++; else r--;
	int v = (bnd == 0) ? i : j;
	F(mid, l, r + 1){
		if(w[v][mid] == 0)cont;
		if(!was[l][mid][cnt - 1][1])dfs(l, mid, cnt - 1, 1);
		if(!was[mid][r][cnt - 1][0])dfs(mid, r, cnt - 1, 0);
		int nxt = min(dp[l][mid][cnt - 1][1], dp[mid][r][cnt - 1][0]);
		dp[i][j][cnt][bnd] = min(dp[i][j][cnt][bnd], nxt + w[v][mid]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	fi0(w); fi0(was);
	F(i, 0, m){
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);
		v--; u--;
		w[v][u] = (w[v][u] == 0) ? c : min(w[v][u], c);
	}
	F(i, 0, MAXN)
		F(j, 0, MAXN)
			F(l, 0, MAXN)
				dp[i][j][l][0] = dp[i][j][l][1] = inf;
	if(k == 1){
		printf("0"); ret 0;
	}
	int ans = inf;
	F(i, 0, n){
		if(!was[0][i][k][1])dfs(0, i, k, 1);
		if(!was[i][n - 1][k][0])dfs(i, n - 1, k, 0);
		ans = min(ans, dp[0][i][k][1]);
		ans = min(ans, dp[i][n - 1][k][0]);
	}
	if(ans == inf)printf("-1");
	else printf("%d", ans);
	ret 0;
}