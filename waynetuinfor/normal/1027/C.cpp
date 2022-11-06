#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }
        vector<pair<int, int>> cc;
        for (auto it : cnt) {
            if (it.second >= 4) cc.emplace_back(it.first, 4);
            else if (it.second >= 2) cc.emplace_back(it.first, 2);
        }
        sort(cc.begin(), cc.end());
        double ans = 1000000000.0;
        vector<int> bst;
        for (int i = 0; i < cc.size(); ++i) {
            auto it = cc[i];
            if (it.second >= 4) {
                long long p = (it.first * 4) * 1ll * (it.first * 4);
                long long q = it.first * 1ll * it.first;
                if (p * 1.0 / q < ans) {
                    ans = p * 1.0 / q;
                    bst = { it.first, it.first, it.first, it.first };
                }
            }
            if (i > 0) {
                auto pit = cc[i - 1];
                long long p = ((pit.first + it.first) * 2) * 1ll * ((pit.first + it.first) * 2);
                long long q = pit.first * 1ll * it.first;
                if (p * 1.0 / q < ans) {
                    ans = p * 1.0 / q;
                    bst = { it.first, it.first, pit.first, pit.first };
                }
            }
        }
        for (int i : bst) printf("%d ", i);
        puts("");
    }
    return 0;
}