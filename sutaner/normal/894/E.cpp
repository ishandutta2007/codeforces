#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>
#define maxn 2000005
#define INF 2000000005
#define LL long long int
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int i = h2[x]; i; i = e2[i].next)
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0;
    while (!('0' <= ch && ch <= '9')) ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int pr[maxn];
int n, m, root;

struct edge{
    int next, to;
    LL num, len;
    edge(int next, int to, LL len, LL num) : next(next), to(to), len(len), num(num){}
    edge(int next, int to, LL len) : next(next), to(to), len(len){}
    edge(){}
}e[maxn << 1], e2[maxn << 1];
int h[maxn], h2[maxn], cnt = 1, cnt2 = 1;
void Add_Edge(int x, int y, LL z, LL k){
    e[++cnt] = edge(h[x], y, z, k);
    h[x] = cnt;
}
void Add_Edge2(int x, int y, LL z){
    e2[++cnt2] = edge(h2[x], y, z);
    h2[x] = cnt2;
}

int pre[maxn];
int low[maxn];
int scc[maxn];
int dfs[maxn];
bool vis[maxn];
LL sco[maxn];
int t = 0, ct = 0;
stack<int> s;

int Tarjan(int x){
    vis[x] = 1;
    low[x] = pre[x] = ++t;
    s.push(x);
    erep(i, x){
        int op = e[i].to;
        if (!vis[op]) low[x] = min(low[x], Tarjan(op));
        else if (!scc[op]) low[x] = min(low[x], low[op]);
    }
    if (low[x] == pre[x]){
        ct++;
        int k = s.top();
        s.pop();
        while (k != x){
            scc[k] = ct;
            k = s.top();
            s.pop();
        }
        scc[x] = ct;
    }
    return low[x];
}

bool vis2[maxn];
LL dp[maxn];
LL DP(int x){
    if (vis2[x]) return dp[x];
    vis2[x] = 1;
    LL& ans = dp[x];
    erep2(i, x){
        int op = e2[i].to;
        ans = max(ans, DP(op) + e2[i].len);
    }
    ans += sco[x];
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("mushroom.in", "r", stdin);
    #endif
    int len = 0;
    rep(i, 1, maxn - 1) {
        if (INF - pr[i - 1] < i) {
            len = i - 1;
            break;
        }
        pr[i] = pr[i - 1] + i;
    }
    int x, y;
    LL z;
    read(n), read(m);
    rep(i, 1, m) {
        read(x), read(y), read(z);
        LL k = upper_bound(pr, pr + len + 1, z) - pr - 1;
        k = (k + 1) * z - k * (k + 1) * (k + 2) / 6;
        Add_Edge(x, y, z, k);
    }
    rep(i, 1, n) if (!vis[i]) Tarjan(i);
    rep(i, 1, n){
        erep(j, i){
            int op = e[j].to;
            if (scc[op] == scc[i]) sco[scc[i]] += e[j].num;
            else Add_Edge2(scc[i], scc[op], e[j].len);
        }
    }
    read(root);
    printf("%I64d", DP(scc[root]));
    return 0;
}