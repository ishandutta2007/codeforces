#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100009;

struct edge {
        int a, b, cost;
        void set(int aa, int bb, int cc) { a = aa; b = bb; cost = cc; }
        bool operator < (edge o) const { return cost < o.cost; }
} es[N << 2];
int en;

int S[N], sz[N];
int find(int i) {
        if(S[S[i]] != S[i]) S[i] = find(S[i]);
        return S[i];
}
void join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        S[b] = a;
}


int n, s, t, k;
int pos[N], mrk[N], dist[N];
vector<int> adj[N];
int bfs() {
        queue<int> q;
        memset(mrk, -1, sizeof mrk);
        for(int i = 0; i < k; i++)
                q.push(pos[i]), mrk[pos[i]] = i;
        while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : adj[u]) {
                        if(mrk[v] == -1) {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                                mrk[v] = mrk[u];
                        } else {
                                es[en++].set(mrk[v], mrk[u], dist[v] + dist[u] + 1);
                        }
                }
        }
        sort(es, es + en);
        for(int i = 0; i < en; i++) {
                edge &e = es[i];
                if(find(e.a) == find(e.b)) continue;
                join(e.a, e.b);
                if(find(0) == find(k - 1)) return e.cost;
        }
        return -1;
}

int main() {
        int i, m, u, v;
        scanf("%d %d %d", &n, &m, &k);
        for(i = 0; i < k; i++) {
                scanf("%d", &pos[i]); pos[i]--;
                S[i] = i; sz[i] = 1;
        }
        S[k] = i; sz[k] = 1;
        for(i = 0; i < m; i++) {
                scanf("%d %d", &u, &v);
                adj[--u].pb(--v);
                adj[v].pb(u);
        }
        scanf("%d %d", &s, &t);
        s--; t--;
        bool hast = false;
        for(i = 0; i < k; i++) {
                if(pos[i] == t) {
                        hast = true;
                        swap(pos[i], pos[k - 1]);
                }
                if(pos[i] == s)
                        swap(pos[i], pos[0]); // at s is always 0
        }
        if(!hast) pos[k++] = t;
        //at t is always k - 1
        printf("%d\n", bfs());
}