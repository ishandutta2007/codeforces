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
        int same0 = 0;
        int same1 = 0;
        if (!ask(zero, zero + 1, one) && !ask(zero, zero + 1, one + 1) && !ask(zero, zero + 1, one + 2)) {
            same0 = 1;
        }
        if (ask(one, one + 1, zero) && ask(one, one + 1, zero + 1) && ask(one, one + 1, zero + 2)) {
            same1 = 1;
        }
        int imps = -1;
        int crew = -1;
        vector<int> ans;
        if (same0) {
            ans.emplace_back(zero);
            ans.emplace_back(zero + 1);
            if (same1) {
                imps = zero;
                crew = one;
                if (!ask(imps, crew, one + 2)) {
                    ans.emplace_back(one + 2);
                }
            } else {
                imps = zero;
                crew = one + 2;
                if (!ask(crew, imps, one)) {
                    ans.emplace_back(one);
                } else {
                    ans.emplace_back(one + 1);
                }
            }
            if (!ask(imps, crew, zero + 2)) {
                ans.emplace_back(zero + 2);
            }
        } else {
            imps = zero + 2;
            ans.emplace_back(imps);
            if (same1) {
                crew = one;
                if (!ask(imps, crew, one + 2)) {
                    ans.emplace_back(one + 2);
                }
            } else {
                crew = one + 2;
                if (!ask(crew, imps, one)) {
                    ans.emplace_back(one);
                } else {
                    ans.emplace_back(one + 1);
                }
            }
            if (!ask(zero, imps, crew)) {
                ans.emplace_back(zero);
            } else {
                ans.emplace_back(zero + 1);
            }
        }
        for (int i = 0; i < n; i += 3) {
            if (i == one || i == zero) {
                continue;
            }
            if (a[i / 3] == 1) {  // more crew
                if (!ask(imps, i, i + 1)) {
                    // i + 2 -> crew
                    if (!ask(imps, crew, i)) {
                        ans.emplace_back(i);
                    } else {
                        ans.emplace_back(i + 1);
                    }
                } else {
                    // i, i + 1 -> crew
                    if (!ask(imps, crew, i + 2)) {
                        ans.emplace_back(i + 2);
                    }
                }
            } else {  // more imps
                if (!ask(crew, i, i + 1)) {
                    ans.emplace_back(i);
                    ans.emplace_back(i + 1);
                    if (!ask(imps, crew, i + 2)) {
                        ans.emplace_back(i + 2);
                    }
                } else {
                    ans.emplace_back(i + 2);
                    if (!ask(imps, crew, i)) {
                        ans.emplace_back(i);
                    } else {
                        ans.emplace_back(i + 1);
                    }
                }
            }
        }
        cout << "! " << ans.size();
        for (int i : ans) {
            cout << " " << i + 1;
        }
        cout << endl;
    }
    return 0;
}