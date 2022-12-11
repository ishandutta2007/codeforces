#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1e3 + 7;
int par[N], sz[N];

int get_par(int v) {
    if (par[v] == v)
        return v;
    par[v] = get_par(par[v]);
    return par[v];
}

void merge(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (v == u)
        return;
    if (sz[v] < sz[u])
        swap(v, u);
    par[u] = v;
    sz[v] += sz[u];
}

signed main() {
//    freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        sz[i] = 1;
        par[i] = i;
    }
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        merge(x, y);
        vector <int> cmps;
        int musthave = 0;
        for (int j = 0; j < n; j++) {
            if (par[j] == j) {
                cmps.push_back(sz[j]);
                musthave += sz[j] - 1;
            }
        }
        int k = (i + 1) - musthave + 1;
        k = min(k, (int) cmps.size());
        nth_element(cmps.begin(), cmps.begin() + (k - 1), cmps.end(), greater <int>());
        int sm = 0;
        for (int j = 0; j < k; j++)
            sm += cmps[j];
        cout << sm - 1 << "\n";
    }
}