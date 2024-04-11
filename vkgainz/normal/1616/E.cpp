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
    vector<int> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
    }
    void upd(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, 2 * x + 1, lx, m);
        else upd(i, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void upd(int i) { upd(i, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m)
            + query(l, r, 2 * x + 2, m, rx);
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
};

int main() {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        vector<vector<int>> spos(26);
        for (int i = 0; i < n; i++) {
            spos[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            reverse(spos[i].begin(), spos[i].end());
        }
        long long ans = 1e12;
        seg_tree in;
        in.init(n);
        long long curr = 0LL;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                //iterate
                //mv to t[i]
                if (spos[t[i - 1] - 'a'].empty()) {
                    break;
                }
                int mv = spos[t[i - 1] - 'a'].back();
                int effective_pos = in.query(mv, n) + mv;
                curr += effective_pos - (i - 1);
                in.upd(mv);
                spos[t[i - 1] - 'a'].pop_back();
            }
            for (int j = 0; j < t[i] - 'a'; j++) {
                if (spos[j].empty()) continue;
                int mv = spos[j].back();
                int effective_pos = in.query(mv, n) + mv;
                int extra = effective_pos - i;
                ans = min(ans, curr + extra);
            }
        }
        if (ans == 1e12) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}