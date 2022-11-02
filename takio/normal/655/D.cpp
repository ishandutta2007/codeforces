#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100;

int n, m, u[N], v[N], in[N];
vector <int> g[N];

int jug (int k) {
    for (int i = 1; i <= n; i++) g[i].clear();
    memset (in, 0, sizeof in);
    for (int i = 1; i <= k; i++) {
        g[u[i]].push_back (v[i]);
        in[v[i]] ++;
    }
    queue <int> q;
    for (int i = 1; i <= n; i++) if (in[i] == 0) {
        q.push (i);
    }
    if (q.size() != 1) return 0;
    int cnt = 0;
    while (!q.empty()) {
        if (q.size() != 1) return 0;
        cnt++;
        int u = q.front();
        q.pop();
        for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            in[v] --;
            if (!in[v]) q.push (v);
        }
    }
    return cnt == n;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u[i], &v[i]);
    }
    int l = 0, r = m;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (jug (mid)) r = mid;
        else l = mid;
    }
    if (jug (r)) cout << r;
    else cout << -1;
}