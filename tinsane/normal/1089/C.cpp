#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int N = 505;
const int INF = (int)1e9;

int n, m;
bool edge[N][N];
int dist[N][N];

int ask(int v) {
    printf("%d\n", v + 1);
    fflush(stdout);
    char buf[10];
    scanf("%s", buf);
    if (strcmp(buf, "FOUND") == 0) {
        return -1;
    }
    int to;
    scanf("%d", &to);
    return to - 1;
}

int calc(const vector<int>& my_set, int me, int nei) {
    int cnt = 0;
    for (int x : my_set) {
        cnt += dist[me][x] > dist[nei][x];
    }
    return cnt;
}

void solve() {
    vector<int> my_set;
    for (int i = 0; i < n; ++i) {
        my_set.push_back(i);
    }

    while (true) {
        int best_v = -1, minima = INF;
        for (int v : my_set) {
            int maxima = -INF;
            for (int to : my_set) {
                if (!edge[v][to]) {
                    continue;
                }
                maxima = max(maxima, calc(my_set, v, to));
            }
            if (minima > maxima) {
                minima = maxima;
                best_v = v;
            }
        }

        int resp = ask(best_v);
        if (resp == -1) {
            break;
        }

        vector<int> new_set;
        for (int to : my_set) {
            if (dist[best_v][to] > dist[resp][to]) {
                new_set.push_back(to);
            }
        }
        swap(my_set, new_set);
    }
}

int main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        int prv = -1;
        while (k--) {
            int x;
            scanf("%d", &x);
            --x;
            if (prv != -1 && prv != x) {
                dist[prv][x] = dist[x][prv] = 1;
                edge[prv][x] = edge[x][prv] = true;
            }
            prv = x;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        solve();
    }

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}