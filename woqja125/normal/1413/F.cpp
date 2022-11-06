#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 500001;

int n;

vector<pair<int, int>> map[N];

pair<int, int> far(int x, int p) {
    pair<int, int> re(-1, x);
    for(auto [e, t]: map[x]) {
        if(e == p) continue;
        re = max(re, far(e, x));
    }
    return {re.first+1, re.second};
}

pair<int, int> emax(pair<int, int> x, pair<int, int> y) {
    return {max(x.first, y.first), max(x.second, y.second)};
}

pair<int, int> trans(pair<int, int> x) {
    return {x.second, x.first};
}

struct IT {
    pair<int, int> *a;
    bool *flip;
    int base;
    void init(int n, const int *v, const int *c) {
        for(base=1; base <= n; base*=2);
        a = new pair<int, int>[base*2+1]();
        flip = new bool[base*2+1]();
        for(int i=0; i<n; i++)
            if(c[i]) a[base+i].second = v[i];
            else a[base+i].first = v[i];
        for(int i=base-1; i>=1; i--)
            a[i] = emax(a[i*2], a[i*2+1]);
    }
    pair<int, int> upd_max(int x, int l, int r, int s, int e) {
        if(l <= s && e <= r) {
            flip[x] = !flip[x];
            return a[x] = trans(a[x]);
        }
        if(r < s || e < l) return a[x];
        int m = (s+e)/2;
        a[x] = emax(
            upd_max(x*2, l, r, s, m),
            upd_max(x*2+1, l, r, m+1, e)
        );
        if(flip[x]) a[x] = trans(a[x]);
        return a[x];
    }
    pair<int, int> upd_max(int x, int l, int r) { return upd_max(x, l, r, 0, base-1); }
};

struct P {
    int root;
    IT it;
    int nn[N];
    int end[N];
    int h[N];
    int c[N];
    int dT=-1;
    void dfs(int x, int p, int col) {
        nn[x] = ++dT;
        c[nn[x]] = col;
        if(p != -1) h[nn[x]] = h[nn[p]] + 1;
        for(auto [e, t]: map[x]) {
            if(e == p) continue;
            dfs(e, x, col^t);
        }
        end[x] = dT;
    }
    void init(int _root) {
        root = _root;
        h[root] = 0;
        dfs(root, -1, 0);
        it.init(n, h, c);
    }
    int Q(int x, int y) {
        if(h[nn[x]] < h[nn[y]]) x ^= y ^= x ^= y;
        return it.upd_max(1, nn[x], end[x]).first;
    }
} X, Y;

int e[N][2];

int main() {
    int x, y, m, t;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d%d", &x, &y, &t);
        map[x].emplace_back(y, t);
        map[y].emplace_back(x, t);
        e[i][0] = x; e[i][1] = y;
    }
    x = far(1, -1).second;
    y = far(x, -1).second;
    X.init(x); Y.init(y);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &t);
        printf("%d\n", max(X.Q(e[t][0], e[t][1]), Y.Q(e[t][0], e[t][1])));
    }
    return 0;
}