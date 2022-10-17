#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct lctree {
    int n;
    vector<int> f, r;
    vector<vector<int>> ch;
    vector<int> a, mn, sz, sum, type, add;
    vector<int> lc, rc;
    lctree(int n): n(n), r(n), f(n, -1), ch(n, vector<int>(2, -1)) {
        a.resize(n);
        mn.resize(n);
        sz.resize(n);
        lc.resize(n);
        rc.resize(n);
        sum.resize(n);
        add.resize(n);
        type.resize(n);
        fill(add.begin(), add.end(), -1);
    }
    void pushup(int x) {
        sum[x] = a[x] & type[x], mn[x] = x, sz[x] = type[x];
        if(ch[x][0] != -1) sum[x] += sum[ch[x][0]], mn[x] = min(mn[x], mn[ch[x][0]]), sz[x] += sz[ch[x][0]];
        if(ch[x][1] != -1) sum[x] += sum[ch[x][1]], mn[x] = min(mn[x], mn[ch[x][1]]), sz[x] += sz[ch[x][1]];
    }
    int isroot(int x) {
        if(f[x] == -1) return 1;
        return ch[f[x]][0] != x && ch[f[x]][1] != x;
    }
    void rev(int x) {
        swap(ch[x][0], ch[x][1]);
        r[x] ^= 1;
    }
    void pushdown(int x) {
        if(r[x]) {
            if(ch[x][0] != -1) rev(ch[x][0]);
            if(ch[x][1] != -1) rev(ch[x][1]);
            r[x] = 0;
        }
        if(add[x] != -1) {
            if(ch[x][0] != -1) a[ch[x][0]] = add[x], add[ch[x][0]] = add[x], sum[ch[x][0]] = add[x] * sz[ch[x][0]];
            if(ch[x][1] != -1) a[ch[x][1]] = add[x], add[ch[x][1]] = add[x], sum[ch[x][1]] = add[x] * sz[ch[x][1]];
            add[x] = -1;
        }
    }
    void rotate(int x) {
        int y = f[x], z = f[y], k = ch[y][1] == x, w = ch[x][k ^ 1];
        if(isroot(y) == 0) ch[z][ch[z][1] == y] = x;
        if(w != -1) f[w] = y;
        f[x] = z; f[y] = x; ch[x][k ^ 1] = y; ch[y][k] = w;
        pushup(y);
    }
    void splay(int x) {
        function<void(int)> cleartag = [&](int x) {
            if(isroot(x) == 0) cleartag(f[x]);
            pushdown(x);
        };
        cleartag(x);
        while(isroot(x) == 0) {
            int y = f[x], z = f[y];
            if(isroot(y) == 0) rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
            rotate(x);
        }
        pushup(x);
    }
    void access(int x) {
        for(int y = -1; x != -1; y = x, x = f[x]) {
            splay(x);
            ch[x][1] = y;
            pushup(x);
        }
    }
    void makeroot(int x) {
        access(x);
        splay(x);
        rev(x);
    }
    int findroot(int x) {
        access(x);
        splay(x);
        while(ch[x][0] != -1) {
            pushdown(x);
            x = ch[x][0];
        }
        splay(x);
        return x;
    }
    void split(int x, int y) {
        makeroot(x);
        access(y);
        splay(y);
    }
    int link(int x, int y, int m) {
        lc[m] = x, rc[m] = y;
        makeroot(x);
        if(findroot(y) != x) {
            splay(y);
            assert(f[x] == -1);
            assert(f[m] == -1);
            f[x] = m;
            f[m] = y;
            return 1;
        }
        assert(f[x] == -1);
        if(sum[x]) return 0;
        int p = mn[x];
        splay(p);
        assert(f[p] == -1 && ch[p][0] != -1 && ch[p][1] != -1);
        f[ch[p][0]] = f[ch[p][1]] = -1;
        ch[p][0] = ch[p][1] = -1;
        makeroot(y);
        assert(f[y] == -1);
        splay(x);
        assert(f[x] == -1);
        f[y] = m;
        f[m] = x;
        split(lc[p], rc[p]);
        add[rc[p]] = 1, a[rc[p]] = 1, sum[rc[p]] = add[rc[p]] * sz[rc[p]];
        return 1;
    }
    void cut(int x, int y, int m) {
        split(x, y);
        add[y] = 0, a[y] = 0, sum[y] = 0;
        splay(y);
        if(findroot(m) == x) {
            access(y);
            splay(m);
            f[ch[m][0]] = f[ch[m][1]] = -1;
            ch[m][0] = ch[m][1] = -1;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    lctree lc(n + m);
    vector<pair<int,int>> a(m);
    for(int i = 0; i < m; ++i) lc.type[i] = 1;
    for(auto &[u, v] : a) {
        cin >> u >> v;
        --u, --v;
        u += m, v += m;
    }
    int j = 0;
    ll ans = 0;
    for(int i = 0; i < m; ++i) {
        while(j < m && lc.link(a[j].first, a[j].second, j)) ++j;
        ans += j - i;
        lc.cut(a[i].first, a[i].second, i);
    }
    cout << ans << '\n';
}