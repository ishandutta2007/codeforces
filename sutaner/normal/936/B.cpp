#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cassert>
#include <vector>
#define maxn 600005 
#define pb push_back
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

int n, m, s;

struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
    deg[x]++;
}


vector<int> go[maxn];
queue<int> q;
bool vis[maxn];
int sta[maxn];
int p[maxn];
//bool vis2[maxn];

/*void DFS(int x, int d){
    vis2[x] = 1;
    printf("%d ", (x > n) ? (x - n) : x);
    int siz = go[x].size();
    rep(i, 0, siz - 1) {
        int op = go[x][i];
        if (vis2[op]) continue;
        if ((d && sta[op] == 1) || (!d && !sta[op])) {
            DFS(op, d ^ 1);
            return;
        }
    }
    //assert(false);
}*/

void topo(){
    rep(i, 1, n << 1) if (!deg[i]) vis[i] = 1, q.push(i);
    while (!q.empty()){
        int x = q.front(); q.pop();
        if (x > n){
            if (!sta[x]){
                erep(i, x){
                    int op = e[i].to;
                    //if (vis[op] && !sta[op]) assert(false);
                    if (vis[op]) continue;
                    p[op] = x;
                    vis[op] = sta[op] = 1;
                    q.push(op);
                }
            }
            else {
                erep(i, x){
                    int op = e[i].to;
                    if (vis[op]) continue;
                    deg[op]--;
                    if (!deg[op]){
                        vis[op] = 1;
                        q.push(op);
                    }
                }
            }
        }
        else {
            if (sta[x]){
                erep(i, x){
                    int op = e[i].to;
                    //if (vis[op] && !sta[op]) assert(false);
                    if (vis[op]) continue;
                    vis[op] = 1;
                    p[op] = x;
                    assert(!sta[op]);
                    q.push(op);
                }
            }
            else {
                erep(i, x){
                    int op = e[i].to;
                    if (vis[op]) continue;
                    deg[op]--;
                    if (!deg[op]){
                        sta[op] = 1, vis[op] = 1;
                        q.push(op);
                    }
                }
            }
        }
    }
    rep(i, 1, n << 1) if (!vis[i]) sta[i] = -1;
    if (!sta[s]) printf("Lose");
    else if (sta[s] == -1) printf("Draw");
    else {
        printf("Win\n");
        int now = s;
        while (now) printf("%d ", (now > n) ? now - n : now), now = p[now];
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("game.in", "r", stdin);
    #endif
    int x, y;
    read(n), read(m);
    rep(i, 1, n){
        read(x);
        rep(j, 1, x) read(y), go[i].pb(y + n), go[i + n].pb(y), Add_Edge(i + n, y), Add_Edge(i, y + n);
    }
    read(s);
    topo();
    return 0;
}