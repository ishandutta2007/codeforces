#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;

struct Node{
    int mn, res;
    Node() {}
    Node(int l, int r) {
        mn = r;
        res = (l <= r ? l : N);
    }
};

Node t[2 * N];
set <int> lw[N], up[N];

void relax(int pos) {
    t[pos].mn = min(t[2 * pos].mn, t[2 * pos + 1].mn);
    if (t[2 * pos + 1].mn < t[2 * pos].res) t[pos].res = N;
    else t[pos].res = max(t[2 * pos].res, t[2 * pos + 1].res);
}

void upd(int pos, int l, int r) {
    pos += N - 1;
    t[pos] = Node(l, r);
    while (pos > 1) {
        pos /= 2;
        relax(pos);
    }
}


signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = N; i < 2 * N; i++) t[i] = Node(0, m);
    for (int i = N - 1; i >= 1; i--) relax(i);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int x = (a + 1) / 2, y = (b + 1) / 2;
        if (a % 2 == 1) {
            int v = m - y + 1;
            if (lw[x].find(v) != lw[x].end()) lw[x].erase(v);
            else lw[x].insert(v);
        } else {
            int v = m - y;
            if (up[x].find(v) != up[x].end()) up[x].erase(v);
            else up[x].insert(v);
        }
        int ll, rr;
        rr = (up[x].empty() ? m : (*up[x].begin()));
        if (lw[x].empty()) ll = 0;
        else {
            auto uk = lw[x].end();
            ll = *(--uk);
        }
        upd(x, ll, rr);
        cout << (t[1].res <= m ? "YES" : "NO") << "\n";
    }
    return 0;
}