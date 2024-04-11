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
        string t;
        int n;
        cin >> t >> n;
        vector<string> s(n);
        for (auto &x : s) {
            cin >> x;
        }
        int cur = 0;
        vector<pair<int, int>> answer;
        bool ok = true;
        while (cur < t.size()) {
            pair<int, pair<int, int>> mx;
            for (int l = 0; l <= cur; l++) {
                for (int i = 0; i < n; i++) {
                    if (l + s[i].size() > t.size()) {
                        continue;
                    }
                    bool eq = true;
                    for (int j = 0; j < s[i].size(); j++) {
                        if (s[i][j] != t[l + j]) {
                            eq = false;
                            break;
                        }
                    }
                    if (eq) {
                        mx = max(mx, {l + s[i].size(), {i + 1, l + 1}});
                    }
                }
            }
            if (mx.first <= cur) {
                ok = false;
                break;
            }
            answer.push_back(mx.second);
            cur = mx.first;
        }
        if (!ok) {
            cout << -1 << '\n';
        } else {
            cout << answer.size() << '\n';
            for (auto [a, b] : answer) {
                cout << a << ' ' << b << '\n';
            }
        }
    }
    return 0;
}