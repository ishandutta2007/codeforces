#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 10, inf = 1e9;

int main() {
    int n; cin >> n;
    vector<int> a(n << 1);
    for (int i = 0; i < n << 1; ++i) cin >> a[i];
    int ans = inf;
    for (int i = 0; i < n * 2; ++i) {
        for (int j = i + 1; j < n * 2; ++j) {
            vector<int> vec;
            int cur = 0;
            for (int k = 0; k < 2 * n; ++k) if (k != i && k != j) vec.push_back(a[k]);
            sort(vec.begin(), vec.end());
            for (int k = 0; k < 2 * n - 2; k += 2) cur += abs(vec[k] - vec[k + 1]);
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}