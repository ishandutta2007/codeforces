#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
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
int belong[MAXN], block;
struct Query {
    int l, r, ID, lca, ans,L,R;
    bool operator < (const Query &rhs) const{
        return belong[l] == belong[rhs.l] ? belong[l]&1?r < rhs.r:r>rhs.r : belong[l] < belong[rhs.l];
    }
}q[MAXN];
vector<int>v[MAXN];
int a[MAXN];
int deep[MAXN], top[MAXN], fa[MAXN], siz[MAXN], son[MAXN], st[MAXN], ed[MAXN], pot[MAXN], tot;
void dfs1(int x, int _fa) {
    fa[x] = _fa; siz[x] = 1;
    st[x] = ++ tot; pot[tot] = x; 
    for(int i = 0; i < (int)v[x].size(); i++) {
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
    for(int i = 0; i < (int)v[x].size(); i++) {
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
        int x = read(), y = read(), L=read(),R=read();
        if(st[x] > st[y]) swap(x, y);
        int _lca = GetLca(x, y);
        q[i].ID = i;
        q[i].L=L,q[i].R=R;
        if(_lca == x) q[i].l = st[x], q[i]. r = st[y];
        else q[i].l = ed[x], q[i].r = st[y], q[i].lca = _lca;
    }
}
int out[MAXN], happen[MAXN];
namespace xay{
	const int N=300005,B=600;
	int bel[N],bl[N/B+5],br[N/B+5],bin[N],sum[N/B+5];
	void init(int n){
		rep(i,1,n){
			bel[i]=(i-1)/B+1;
			if(!bl[bel[i]])bl[bel[i]]=i;
			br[bel[i]]=i;
		}
	}
	void ps(int x){
		++bin[x];
		++sum[bel[x]];
	}
	void pop(int x){
		--bin[x];
		--sum[bel[x]];
	}
	int qry(int l,int r){
		if(bel[l]==bel[r]){
			rep(i,l,r)if(bin[i])return i;
			return -1;
		}
		rep(i,l,br[bel[l]])if(bin[i])return i;
		rep(i,bel[l]+1,bel[r]-1){
			if(sum[i]){
				rep(j,bl[i],br[i])if(bin[j])return j;
				assert(0);
			}
		}
		rep(i,bl[bel[r]],r)if(bin[i])return i;
		return -1;
	}
}
void add(int x) {
    if((happen[x]^=1)&1) xay::ps(x);
    else xay::pop(x);
}
void Add(int x) {
	add(a[x]);
}
void Mo() {
    sort(q + 1, q + Q + 1);
    int l = 1, r = 0;
    for(int i = 1; i <= Q; i++) {
        while(l < q[i].l) Add(pot[l]), l++;
        while(l > q[i].l) l--, Add(pot[l]);
        while(r < q[i].r) r++, Add(pot[r]);
        while(r > q[i].r) Add(pot[r]), r--;
        if(q[i].lca) Add(q[i].lca);
        q[i].ans = xay::qry(q[i].L,q[i].R);
        if(q[i].lca) Add(q[i].lca);
    }
    for(int i = 1; i <= Q; i++) out[q[i].ID] = q[i].ans;
    for(int i = 1; i <= Q; i++)
        printf("%d\n", out[i]);
}
int main() {
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
    N = read(); Q = read();
    block=600;
    for(int i = 1; i <= N; i++) a[i] = read();
    for(int i = 1; i <= N * 2; i++) belong[i] = i / block + 1;
    xay::init(N);
    for(int i = 1; i <= N - 1; i++) {
        int x = read(), y = read();
        v[x].push_back(y); v[y].push_back(x);
    }
    deep[1] = 1; dfs1(1, 0);
    dfs2(1, 1);
    DealAsk();
    Mo();
    return 0;
}