#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int inf = 1e12 + 10;

struct line {
    int k, b;
    line() = default;
    line(int k, int b) : k(k), b(b) {};
    int get(int x) const {
        return k * x + b;
    }
    int intersect(line l) const {
        return (l.b - b) / (k - l.k);
    }
};

struct CHT {
    vector<int> pts;
    vector<line> lines;
    int ptr = 0;

    void add_line(line l) {
        while (!lines.empty() && l.get(pts.back()) < lines.back().get(pts.back())) {
            pts.pop_back();
            lines.pop_back();
        }
        int c = lines.empty() ? -inf : l.intersect(lines.back());
        pts.push_back(c);
        lines.push_back(l);
    }

    int get(int x) {
        while (ptr + 1 < pts.size() && pts[ptr + 1] <= x) {
            ptr++;
        }
        return lines[ptr].get(x);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    vector<vector<int>> d(k + 1, vector<int>(n, inf));
    d[0][0] = 0;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.insert({d[0][i], i});
    }
    while (!st.empty()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto [u, w] : g[v]) {
            if (d[0][v] + w < d[0][u]) {
                st.erase({d[0][u], u});
                d[0][u] = d[0][v] + w;
                st.insert({d[0][u],u });
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout << d[0][i] << ' ';
    }
    cout << '\n';*/
    for (int iter = 1; iter <= k; iter++) {
        CHT musorka;
        for (int i = n - 1; i >= 0; i--) {
            musorka.add_line(line(i, d[iter - 1][i] + i * i));
        }
        /*cout << "debug begins:\n";
        for (auto it : musorka.pts) {
            cout << it << ' ';
        }
        cout << '\n';
        for (auto it : musorka.lines) {
            cout << it.k << ' ' << it.b << '\n';
        }*/
        //cout << "debug ends\n";
        for (int i = n - 1; i >= 0; i--) {
            d[iter][i] = i * i + musorka.get(-2 * i);
            //cout << d[iter][i] << ' ';
            //cout << i << ' ' << musorka.ptr << '\n';
        }
        //cout << '\n';
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            st.insert({d[iter][i], i});
        }
        while (!st.empty()) {
            int v = st.begin()->second;
            st.erase(st.begin());
            for (auto [u, w] : g[v]) {
                if (d[iter][v] + w < d[iter][u]) {
                    st.erase({d[iter][u], u});
                    d[iter][u] = d[iter][v] + w;
                    st.insert({d[iter][u],u });
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[k][i] << ' ';
    }
    cout << '\n';
    return 0;
}