#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include <iostream>
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
using namespace std;
const int MAXN = 6e5 + 10;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, Q;
int belong[MAXN];
const int block=567;
struct Query {
    int l, r, ID, lca, ans,x,y;
    bool operator < (const Query &rhs) const{
        return belong[l] == belong[rhs.l] ? ((belong[l]&1)^(r < rhs.r)) : belong[l] < belong[rhs.l];
    }
}q[MAXN];
vector<int>v[MAXN];
int a[MAXN], date[MAXN];
int deep[MAXN], top[MAXN], fa[MAXN], siz[MAXN], son[MAXN], st[MAXN], ed[MAXN], pot[MAXN], tot;
void dfs1(int x, int _fa) {
    fa[x] = _fa; siz[x] = 1;
    st[x] = ++ tot; pot[tot] = x; 
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if(deep[to]) continue;
        deep[to] = deep[x] + 1;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] = to;
    }
    ed[x] = ++tot; pot[tot] = x;
}
void dfs2(int x, int topfa) {
    top[x] = topfa;
    if(!son[x]) return ;
    dfs2(son[x], topfa);
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if(top[to]) continue;
            dfs2(to, to);
    }
}
int GetLca(int x, int y) {
    while(top[x] != top[y]) {
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
}
void DealAsk() {
    for(int i = 1; i <= Q; i++) {
        int x = read(), y = read(),l=read(),r=read();
        if(st[x] > st[y]) swap(x, y);
        int _lca = GetLca(x, y);
        q[i].ID = i;q[i].x=l,q[i].y=r;
        if(_lca == x) q[i].l = st[x], q[i]. r = st[y];
        else q[i].l = ed[x], q[i].r = st[y], q[i].lca = _lca;
    }
}
int Ans, out[MAXN], used[MAXN], happen[MAXN],cnt[MAXN],cntcnt[1000];
void add(int x) {
	if(cnt[x]) --cntcnt[x/block];
	else ++cntcnt[x/block];
	cnt[x]^=1;
}
void Add(int x) {
    add(a[x]),used[x] ^= 1;
}
inline int Query(int l,int r)
{
	for(int i=l/block+1;i<r/block;i++)
		if(cntcnt[i])for(int j=i*block;j<=r;j++)
			if(cnt[j]) return j;
	int qwq=l/block*block+block;
	for(int i=l;i<=min(qwq,r);i++)
		if(cnt[i]) return i;
	int X=r/block*block;
	for(int i=r;i>=max(X,l);i--)
		if(cnt[i]) return i;
	return -1;
}
void Mo() {
    sort(q + 1, q + Q + 1);
    int l = 1, r = 0;
    for(int i = 1; i <= Q; i++) {
        while(l > q[i].l) l--, Add(pot[l]);
        while(r < q[i].r) r++, Add(pot[r]);
        while(r > q[i].r) Add(pot[r]), r--;
        while(l < q[i].l) Add(pot[l]), l++;
        if(q[i].lca) Add(q[i].lca);
     //   cout << q[i].ID << " ";
        q[i].ans = Query(q[i].x,q[i].y);
       // puts("");
        if(q[i].lca) Add(q[i].lca);
    }
    for(int i = 1; i <= Q; i++) out[q[i].ID] = q[i].ans;
    for(int i = 1; i <= Q; i++)
        printf("%d\n", out[i]);
}
int main() {
    N = read(); Q = read();
    for(int i = 1; i <= N; i++) a[i] = read();
    for(int i = 1; i <= N * 2; i++) belong[i] = i / block + 1;
    for(int i = 1; i <= N - 1; i++) {
        int x = read(), y = read();
        v[x].push_back(y); v[y].push_back(x);
    }
    deep[1] = 1; dfs1(1, 0);
    dfs2(1, 1);
    DealAsk();
 //   for(int i=1;i<=N;i++) cout << a[i] << " ";
    Mo();
    return 0;
}