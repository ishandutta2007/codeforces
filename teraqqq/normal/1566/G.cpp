#include <iostream>
#include <queue>
#include <random>
#include <map>

using namespace std;
using ll = long long;

const int N = 1e5+64, M = 1e5+7, Q = 1e5+7;
const ll LINF = 1e18;

struct Edge {
    int a, b, w;
} edges[M+Q];

int col[N], ing[M+Q];
ll ans[Q], g[4][4];

struct cmp {
    bool operator() (int i, int j) { return edges[i].w > edges[j].w; }
};

using pqe = priority_queue<int, vector<int>, cmp>; // priority queue for edges

void check(int i, array<array<pqe, 4>, 4>& gt) {
    for (int x = 0; x < 4; ++x) {
        for (int y = x; y < 4; ++y) {
            g[x][y] = min(gt[x][y].empty() ? LINF : edges[gt[x][y].top()].w,
                          gt[y][x].empty() ? LINF : edges[gt[y][x].top()].w);
        }
    }

    g[0][1] = min(g[0][1], min(g[0][2]+g[1][2], g[0][3]+g[1][3]));
    g[0][2] = min(g[0][2], min(g[0][1]+g[1][2], g[0][3]+g[2][3]));
    g[0][3] = min(g[0][3], min(g[0][1]+g[1][3], g[0][2]+g[2][3]));
    g[1][2] = min(g[1][2], min(g[0][1]+g[0][2], g[1][3]+g[2][3]));
    g[1][3] = min(g[1][3], min(g[0][1]+g[0][3], g[1][2]+g[2][3]));
    g[2][3] = min(g[2][3], min(g[0][2]+g[0][3], g[1][2]+g[1][3]));

    ans[i] = min(ans[i], min(g[0][1], min(g[0][0], g[1][1])) + min(g[2][3], min(g[2][2], g[3][3])));
    ans[i] = min(ans[i], g[0][0] + min(g[1][1], min(g[1][2], g[1][3])));    
    ans[i] = min(ans[i], g[2][2] + min(g[3][3], min(g[0][3], g[1][3])));
    ans[i] = min(ans[i], g[1][1] + min(g[0][2], g[0][3]));
    ans[i] = min(ans[i], g[3][3] + min(g[0][2], g[1][2]));
    ans[i] = min(ans[i], g[0][2] + g[1][3]);
    ans[i] = min(ans[i], g[0][3] + g[1][2]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    map<pair<int, int>, int> id;

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        if (edges[i].a > edges[i].b) swap(edges[i].a, edges[i].b);
        id[{edges[i].a, edges[i].b}] = i;
    }

    int q; cin >> q;
    fill(ans, ans+q+1, LINF);
    for (int t = 0; t < q; ++t) {
        const int i = t + m;
        int typ; cin >> typ >> edges[i].a >> edges[i].b;
        if (edges[i].a > edges[i].b) swap(edges[i].a, edges[i].b);
        
        if (typ == 0) {
            edges[i].w = -id[{edges[i].a, edges[i].b}];
        } else {
            cin >> edges[i].w;
            id[{edges[i].a, edges[i].b}] = i;
        }
    }

    mt19937 rng(1337228);
    for (int iter = 50; iter--; ) {
        array<array<pqe, 4>, 4> gq;

        for (int i = 1; i <= n; i += 8) {
            uint32_t x = rng();
            for (int j = 8; j--; x >>= 2)
                col[i+j] = x & 3;
        }

        fill(ing, ing+m+q, true);
        
        for (int i = 0; i < m; ++i) {
            gq[col[edges[i].a]][col[edges[i].b]].push(i);
        }

        check(0, gq);
        for (int t = 0; t < q; ++t) {
            const int i = t + m;
            if (edges[i].w > 0) {
                gq[col[edges[i].a]][col[edges[i].b]].push(i);
            } else {
                ing[-edges[i].w] = false;
                const int a = col[edges[i].a], b = col[edges[i].b];
                while (!gq[a][b].empty() && !ing[gq[a][b].top()]) gq[a][b].pop();
            }

            check(t+1, gq);
        }
    }

    for (int i = 0; i <= q; ++i) {
        cout << ans[i] << endl;
    }
}