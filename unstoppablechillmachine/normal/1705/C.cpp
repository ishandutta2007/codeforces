#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<pair<int, int>> seg = {{1, n}};
        for (int i = 0; i < c; i++) {
            int l, r;
            cin >> l >> r;
            seg.emplace_back(l, r);
        }
        vector<int> sum(seg.size());
        sum[0] = n;
        for (int i = 1; i < seg.size(); i++) {
            sum[i] = sum[i - 1] + (seg[i].second - seg[i].first + 1);
        }
        for (int i = 0; i < q; i++) {
            int pos, ptr = static_cast<int>(seg.size()) - 1;
            cin >> pos;
            while (pos > n) {
                //cout << "POS " << pos << '\n';
                while (ptr > 0 && sum[ptr - 1] >= pos) {
                    ptr--;
                }
                pos = seg[ptr].second - (sum[ptr] - pos);
            }
            //cout << pos << endl;
            cout << s[pos - 1] << '\n';
        }
    }
    return 0;
}