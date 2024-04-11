#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 400000;
const int MAXV = 2500000;
vector<int>G[MAXV + 5], vec[MAXV + 5];
void addedge(int u, int v) {
//	printf("! %d %d\n", u, v);
	G[u].push_back(v);
}
int tid[MAXV + 5], low[MAXV + 5], num[MAXV + 5], stk[MAXV + 5];
int tp, tot, dcnt;
void dfs(int x) {
    stk[++tp] = x; tid[x] = low[x] = (++dcnt);
    for(int i=0;i<G[x].size();i++) {
        int p = G[x][i];
        if( !tid[p] )
            dfs(p), low[x] = min(low[x], low[p]);
        else if( !num[p] )
            low[x] = min(low[x], tid[p]);
    }
    if( low[x] >= tid[x] ) {
        tot++;
        while( tp && tid[stk[tp]] >= tid[x] ) {
            int t = stk[tp--];
            num[t] = tot, vec[tot].push_back(t);
        }
    }
}
int id1[MAXN + 5], id2[MAXN + 5], id3[MAXN + 5], id4[MAXN + 5];
int n, p, M, m;
bool tag[MAXV + 5];
void solve() {
    for(int i=1;i<=tot;i++) {
        for(int j=0;j<vec[i].size();j++) {
            int x = vec[i][j];
            for(int k=0;k<G[x].size();k++)
                if( tag[num[G[x][k]]] )
                    tag[i] = true;
        }
        if( !tag[i] ) {
            for(int j=0;j<vec[i].size();j++) {
                int x = vec[i][j];
                if( x < 2*(M + p) )
                    tag[num[x^1]] = true;
            }
        }
    }
}
vector<int>ans;
int l[MAXN + 5], r[MAXN + 5];
int main() {
	scanf("%d%d%d%d", &n, &p, &M, &m);
	int cnt = 0;
	for(int i=1;i<=p;i++) id1[i] = (cnt++);
	for(int i=1;i<=M;i++) id2[i] = (cnt++);
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		addedge(id1[x]<<1, id1[y]<<1|1);
		addedge(id1[y]<<1, id1[x]<<1|1);
	}
	cnt <<= 1;
	int nw = id2[1]<<1; id3[1] = nw;
	for(int i=2;i<=M;i++) {
		addedge(id2[i]<<1|1, nw);
		if( i == M ) break;
		id3[i] = (cnt++);
		addedge(id3[i], nw);
		addedge(id3[i], id2[i]<<1);
		nw = id3[i];
	}
	nw = id2[M]<<1; id4[M] = nw;
	for(int i=M-1;i>=1;i--) {
		addedge(id2[i]<<1|1, nw);
		if( i == 1 ) break;
		id4[i] = (cnt++);
		addedge(id4[i], nw);
		addedge(id4[i], id2[i]<<1);
		nw = id4[i];
	}
	for(int i=1;i<=p;i++) {
		scanf("%d%d", &l[i], &r[i]);
		if( l[i] != 1 )
			addedge(id4[l[i]], id1[i]<<1), addedge(id1[i]<<1|1, id3[l[i]-1]);
		if( r[i] != M )
			addedge(id3[r[i]], id1[i]<<1), addedge(id1[i]<<1|1, id4[r[i]+1]);
	}
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(id1[u]<<1|1, id1[v]<<1);
		addedge(id1[v]<<1|1, id1[u]<<1);
	}
	for(int i=0;i<cnt;i++)
		if( !tid[i] ) dfs(i);
	for(int i=1;i<=p;i++)
		if( num[id1[i]<<1] == num[id1[i]<<1|1] ) {
			puts("-1");
			return 0;
		}
	for(int i=1;i<=M;i++)
		if( num[id2[i]<<1] == num[id2[i]<<1|1] ) {
			puts("-1");
			return 0;
		}
	solve();
	int res = 1;
	for(int i=1;i<=p;i++)
		if( !tag[num[id1[i]<<1|1]] )
			ans.push_back(i), res = max(res, l[i]);
	printf("%d %d\n", ans.size(), res);
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	puts("");
}