#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9 + 7;
const int INF = (1 << 30) - 1;
const int N = 605;

int n, m, u, v, w;
int d[N][N], dist[N];
bool visit[N];

int main() {
    cin >> n >> m;
    rep(i, 0, n - 1) rep(j, 0, n - 1) d[i][j] = INF;
    rep(i, 1, m) scanf("%d%d%d", &u, &v, &w), d[u][v] = w;

    rep(i, 0, n - 1) {
        int x;
        rep(j, 0, n - 1) dist[j] = d[i][j], visit[j] = false;

        rep(j, 2, n) {
            int mdist = INF;
            rep(k, 0, n - 1) if (!visit[k] && dist[k] < mdist) mdist = dist[k], x = k;
            visit[x] = true;

            rep(k, 0, n - 1) dist[(k + dist[x]) % n] = min(dist[(k + dist[x]) % n], dist[x] + d[x][k]);
            if (j > 1)
                dist[(x + 1) % n] = min(dist[(x + 1) % n], dist[x] + 1);
        }
        dist[i] = 0;
        rep(j, 0, n - 1) printf("%d%c", dist[j], j < n - 1 ? ' ' : '\n');
    }
    return 0;
}