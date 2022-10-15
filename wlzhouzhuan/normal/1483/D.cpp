// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const ll inf = 1e15;
const int N = 605;

vector<pii> tag[N];
ll dis[N][N], maxx[N];
int E[N][N];
int n, m, q, ans;

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        E[u][v] = E[v][u] = w;
        dis[u][v] = dis[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    q = read();
    for (int i = 1; i <= q; i++) {
        int u = read(), v = read(), l = read();
        tag[u].pb({v, l});
        tag[v].pb({u, l});
    }
    // u -> x -> y -> v
    for (int y = 1; y <= n; y++) {
        for (int u = 1; u <= n; u++) {
            maxx[u] = -inf;
            for (auto it: tag[u]) {
                int v = it.fir, len = it.sec;
                maxx[u] = max(maxx[u], len - dis[v][y]); 
            }
        }
        for (int x = y + 1; x <= n; x++) {
            if (!E[x][y]) continue;
            for (int u = 1; u <= n; u++) {
                if (dis[u][x] + E[x][y] <= maxx[u]) {
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}