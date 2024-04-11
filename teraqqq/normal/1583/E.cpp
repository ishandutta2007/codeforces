#include <bits/stdc++.h>

using namespace std;
using ll = long  long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

struct Dsu {
    vi p, c;

    Dsu(int n) : p(n), c(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int get_root(int v) {
        return p[v] == v ? v : p[v] = get_root(p[v]);
    }

    bool unite(int a, int b) {
        a = get_root(a); b = get_root(b);
        if (a != b) {
            if (c[a] < c[b]) swap(a, b);
            p[b] = a;
            c[a] += c[b];
            return true;
        } else {
            return false;
        }
    }
};

const int N = 3e5+7;

int n, m, in_st[N], ea[N], eb[N], x[N], used[N], tin[N], tout[N], gt, par[N];
vector<int> st, g[N], t[N];

void dfs(int v, int p = -1) {
    par[v] = p;
    tin[v] = gt++;
    for (int to : g[v]) {
        if (to != p) dfs(to, v);
    }
    tout[v] = gt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    Dsu dsu(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        if (dsu.unite(a, b)) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> ea[i] >> eb[i]; ea[i]--, eb[i]--;
        t[ea[i]].push_back(i);
        t[eb[i]].push_back(i);
        x[i] = ea[i] ^ eb[i];
    }

    int bad_count = 0;
    for (int i = 0; i < n; ++i) bad_count += t[i].size() % 2;

    if (bad_count != 0) {
        cout << "NO" << endl;
        cout << bad_count / 2 << endl;
        return 0;
    }


    dfs(0);
    cout << "YES" << endl;
    for (int i = 0; i < q; ++i) {
        int a = ea[i], b = eb[i];

        vector<int> pa, pb;
        while (a != b) {
            if (tin[b] < tin[a] || tout[b] > tout[a]) {
                pa.push_back(a);
                a = par[a];
            } else if (tin[a] < tin[b] || tout[a] > tout[b]) {
                pb.push_back(b);
                b = par[b];
            }
        }

        pa.push_back(a);
        while (!pb.empty()) pa.push_back(pb.back()), pb.pop_back();

        cout << pa.size() << '\n';
        for (int x : pa) cout << x+1 << ' ';
        cout << '\n';
    }
}