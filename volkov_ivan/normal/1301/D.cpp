#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    int mem = k;
    vector <pair <int, string>> res, res2;
    for (int i = 0; i < n; i++) {
        if (k == 0) break;
        int nxt = min(m - 1, k);
        res.push_back({nxt, "R"});
        k -= nxt;
        if (k == 0) break;
        if (i != n - 1) {
            int nxt = min(m - 1, k / 3);
            res.push_back({nxt, "DUL"});
            k -= nxt * 3;
            if (k == 0) break;
            if (nxt != m - 1) {
                res.push_back({1, "D"});
                k--;
                if (k == 0) break;
                res.push_back({1, "U"});
                k--;
                if (k == 0) break;
                assert(k != 0);
            }
        } else {
            int nxt = min(m - 1, k);
            res.push_back({nxt, "L"});
            k -= nxt;
            if (k == 0) break;
        }
        if (i != n - 1) {
            res.push_back({1, "D"});
            k--;
        }
        if (k == 0) break;
    }
    if (k != 0) {
        int nxt = min(n - 1, k);
        res.push_back({nxt, "U"});
        k -= nxt;
    }
    if (k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (auto elem : res) if (elem.first != 0) res2.push_back(elem);
    cout << "YES" << endl;
    cout << res2.size() << endl;
    assert(res2.size() <= 3000);
    int cnt = 0;
    for (auto elem : res2) {
        cnt += elem.first * elem.second.size();
        cout << elem.first << ' ' << elem.second << endl;
    }
    assert(cnt == mem);
    return 0;
}