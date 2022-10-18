#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map<tuple<int, int, int>, int> mp;
        auto ask = [&](int a, int b, int c) {
            vector<int> d = {a, b, c};
            sort(d.begin(), d.end());
            auto t = make_tuple(d[0], d[1], d[2]);
            if (mp.count(t)) {
                return mp[t];
            }
            cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
            cin >> a;
            return mp[t] = a;
        };
        vector<int> a(n / 3);
        int zero = -1;
        int one = -1;
        for (int i = 0; i < n; i += 3) {
            int k = ask(i, i + 1, i + 2);
            if (k == 0) {
                zero = i;
            } else {
                one = i;
            }
            a[i / 3] = k;
        }
        assert(zero != -1 && one != -1);
        int c1 = -1, c2 = -1;
        vector<int> b = {zero, zero + 1, zero + 2, one, one + 1, one + 2};
        for (int x = 0; x < 6; x++) {
            for (int y = x + 1; y < 6; y++) {
                int t = 0;
                for (int z = 0; z < 6; z++) {
                    if (x == z || y == z) {
                        continue;
                    }
                    t |= 1 << ask(b[x], b[y], b[z]);
                }
                if (t == 3) {
                    c1 = b[x];
                    c2 = b[y];
                    break;
                }
            }
            if (c1 != -1) {
                break;
            }
        }
        debug(c1, c2);
        assert(c1 != -1);
        vector<int> ans;
        vector<int> t(n, -1);
        for (int i = 0; i < n; i++) {
            if (i == c1 || i == c2) {
                continue;
            }
            if (!ask(i, c1, c2)) {
                ans.emplace_back(i);
                t[i] = 0;
                zero = i;
            } else {
                t[i] = 1;
                one = i;
            }
        }
        if (!ask(c1, zero, one)) {
            ans.emplace_back(c1);
        } else {
            ans.emplace_back(c2);
        }
        cout << "! " << ans.size();
        for (int i : ans) {
            cout << " " << i + 1;
        }
        cout << endl;
    }
    return 0;
}