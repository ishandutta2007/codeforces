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

int adj[409][409];
int n;
int dist[409];
int bfs(int a) {
        queue<int> q;
        q.push(0);
        memset(dist, -1, sizeof dist);
        dist[0] = 0;
        while(!q.empty()) {
                int x = q.front(); q.pop();
                for(int i = 0; i < n; i++)
                        if(x != i && adj[x][i] == a && dist[i] == -1) {
                                if(i == n - 1) return dist[x] + 1;
                                dist[i] = dist[x] + 1;
                                q.push(i);
                        }
        }
        return -1;
}

int main() {
        int i, j, m, u, v;
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; i++) {
                scanf("%d %d", &u, &v); u--; v--;
                adj[u][v] = adj[v][u] = 1;
        }
        if(adj[0][n - 1])
                printf("%d\n", bfs(0));
        else
                printf("%d\n", bfs(1));
}