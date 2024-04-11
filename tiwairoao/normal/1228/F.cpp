#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN = 17;
const int MAXM = (1<<MAXN);
int siz[MAXM + 5], deg[MAXM + 5], cnt[MAXM + 5], n, m, rt;
vector<int>G[MAXM + 5];
void addedge(int a, int b) {
	G[a].push_back(b);
	G[b].push_back(a);
}
int mxd[MAXM + 5], dep[MAXM + 5], fa[MAXM + 5];
void dfs(int x, int f) {
	fa[x] = f, dep[x] = dep[f] + 1, mxd[x] = dep[x];
	for(int i=0;i<G[x].size();i++) {
		int p = G[x][i];
		if( p == f ) continue;
		dfs(p, x);
		mxd[x] = max(mxd[x], mxd[p]);
	}
}
int find_root() {
	dfs(1, 0);
	int x = 1;
	for(int i=1;i<=m-2;i++)
		if( dep[i] > dep[x] ) x = i;
	dfs(x, 0);
	int y = x;
	for(int i=1;i<=m-2;i++)
		if( dep[i] > dep[y] ) y = i;
	if( !(dep[y] & 1) ) {
		puts("0");
		exit(0);
	}
	int p = y;
	while( dep[y] - dep[p] != dep[p] - dep[x] ) p = fa[p];
	return p;
}
bool check(int x, int f) {
	siz[x] = 1;
	int tmp = -1;
	for(int i=0;i<G[x].size();i++) {
		int p = G[x][i];
		if( p == f || p == fa[x] ) continue;
		if( !check(p, x) ) return false;
		siz[x] += siz[p];
		if( tmp == -1 ) tmp = siz[p];
		else if( tmp != siz[p] ) return false;
	}
	return true;
}
bool check() {
	return check(rt, 0);
}
int main() {
	scanf("%d", &n), m = (1<<n);
	for(int i=1;i<=m-3;i++) {
		int a, b; scanf("%d%d", &a, &b);
		deg[a]++, deg[b]++, addedge(a, b);
	}
	if( n == 2 ) {
		printf("2\n1 2\n");
		return 0;
	}
	for(int i=1;i<=m-2;i++)
		cnt[deg[i]]++;
	for(int i=5;i<=m;i++)
		if( cnt[i] ) {
			puts("0");
			return 0;
		}
	if( cnt[1] != (1<<(n-1)) && cnt[1] != (1<<(n-1)) - 1 ) {
		puts("0");
		return 0;
	}
	if( cnt[1] == (1<<(n-1)) && cnt[4] == 0 && cnt[2] == 0 ) {
		dfs(1, 0);
		int x = 1;
		for(int i=1;i<=m-2;i++)
			if( dep[i] > dep[x] ) x = i;
		dfs(x, 0);
		int y = x;
		for(int i=1;i<=m-2;i++)
			if( dep[i] > dep[y] ) y = i;
		if( (dep[y] & 1) ) {
			puts("0");
			return 0;
		}
		int p = y;
		while( dep[y] - dep[p] < dep[p] - dep[x] - 1 ) p = fa[p];
		int q = fa[p];
		dep[q] = 0, dfs(p, q), dep[p] = 0, dfs(q, p), dep[p] = dep[q] = 1;
		if( check(p, q) && check(q, p) && mxd[p] == mxd[q] ) {
			printf("2\n%d %d\n", min(p, q), max(p, q));
			return 0;
		}
		else puts("0");
		return 0;
	}
	rt = find_root(), dfs(rt, 0);
	if( cnt[1] == (1<<(n-1)) ) {
		if( cnt[4] == 1 ) {
			if( cnt[2] == 1 && deg[rt] == 2 ) {
				int k = -1;
				for(int i=1;i<=m-2;i++)
					if( deg[i] == 4 ) k = i;
				int x = -1, y = -1, z = -1;
				for(int i=0;i<G[k].size();i++)
					if( G[k][i] != fa[k] ) {
						if( x == -1 ) x = G[k][i];
						else if( y == -1 ) y = G[k][i];
						else z = G[k][i];
					}
				G[k].clear(); G[k].push_back(m - 1); G[k].push_back(fa[k]);
				if( mxd[x] == mxd[y] && mxd[x] + 1 == mxd[z] ) {
					G[k].push_back(z);
					G[m - 1].push_back(y); 
					G[m - 1].push_back(x);
				}
				else if( mxd[y] == mxd[z] && mxd[y] + 1 == mxd[x] ) {
					G[k].push_back(x);
					G[m - 1].push_back(y);
					G[m - 1].push_back(z);
				}
				else if( mxd[x] == mxd[z] && mxd[x] + 1 == mxd[y] ) {
					G[k].push_back(y);
					G[m - 1].push_back(x);
					G[m - 1].push_back(z);
				}
				else {
					puts("0");
					return 0;
				}
				if( check() )
					printf("1\n%d\n", k);
				else puts("");
				return 0;
			}
		}
		puts("0");
		return 0;
	}
	else if( cnt[1] == (1<<(n-1)) - 1 ) {
		if( cnt[4] == 0 && cnt[2] == 2 && deg[rt] == 2 ) {
			int x = -1;
			for(int i=1;i<=m-2;i++)
				if( deg[i] == 2 && i != rt )
					x = i;
			addedge(x, m - 1);
			if( check() )
				printf("1\n%d\n", x);
			else puts("");
		}
		else {
			puts("0");
			return 0;
		}
		return 0;
	}
}