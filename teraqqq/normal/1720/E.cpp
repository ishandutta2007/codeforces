#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

struct Counter {
    int uniq;
    vector<int> cnt;

    Counter(int sz) : uniq(0), cnt(sz) { }

    void insert(int x) {
        if (cnt[x] == 0) uniq++;
        cnt[x]++;
    }

    void erase(int x) {
        cnt[x]--;
        if (cnt[x] == 0) uniq--;
    }

    int unique_count() const {
        return uniq;
    }
};

int solve(int n, int k, vector<vi> a) {
    Counter counter(n*n);
    for (auto w : a) for (int x : w) counter.insert(x);
    if (counter.unique_count() <= k) return k - counter.unique_count();
    if (k == 1) return 1;

    for (int diff = -n+1; diff <= n-1; ++diff) {
        const int xmin = max(0, -diff);
        const int xmax = min(0, -diff) + n-1;

        int l = xmin, r = xmin;
        for (; r <= xmax; ++r) {
            counter.erase(a[r][r+diff]);
            for (int t = l; t < r; ++t) {
                counter.erase(a[t][r+diff]);
                counter.erase(a[r][t+diff]);
            }

            while (l < r && counter.unique_count() < k - 1) {
                counter.insert(a[l][l+diff]);
                for (int t = l+1; t <= r; ++t) {
                    counter.insert(a[l][t+diff]);
                    counter.insert(a[t][l+diff]);
                }

                l++;
            }

            if (counter.unique_count() == k-1 || counter.unique_count() == k) {
                return 1;
            }
        }

        r--;
        for (int i = l; i <= r; ++i)
        for (int j = l; j <= r; ++j) {
            counter.insert(a[i][j+diff]);
        }
    }

    return 2;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector a(n, vector<int>(n));
    for (auto& w : a) for (int& x : w) cin >> x, --x;

    int res = solve(n, k, a);

    cout << res << endl;
}