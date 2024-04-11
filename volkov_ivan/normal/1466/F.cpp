#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7, M = 1e9 + 7;
int sz[N];
int par[N];
bool good[N];
int pow2[N];

int get_par(int v) {
    if (par[v] == v)
        return v;
    par[v] = get_par(par[v]);
    return par[v];
}

bool merge(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (v == u)
        return 0;
    if (sz[v] > sz[u])
        swap(v, u);
    par[v] = u;
    sz[u] += sz[v];
    bool res = 1;
    if (good[v] && good[u])
        res = 0;
    good[u] |= good[v];
    return res;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pow2[0] = 1;
    for (int i = 1; i < N; i++)
        pow2[i] = (pow2[i - 1] * 2) % M;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        good[i] = 0;
        par[i] = i;
        sz[i] = 1;
    }
    vector <int> basis;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int v;
            cin >> v;
            v = get_par(v);
            if (!good[v]) {
                basis.push_back(i + 1);
                good[v] = 1;
            }
        } else {
            int v, u;
            cin >> v >> u;
            if (merge(v, u))
                basis.push_back(i + 1);
        }
    }
    int log = 0;
    for (int i = 1; i <= m; i++) {
        if (par[i] == i) {
            if (good[i])
                log += sz[i];
            else
                log += sz[i] - 1;
        }
    }
    cout << pow2[log] << ' ' << basis.size() << endl;
    for (int elem : basis) {
        cout << elem << ' ';
    }
    cout << endl;
}