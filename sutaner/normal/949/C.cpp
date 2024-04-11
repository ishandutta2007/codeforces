#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#define pii pair<int, int> 
#define fi first
#define se second
#define pb push_back
#define maxn 200005
#define maxm 300005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    if (!f) x = -x;
}

int n, m, ho;
int ti[maxn];
map<pii, int> s;

struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxm << 1];
int h[maxn], cnt = 0;
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
}

int pre[maxn];
int low[maxn];
bool vis[maxn];
int scc[maxn];
int ct = 0, t = 0;
stack<int> sa;
int Tarjan(int x){
    vis[x] = 1;
    pre[x] = low[x] = ++t;
    sa.push(x);
    erep(i, x){
        int op = e[i].to;
        if (!vis[op]) low[x] = min(low[x], Tarjan(op));
        else if (!scc[op]) low[x] = min(low[x], low[op]);
    }
    if (low[x] == pre[x]){
        scc[x] = ++ct;
        int op = sa.top(); sa.pop();
        while (op != x){
            scc[op] = ct;
            op = sa.top(); sa.pop();
        }
    }
    return low[x];
}

int siz[maxn];
vector<int> go[maxn];
bool out[maxn];

void Get(){
    rep(i, 1, n){
        int x = scc[i];
        siz[x]++;
        erep(j, i){
            int op = e[j].to;
            if (scc[op] != x) out[x] = 1;//go[x].pb(scc[op]);
        }
    }
}

/*int dp[maxn];
bool vis2[maxn];
int DP(int x){
    if (vis2[x]) return dp[x];
    vis2[x] = 1;
    int& ans = dp[x];
    int size = go[x].size();
    rep(i, 0, size - 1){
        int op = go[x][i];
        ans += DP(op);
    }
    ans += siz[x];
    return ans;
}*/

int main(){
    #ifndef ONLINE_JUDGE
        freopen("C.in", "r", stdin);
    #endif
    read(n), read(m), read(ho);
    int x, y;
    rep(i, 1, n) read(ti[i]);
    rep(i, 1, m){
        read(x), read(y);
        if ((ti[x] + 1) % ho == ti[y] && !s.count(pii(x, y))) {
            s[pii(x, y)] = 1;
            Add_Edge(x, y);
        }
        if ((ti[y] + 1) % ho == ti[x] && !s.count(pii(y, x))) {
            s[pii(y, x)] = 1;
            Add_Edge(y, x);
        }
    }
    rep(i, 1, n) if (!vis[i]) Tarjan(i); 
    Get();
    int ans = n + 1;
    /*rep(i, 1, ct) ans = min(ans, DP(i));
    rep(i, 1, ct){
        if (DP(i) == ans){
            printf("%d\n", siz[i]);
            rep(j, 1, n){
                if (scc[j] == i) printf("%d ", j);
            }
        }
    }*/
    rep(i, 1, ct) {
        if (out[i]) continue;
        ans = min(ans, siz[i]);
    }
    rep(i, 1, ct){
        if (out[i]) continue;
        if (siz[i] == ans){
            printf("%d\n", siz[i]);
            rep(j, 1, n){
                if (scc[j] == i) printf("%d ", j);
            }
            return 0;
        }
    }
    /*rep(i, 1, n){
        if (!vis[i]){
            printf("%d\n%d", 1, i);
            return 0;
        }
    }
    printf("%d\n", n);
    rep(i, 1, n) printf("%d ", i);*/
    return 0;
}