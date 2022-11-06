#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxv = 1e6;
int a[maxn];
bool v[maxv + 10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> mul;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mul.push_back(max(a[i], a[j]) - min(a[i], a[j]));
            }
        }
        sort(mul.begin(), mul.end()); mul.resize(unique(mul.begin(), mul.end()) - mul.begin());
        for (int i : mul) v[i] = true;
        vector<int> now = { 1 };
        size_t ptr = 0; int cur = 2;
        for (int i = 0; i < n - 1; ++i) {
            while (ptr < mul.size() && cur == mul[ptr]) ++ptr, ++cur;
            while (cur <= maxv) {
                bool ok = true;
                for (int j : now)  {
                    if (v[cur - j]) ok = false;
                    if (!ok) break;
                }
                ++cur;
                if (ok) {
                    now.push_back(cur - 1);
                    break;
                }
            }
        }
        for (int i : mul) v[i] = false;
        if (now.size() < n) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i : now) cout << i << ' '; cout << endl;
    }
    return 0;
}