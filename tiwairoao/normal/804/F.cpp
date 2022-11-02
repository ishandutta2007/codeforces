#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 5000;
const int MAXS = 2000000;
const int MOD = int(1E9) + 7;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
vector<int>vec[MAXN + 5];
char str[MAXS + 5];
bool G[MAXN + 5][MAXN + 5];
int n, a, b;
int tid[MAXN + 5], low[MAXN + 5], dcnt;
int num[MAXN + 5], stk[MAXN + 5], tot, tp;
int val[MAXN + 5];
void dfs(int x) {
	tid[x] = low[x] = (++dcnt), stk[++tp] = x;
	for(int i=1;i<=n;i++)
		if( G[x][i] ) {
			if( !tid[i] )
				dfs(i), low[x] = min(low[x], low[i]);
			else if( !num[i] )
				low[x] = min(low[x], tid[i]);
		}
	if( low[x] >= tid[x] ) {
		val[++tot] = 0;
		while( tp && tid[stk[tp]] >= tid[x] ) {
			int t = stk[tp--];
			num[t] = tot, val[tot] = gcd(val[tot], vec[t].size());
		}
	}
}
vector<int>v2[MAXN + 5];
int key[MAXN + 5]; bool tmp[MAXS + 5];
struct node{
	int tr, mx;
}nd[MAXN + 5];
int comb[MAXN + 5][MAXN + 5], f[MAXN + 5], g[MAXN + 5];
int solve() {
	for(int i=0;i<=n;i++) {
		comb[i][0] = 1;
		for(int j=1;j<=n;j++)
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		f[i] = g[i] = 0;
		for(int j=1;j<=n;j++) {
			if( nd[j].tr > nd[i].mx )
				f[i]++;
			else if( nd[j].mx > nd[i].mx || (nd[j].mx == nd[i].mx && j > i) )
				g[i]++;
		}
		for(int j=0;j<=g[i];j++)
			if( b - j - 1 >= 0 && b - j - 1 <= f[i] && f[i] + j + 1 <= a )
				ans = (ans + 1LL*comb[g[i]][j]*comb[f[i]][b-j-1])%MOD;
	}
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for(int i=1;i<=n;i++) {
		scanf("%s", str + 1);
		for(int j=1;j<=n;j++)
			G[i][j] = str[j] - '0';
	}
	for(int i=1;i<=n;i++) {
		int siz; scanf("%d%s", &siz, str);
		for(int j=0;j<siz;j++)
			vec[i].push_back(str[j] - '0'), nd[i].tr += (str[j] - '0');
	}
	for(int i=1;i<=n;i++)
		if( !tid[i] ) dfs(i);
	for(int i=1;i<=tot;i++)
		for(int j=0;j<val[i];j++)
			v2[i].push_back(0);
	for(int i=1;i<=n;i++)
		for(int j=0;j<vec[i].size();j++)
			v2[num[i]][j%val[num[i]]] |= vec[i][j];
	for(int i=tot;i>=2;i--) {
		int p = gcd(v2[i].size(), v2[i - 1].size());
		for(int j=0;j<p;j++) tmp[j] = false;
		for(int j=0;j<v2[i].size();j++) tmp[j % p] |= v2[i][j];
		for(int j=0;j<v2[i-1].size();j++) v2[i-1][j] |= tmp[j % p];
	}
	for(int i=1;i<=tot;i++)
		for(int j=0;j<v2[i].size();j++)
			key[i] += v2[i][j];
	for(int i=1;i<=n;i++)
		nd[i].mx = vec[i].size()/val[num[i]]*key[num[i]];
	printf("%d\n", solve());
}