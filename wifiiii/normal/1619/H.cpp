#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 5;
int ch[N][2], rd[N], sz[N], val[N], a[N], fa[N], vis[N], tot = 0;
void pushup(int rt) {
    sz[rt] = 1 + sz[ch[rt][0]] + sz[ch[rt][1]];
}
void split(int rt, int k, int &x, int &y) {
    if(!rt) {
        x = y = 0;
        return;
    }
    if(sz[ch[rt][0]] + 1 <= k) {
        if(ch[rt][1]) fa[ch[rt][1]] = 0;
        x = rt, split(ch[rt][1], k - sz[ch[rt][0]] - 1, ch[rt][1], y);
        if(ch[rt][1]) fa[ch[rt][1]] = rt;
    } else {
        if(ch[rt][0]) fa[ch[rt][0]] = 0;
        y = rt, split(ch[rt][0], k, x, ch[rt][0]);
        if(ch[rt][0]) fa[ch[rt][0]] = rt;
    }
    pushup(rt);
}
int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(rd[x] < rd[y]) {
        ch[x][1] = merge(ch[x][1], y);
        if(ch[x][1]) fa[ch[x][1]] = x;
        pushup(x);
        return x;
    } else {
        ch[y][0] = merge(x, ch[y][0]);
        if(ch[y][0]) fa[ch[y][0]] = y;
        pushup(y);
        return y;
    }
}

pair<int,int> get(int x) {
    int p = x, pos = sz[ch[x][0]];
    while(fa[p]) {
        if(p == ch[fa[p]][1]) pos += sz[ch[fa[p]][0]] + 1;
        p = fa[p];
    }
    return {p, pos};
}
int kth(int p, int k) {
    while(k) {
        if(k <= sz[ch[p][0]]) {
            p = ch[p][0];
        } else if(k == sz[ch[p][0]] + 1) {
            return p;
        } else {
            k -= sz[ch[p][0]] + 1;
            p = ch[p][1];
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i], rd[i] = mrand() % INT_MAX, sz[i] = 1;
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        int p = i, rt = 0;
        while(!vis[p]) {
            vis[p] = 1;
            rt = merge(rt, p);
            p = a[p];
        }
    }
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            cin >> x >> y;
            auto [rtx, px] = get(x);
            auto [rty, py] = get(y);
            if(rtx == rty) {
                if(px > py) {
                    swap(px, py);
                    swap(x, y);
                }
                // px < py
                int l, m, r;
                split(rtx, px + 1, l, r);
                split(r, py - px, m, r);
                merge(l, r);
            } else {
                int lx, rx, ly, ry;
                split(rtx, px + 1, lx, rx);
                split(rty, py + 1, ly, ry);
                merge(merge(lx, ry), merge(ly, rx));
            }
        } else {
            int x, k;
            cin >> x >> k;
            auto [rt, pos] = get(x);
            pos = (pos + k) % sz[rt];
            cout << kth(rt, pos + 1) << '\n';
        }
    }
}