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
    vector<int> b(32);
    vector<vector<int>> x(32);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int t = 0;
        int c = a;
        while (a / 2) {
            a /= 2;
            t++;
        }
        b[t]++;
        x[t].emplace_back(c);
    }
    function<int(vector<vector<int>>)> solve = [&](vector<vector<int>> v) {
        debug(v);
        int res = n + 1;
        for (int i = 0; i < 32; i++) {
            if (!v[i].empty()) {
                int s = 0;
                for (int j = 0; j < i; j++) {
                    s += (int)v[j].size();
                }
                s = max(0, s - 1);
                for (int j = i + 1; j < 32; j++) {
                    if (!v[j].empty()) {
                        s += (int)v[j].size() - 1;
                    }
                }
                if (i != 0) {
                    vector<vector<int>> t(32);
                    for (int j : v[i]) {
                        int a = j ^ (1 << i);
                        int c = a;
                        int tt = 0;
                        while (a / 2) {
                            a /= 2;
                            tt++;
                        }
                        t[tt].emplace_back(c);
                    }
                    s += solve(t);
                }
                res = min(res, s);
            }
        }
        return res;
    };
    cout << solve(x) << '\n';
    return 0;
}