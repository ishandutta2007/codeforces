#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1000;
const int MAXM = MAXN*MAXN;

int ch[26][MAXM + 5], dfn[MAXM + 5], ncnt, dcnt;
void dfs(int x) {
	dfn[x] = (++dcnt);
	for(int i=0;i<26;i++)
		if( ch[i][x] ) dfs(ch[i][x]);
}
char ans[MAXN + 5];
void print(int x, int k, int d) {
	if( dfn[x] == k ) puts(ans);
	for(int i=0;i<26;i++)
		if( ch[i][x] ) ans[d] = i + 'a', print(ch[i][x], k, d + 1), ans[d] = 0;
}

int id[MAXN + 5][MAXN + 5], n, m; ll k;
ll add(ll x, ll y) {return (x + y > k ? k : x + y);}
ll mul(ll x, ll y) {return (x > k / y ? k : x * y);}

int a[MAXN + 5]; ll f[MAXN + 5][MAXN + 5], sum[MAXN + 5][MAXN + 5];
bool check(int x) {
	for(int i=n;i>=1;i--) {
		a[i] = 0;
		while( i + a[i] <= n && id[i][i + a[i]] <= x )
			a[i]++;
	}
	
	f[n + 1][0] = sum[n + 1][0] = 1;
	for(int i=n;i>=1;i--) {
		for(int j=0;j<=m;j++) f[i][j] = 0;
		for(int j=1;j<=m;j++) f[i][j] = add(f[i][j], sum[i + a[i] + 1][j - 1]);
		for(int j=0;j<=m;j++) sum[i][j] = add(sum[i + 1][j], f[i][j]);
	}
	return f[1][m] < k;
}

char s[MAXN + 5];
int main() {
	scanf("%d%d%lld%s", &n, &m, &k, s + 1);
	for(int i=1;i<=n;i++) {
		int nw = 0;
		for(int j=i;j<=n;j++) {
			if( ch[s[j] - 'a'][nw] == 0 )
				ch[s[j] - 'a'][nw] = (++ncnt);
			id[i][j] = nw = ch[s[j] - 'a'][nw];
		}
	}
	
	dfs(0);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			id[i][j] = dfn[id[i][j]];
	
	int l = 1, r = dcnt;
	while( l < r ) {
		int mid = (l + r) >> 1;
		if( check(mid) ) r = mid;
		else l = mid + 1;
	}
	print(0, r, 0);
}