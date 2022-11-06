    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>
    using namespace std;
     
    const int maxn = 2097152;
    vector<int> pr[maxn];
    int a[maxn];
     
    int main() {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
     
        for (int i = 0; i < n; ++i) {
            pr[a[i]].push_back(i);
        }
     
        for (int i = 0; i < maxn; ++i) {
            if (pr[i].size() >= 2) {
                int x = pr[i].back(); pr[i].pop_back();
                int y = pr[i].back(); pr[i].pop_back();
                vector<int>().swap(pr[i]);
                pr[i] = {y, x};
            }
        }
     
        for (int i = maxn - 1; i >= 0; --i) {
            for (int j = 0; j < 21; ++j) {
                if ((i >> j & 1) == 0)
                    pr[i].insert(pr[i].end(), pr[i | (1 << j)].begin(), pr[i | (1 << j)].end());
            }
            sort(pr[i].begin(), pr[i].end());
            pr[i].resize(unique(pr[i].begin(), pr[i].end()) - pr[i].begin());
            if (pr[i].size() >= 2) {
                int x = pr[i].back(); pr[i].pop_back();
                int y = pr[i].back(); pr[i].pop_back();
                vector<int>().swap(pr[i]);
                pr[i] = {y, x};
            }
        }
     
        auto check = [&](int v) {
            for (int i = 0; i < n; ++i) {
                int z = (a[i] ^ v) & v;
                if (pr[z].size() >= 2 && pr[z][0] > i) return true;
            }
            return false;
        };
     
        int ans = 0;
        for (int d = 20; d >= 0; --d) {
            if (check(ans | (1 << d))) 
                ans |= (1 << d);
        }
        printf("%d\n", ans);
        return 0;
    }