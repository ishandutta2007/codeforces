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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d;
    vector<pair<int, int>> ans;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 3) {
            if (!d.empty()) {
                ans.emplace_back(c, d.back());
                ans.emplace_back(c, i);
                c++;
            }
            d.emplace_back(i);
            a[i] = 0;
        }
    }
    if (!d.empty()) {
        int t = 3;
        for (int i = d.back(); i < n; i++) {
            if (a[i] == 2 && t == 3) {
                t = 2;
                ans.emplace_back(c, d.back());
                ans.emplace_back(c, i);
                c++;
                d.emplace_back(i);
                a[i] = 0;
            }
            if (a[i] == 1 && t == 2) {
                t = 0;
                a[i] = 0;
                ans.emplace_back(c, d.back());
                ans.emplace_back(c, i);
                c++;
                break;
            }
        }
        if (t == 2) {
            cout << -1 << '\n';
            return 0;
        }
        if (t != 0) {
            for (int i = d.back(); i < n; i++) {
                if (a[i] == 1) {
                    t = 0;
                    a[i] = 0;
                    ans.emplace_back(c, d.back());
                    ans.emplace_back(c, i);
                    ans.emplace_back(c + 1, i);
                    c += 2;
                    break;
                }
            }
            if (t == 3) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    debug(a);
    queue<int> que;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            continue;
        } else if (a[i] == 1) {
            que.emplace(i);
        } else if (a[i] == 2) {
            if (que.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            ans.emplace_back(c, que.front());
            ans.emplace_back(c, i);
            que.pop();
            c++;
        }
    }
    while (!que.empty()) {
        ans.emplace_back(c++, que.front());
        que.pop();
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
    return 0;
}