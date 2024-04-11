#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

struct Dsu {
    vector<int> p;

    Dsu (int n) : p(n) {
        iota(p.begin(), p.end(), 0);
    }

    int root(int v) {
        return v == p[v] ? v : p[v] = root(p[v]);
    }

    void unite(int a, int b) {
        p[root(b)] = root(a);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int& x : p) cin >> x;

    vector<int> gR(n), gL(n), lR(n), lL(n);

    for (int i = 0; i < n; ++i) {
        gL[i] = i - 1;
        while (gL[i] != -1 && p[gL[i]] < p[i]) gL[i] = gL[gL[i]];
        lL[i] = i - 1;
        while (lL[i] != -1 && p[lL[i]] > p[i]) lL[i] = lL[lL[i]];
    }

    for (int i = n; i--; ) {
        gR[i] = i + 1;
        while (gR[i] != n && p[gR[i]] < p[i]) gR[i] = gR[gR[i]];
        lR[i] = i + 1;
        while (lR[i] != n && p[lR[i]] > p[i]) lR[i] = lR[lR[i]];
    }

    Dsu dgL(n), dgR(n), dlL(n), dlR(n);

    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    auto update_dist = [&] (int v, int bound, const vector<int>& p, Dsu& dsu) {
        int vl, vr;
        if (bound > v) {
            vl = v - 1;
            vr = bound;
        } else {
            vr = v + 1;
            vl = bound;
        }

        for (int u = v; vl < u && u < vr; u = p[u]) {
            u = dsu.root(u);
            if (vl < u && u < vr) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
                if (p[u] != -1 && p[u] != n) dsu.unite(p[u], u);
            }
        }
    };

    while (!q.empty()) {
        int v = q.front(); q.pop();
        update_dist(v, gR[v], lR, dlR);
        update_dist(v, gL[v], lL, dlL);
        update_dist(v, lR[v], gR, dgR);
        update_dist(v, lL[v], gL, dgL);
    }

    cout << dist.back() << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}