#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;
using pi = pair<int, int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

struct SkipList {
    int n;
    vector<int> p, c, r;

    SkipList(int n) : n(n), p(n), c(n, 1), r(n) {
        iota(p.begin(), p.end(), 0);
        iota(r.begin(), r.end(), 1);
    }

    int get_root(int v) {
        return v == p[v] ? v : p[v] = get_root(p[v]);
    }

    void unite(int a, int b) {
        a = get_root(a);
        b = get_root(b);
        if (a != b) {
            if (c[a] < c[b]) swap(a, b);
            r[a] = max(r[a], r[b]);
            p[b] = a;
            c[a] += c[b];
        }
    }

    int next(int i) {
        return r[get_root(i)];
    }

    void remove(int i) {
        if (i != 0) unite(i-1, i);
    }
};

struct Dsu {
    int n, m;
    vector<int> p, c;
    vector<int> ax, ay, bx, by;

    Dsu(int n, int m) : n(n), m(m), p(n*m), c(n*m, 1),
        ax(n*m), ay(n*m), bx(n*m), by(n*m) {
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            const int t = j + i * m;
            ax[t] = bx[t] = i;
            ay[t] = by[t] = j;
        }
    }

    int get_root(int v) {
        return v == p[v] ? v : p[v] = get_root(p[v]);
    }

    void unite(int nx, int ny, int mx, int my) {
        int a = get_root(nx * m + ny);
        int b = get_root(mx * m + my);
        if (a != b) {
            if (c[a] < c[b]) swap(a, b);

            ax[a] = min(ax[a], ax[b]);
            ay[a] = min(ay[a], ay[b]);
            bx[a] = max(bx[a], bx[b]);
            by[a] = max(by[a], by[b]);

            p[b] = a;
            c[a] += c[b];
        }
    }
};

const int N = 2000;

int n, m;

string s[N];

void paint(Dsu& dsu, vector<SkipList>& row, int ax, int ay, int bx, int by) {
    // cout << "Paint " << ax << " " << ay << " " << bx << " " << by << endl;
    for (int i = ax; i <= bx; ++i) {
        for (int j = ay; j <= by; j = row[i].next(j)) {
            if (j != 0 && s[i][j-1] == '.') dsu.unite(i, j-1, i, j);
            if (j < m-1  && s[i][j+1] == '.') dsu.unite(i, j+1, i, j);
            if (i != 0 && s[i-1][j] == '.') dsu.unite(i-1, j, i, j);
            if (i < n-1  && s[i+1][j] == '.') dsu.unite(i+1, j, i, j);
            s[i][j] = '.';
            row[i].remove(j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    Dsu dsu(n, m);
    vector row(n, SkipList(m));
    for (int i = 0; i < n; ++i) cin >> s[i];
    
    queue<pi> q;
    for (int i = 0; i < n; ++i) 
    for (int j = 0; j < m; ++j) {
        if (s[i][j] == '*') continue;
        if (i && s[i-1][j] == '.') dsu.unite(i, j, i-1, j);
        if (j && s[i][j-1] == '.') dsu.unite(i, j, i, j-1);
    }

    for (int i = 0; i < n; ++i) 
    for (int j = 0; j < m; ++j) {
        const int t = i * m + j;
        if(dsu.p[t] == t && s[i][j] == '.') {  
            // cout << "One room " << i << " " << j << endl;
            q.emplace(t, dsu.c[t]);
        }
    }

    while (!q.empty()) {
        auto [t, c_check] = q.front(); q.pop();
        if (dsu.p[t] != t || dsu.c[t] != c_check) continue;
        const int cx = t / m, cy = t % m;

        // cout << "Got room " << cx << " " << cy <<  endl;

        int nx = -1, ny = -1, mx = -1, my = -1;

        while (true) {
            t = dsu.get_root(t);
            const int ax = dsu.ax[t], bx = dsu.bx[t], ay = dsu.ay[t], by = dsu.by[t];
            // cout << ax <<":" << ay << " " << bx << ":" << by << endl;
            if (ay == ny && by == my) {
                if (ax == nx && bx == mx) break;
                if (ax != nx) paint(dsu, row, ax, ay, nx-1, by);
                if (bx != mx) paint(dsu, row, mx+1, ay, bx, by);
            } else {
                paint(dsu, row, ax, ay, bx, by);
            }
            nx = ax, ny = ay, mx = bx, my = by;
        }
    }

    for (int i = 0; i < n; ++i) cout << s[i] << endl;
}