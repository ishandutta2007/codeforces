#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxm 605
#define maxn 400005
using namespace std;

int n, m, k;
char geo[maxm][maxm];

struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
    deg[x]++, deg[y]++;
}

bool vis[maxn];
void DFS(int x, int fa){
    if (vis[x] || geo[x / m][x % m] == '#') return;
    vis[x] = 1;
    if (fa != -1) Add_Edge(x, fa);
    int _x = x / m, _y = x % m;
    if (_x >= 1) DFS((_x - 1) * m + _y, x);
    if (_x <= n - 2) DFS((_x + 1) * m + _y, x);
    if (_y >= 1) DFS(_x * m + _y - 1, x);
    if (_y <= m - 2) DFS(_x * m + _y + 1, x);
}

queue<int> save;
void del(){
    rep(i, 0, n * m - 1) if (deg[i] == 1) save.push(i);
    while (!save.empty() && k--){
        int op = save.front(); save.pop();
        geo[op / m][op % m] = 'X';
        erep(i, op){
            int t = e[i].to;
            deg[t]--;
            if (deg[t] == 1) save.push(t);
        }
    }
    rep(i, 0, n - 1) printf("%s\n", geo[i]);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("377A.in", "r", stdin);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 0, n - 1) scanf("%s", geo[i]);
    rep(i, 0, n - 1) rep(j, 0, m - 1) {
        if (geo[i][j] == '.') {
            DFS(i * m + j, -1); 
            break;
        }
    }
    del();
    return 0;
}