#include <bits/stdc++.h>
#define fileinput(name) freopen(name".txt", "r", stdin)
#define fileoutput(name) freopen(name".txt", "w", stdout)
using namespace std;

const int maxn = 1e5 + 10;
string s;

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    int cnt[26], tag;
    segtree(int l, int r) {
        memset(cnt, 0, sizeof(cnt));
        tag = -1;
        if (l == r) cnt[s[l]] = 1, lc = rc = nullptr;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r), pull();
    }
    void pull() { for (int i = 0; i < 26; ++i) cnt[i] = lc->cnt[i] + rc->cnt[i]; }
    void push(int l, int r) {
        if (l == r || tag == -1) return;
        memset(lc->cnt, 0, sizeof(lc->cnt));
        lc->cnt[tag] = (m - l + 1); lc->tag = tag;
        memset(rc->cnt, 0, sizeof(rc->cnt));
        rc->cnt[tag] = (r - m + 0); rc->tag = tag;
        tag = -1;
    }
    void modify(int l, int r, int ql, int qr, int v) {
        if (ql > qr) return;
        push(l, r);
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) {
            memset(cnt, 0, sizeof(cnt));
            cnt[v] = (r - l + 1);
            tag = v;
            return;
        }
        lc->modify(l, m, ql, qr, v); rc->modify(m + 1, r, ql, qr, v);
        pull();
    }
    int query(int l, int r, int ql, int qr, int v) {
        if (ql > qr) return 0;
        push(l, r);
        if (l > qr || ql > r) return 0;
        if (l >= ql && r <= qr) return cnt[v];
        return lc->query(l, m, ql, qr, v) + rc->query(m + 1, r, ql, qr, v);
    }
    void dfs(int l, int r) {
        push(l, r);
        int v = -1;
        for (int i = 0; i < 26; ++i) if (cnt[i] > 0) v = i;
        if (l == r) return cout << (char)('a' + v), void();
        lc->dfs(l, m); rc->dfs(m + 1, r);
    }
#undef m
} *st;

int main() {
    fileinput("input"); fileoutput("output");
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) s[i] -= 'a';
    st = new segtree(0, n - 1);
    while (m--) {
        int l, r; cin >> l >> r; --l, --r;
        vector<int> c(26);
        for (int i = 0; i < 26; ++i) c[i] = st->query(0, n - 1, l, r, i);
        int od = -1;
        bool ig = false;
        for (int i = 0; i < 26; ++i) if (c[i] & 1) {
            if (od != -1) ig = true;
            od = i;
        }
        if (od != -1 && (r - l + 1) % 2 == 0) continue;
        if (ig) continue;
        int lp = l, rp = r;
        if (od != -1) st->modify(0, n - 1, (l + r) / 2, (l + r) / 2, od), --c[od];
        for (int i = 0; i < 26; ++i) {
            if (c[i] == 0) continue;
            st->modify(0, n - 1, lp, lp + c[i] / 2 - 1, i);
            lp += c[i] / 2;
            st->modify(0, n - 1, rp - c[i] / 2 + 1, rp, i);
            rp -= c[i] / 2;
        } 
    }
    st->dfs(0, n - 1);
    return 0;
}