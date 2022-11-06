#include <bits/stdc++.h>

using namespace std;

typedef int LL;
typedef pair<int,int> pii;

vector<pii>e[610];
int n, m;
LL ans[610][610];
LL d[610], newd[610];
bool vis[610];
const LL INF = 1e9 + 1e5;

void upd(LL &x, LL y) {
    x = min(x, y);
}

void update_newd() {
    for (int i = 0; i < n; i++) {
        upd(newd[i], newd[(i - 1 + n) % n] + 1);
    }
}

void solve(int s) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        vis[i] = false;
    }
    d[s] = 0;
    for (int round = 0; round < n; round++) {
        int mi = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (mi == -1 || d[i] < d[mi])) {
                mi = i;
            }
        }
        vis[mi] = true;
        for (int i = 0; i < n; i++) newd[i] = INF;
        for (auto &t : e[mi]) {
            upd(newd[(t.first + d[mi]) % n], d[mi] + t.second);
        }
        update_newd(); update_newd();
        for (int i = 0; i < n; i++) upd(d[i], newd[i]);
    }
    for (int i = 0; i < n; i++) {
        ans[s][i] = d[i];
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d",&u, &v, &w);
        e[u].push_back(pii(v, w));
    }
    for (int i = 0; i < n; i++) {
        solve(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c",ans[i][j]," \n"[j==n-1]);
        }
    }
}