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

const int N = 10;

int n;
bool go[N][N];
int repr[N];
bool used[N];
vector<vector<int>> planes;
bool meta_go[N][N];
vector<int> topo;
int dim0, dim1, dim2;
vector<vector<string>> brd;

void dfs_topo(int v) {
    used[v] = true;
    for (int to = 0; to < (int)planes.size(); ++to) {
        if (used[to] || !meta_go[v][to]) {
            continue;
        }
        dfs_topo(to);
    }
    topo.push_back(v);
}

void build_graph() {
    for (int i = 0; i < n; ++i) {
        go[i][i] = true;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                go[i][j] |= go[i][k] && go[k][j];
            }
        }
    }

    memset(repr, -1, sizeof(repr));
    for (int i = 0; i < n; ++i) {
        if (repr[i] != -1) {
            continue;
        }
        repr[i] = (int)planes.size();
        vector<int> plane;
        for (int j = 0; j < n; ++j) {
            if (go[i][j] && go[j][i]) {
                plane.push_back(j);
            }
        }
        for (int v : plane) {
            repr[v] = repr[i];
        }
        planes.push_back(plane);
    }

    for (int v = 0; v < (int)planes.size(); ++v) {
        for (int x : planes[v]) {
            for (int to = 0; to < n; ++to) {
                meta_go[v][repr[to]] |= go[x][to];
            }
        }
    }

    for (int meta_v = 0; meta_v < (int)planes.size(); ++meta_v) {
        if (used[meta_v]) {
            continue;
        }
        dfs_topo(meta_v);
    }
    reverse(topo.begin(), topo.end());


}

void draw_tunnel(int z1, int z2, int x, int y) {
    for (int i = z1 + 1; i < z2; ++i) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                brd[2 * i][x + dx][y + dy] = '#';
            }
        }
    }
    for (int i = z1; i < z2; ++i) {
        brd[2 * i + 1][x][y] = '.';
    }
}

void draw() {
    for (int i = 0; i < (int)planes.size(); ++i) {
        for (int x = 0; x < dim1; ++x) {
            for (int y = 0; y < dim2; ++y) {
                brd[2 * i + 1][x][y] = '#';
            }
        }
    }

    int shift = 0;
    for (int i = 0; i < (int)planes.size(); ++i) {
        const auto& plane = planes[topo[i]];
        for (int idx = 0; idx < (int)plane.size(); ++idx) {
            brd[2 * i][3 * i][shift + idx] = '0' + plane[idx] + 1;
        }

        shift += (int)plane.size();
        for (int j = i + 1; j < (int)planes.size(); ++j) {
            if (meta_go[topo[i]][topo[j]]) {
                draw_tunnel(i, j, 3 * i + 1, shift + 3 * j + 1);
            }
        }
        shift += 3 * (int)planes.size();
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            go[i][j] = x;
        }
    }

    build_graph();

    dim0 = 2 * (int)planes.size();
    dim1 = 3 * (int)planes.size();
    dim2 = n + 3 * (int)planes.size() * (int)planes.size();
    brd.resize(dim0, vector<string>(dim1, string(dim2, '.')));
    draw();

    printf("%d %d %d\n", dim2, dim1, dim0);
    for (int i = 0; i < dim0; ++i) {
        for (int x = 0; x < dim1; ++x) {
            puts(brd[i][x].c_str());
        }
        printf("\n");
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}