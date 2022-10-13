#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
struct seg_tree {
    vector<long long> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
    }
    void upd(int i, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0LL;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m)
            + query(l, r, 2 * x + 2, m, rx);
    }
    void upd(int i, long long v) { upd(i, v, 0, 0, sz); }
    long long query(int l, int r) { return query(l, r, 0, 0, sz); }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> stack;
    vector<int> par(n, -1);
    vector<int> sz(n);
    vector<int> en(n, -1);
    vector<int> bef(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack.push_back(i);
        } else if (s[i] == ')') {
            if (!stack.empty()) {
                int gt = stack.back();
                en[gt] = i;
                bef[i] = gt;
                stack.pop_back();
                if (!stack.empty()) {
                    par[gt] = stack.back();
                    ++sz[stack.back()];
                }
            }
            
        }
    }
    vector<bool> cover(n);
    vector<int> id(n);
    vector<int> numTree(n);
    vector<seg_tree> sto;
    int currTree = 0;
    for (int i = 0; i < n; i++) {
        if (cover[i]) continue;
        int st = i;
        vector<int> in;
        int curr = 0;
        while (st < n && en[st] != -1) {
            in.push_back(st);
            id[st] = curr++;
            numTree[st] = currTree;
            cover[st] = true;
            st = en[st] + 1;
        }
        ++currTree;
        seg_tree nxt;
        nxt.init(curr);
        sto.push_back(nxt);
    }
    seg_tree num, quad;
    num.init(n), quad.init(n);
    for (int i = 0; i < n; i++) {
        if (en[i] != -1) {
            num.upd(i, 1);
            sto[numTree[i]].upd(id[i], 1);
        }
        quad.upd(i, sz[i] * 1LL * (sz[i] - 1) / 2);
    }
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            if (par[l] != -1) {
                --sz[par[l]];
                quad.upd(par[l], sz[par[l]] * 1LL * (sz[par[l]] - 1) / 2);
            }
            num.upd(l, 0);
            sto[numTree[l]].upd(id[l], 0);
        } else {
            long long ans = quad.query(l, r + 1)
                + num.query(l, r + 1);
            int st = l, end = bef[r];
            int numTrees = sto[numTree[st]].query(id[st], id[end] + 1);
            ans += numTrees * 1LL * (numTrees - 1) / 2;
            cout << ans << "\n";
        }
    }
}