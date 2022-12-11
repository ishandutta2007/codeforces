#include <bits/stdc++.h>

using namespace std;

int cc = 0;

struct edge{
    int v, u, w, num;
    edge() {}
    void init() {
        cin >> v >> u >> w;
        num = cc++;
    }
};

bool cmp(edge a, edge b) {
    return (a.w < b.w);
}

const int N = 2e5 + 7, K = 10;
vector <edge> gout[N], gin[N];
int poss[N];
bool forbid[K][K][K][K];
int ok[K][K];
int has[N][K][K];
pair <int, int> kek[N];
int res = 0;
int cur[K];

void rec(int pos, int k) {
    //cout << pos << ' ' << k << endl;
    if (pos == k + 1) {
        /*for (int p1 = 1; p1 <= k; p1++) {
            for (int p2 = p1; p2 <= k; p2++) {
                if (forbid[p1][cur[p1]][p2][cur[p2]]) return;
            }
        }*/
        res++;
        return;
    }
    for (int i = 1; i <= pos; i++) {
        cur[pos] = i;
        //rec(pos + 1, k);
        if (ok[pos][i] > 0) continue;
        //cout << pos << ' '<< k << ' ' << i << endl;
        if (forbid[pos][i][pos][i]) continue;
        for (int j = pos + 1; j <= k; j++) {
            for (int v = 1; v <= j; v++) {
                if (forbid[pos][i][j][v]) ok[j][v]++;
            }
        }
        rec(pos + 1, k);
        for (int j = pos + 1; j <= k; j++) {
            for (int v = 1; v <= j; v++) {
                if (forbid[pos][i][j][v]) ok[j][v]--;
            }
        }
    }
}

signed main() {
    memset(forbid, 0, sizeof(forbid));
    memset(has, 0, sizeof(has));
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        edge e;
        e.init();
        gout[e.v].push_back(e);
        gin[e.u].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        sort(gout[i].begin(), gout[i].end(), cmp);
        for (int j = 0; j < (int) gout[i].size(); j++) {
            kek[gout[i][j].num] = {gout[i].size(), j + 1};
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 0; a < (int) gin[i].size(); a++) {
            auto aa = kek[gin[i][a].num];
            has[i][aa.first][aa.second]++;
        }
        for (int a = 1; a <= k; a++) {
            for (int b = 1; b <= k; b++) {
                for (int v = 1; v <= a; v++) {
                    for (int u = 1; u <= b; u++) {
                        if (has[i][a][v] && has[i][b][u]) {
                            if (a != b || v != u || has[i][a][v] >= 2) forbid[a][v][b][u] = forbid[b][u][a][v] = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            ok[i][j] = 0;
        }
    }
    rec(1, k);
    cout << res << endl;
}