#include <bits/stdc++.h>
 
using ll = long long;
 
const int maxn = 100005;
 
void compress(std::string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') s[i] = 'B';
        if (s[i] == 'G') s[i] = 'D';
    }
}
 
struct SegmenTree{
    int x[3 * maxn];
    void update(int node, int l, int r, int pos, int val) {
        if (r < pos || l > pos) return;
        if (l == r) {
            assert(l == pos);
            x[node] = val;
            return;
        }
        int mid = l + r >> 1;
        update(node * 2, l, mid, pos, val);
        update(node * 2 + 1, mid + 1, r, pos, val);
        x[node] = x[node * 2] + x[node * 2 + 1];
    }
    int get(int node, int l, int r, int ll, int rr) {
        if (l > r || l > rr || r < ll) return 0;
        if (ll <= l && r <= rr) return x[node];
        int mid = l + r >> 1;
        return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
    }
} st[4][10][10];
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::string s;
    std::cin >> s;
    compress(s);
    int len = s.size();
    for (int k = 1; k <= 10; k++) {
        for (int i = 0; i < len; i++) {
            st[s[i] - 'A'][k - 1][i % k].update(1, 0, len - 1, i, 1);
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int pos;
            std::cin >> pos;
            char ch;
            std::cin >> ch;
            pos--;
            if (ch == 'T') ch = 'B';
            if (ch == 'G') ch = 'D';
            for (int k = 1; k <= 10; k++) {
                st[s[pos] - 'A'][k - 1][pos % k].update(1, 0, len - 1, pos, 0);
                st[ch - 'A'][k - 1][pos % k].update(1, 0, len - 1, pos, 1);
            }
            s[pos] = ch;
        } else {
            int l, r;
            std::cin >> l >> r;
            std::string e;
            std::cin >> e;
            compress(e);
            int ans = 0;
            l--;
            r--;
            int sz = e.size();
            for (int i = 0; i < sz; i++) {
                ans += st[e[i] - 'A'][sz - 1][(l + i) % sz].get(1, 0, len - 1, l, r);
            }
            std::cout << ans << "\n";
        }
    }
    return 0;
}