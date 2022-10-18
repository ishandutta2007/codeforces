#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        vector<int> a(n);
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = {a[i], i};
        }
        sort(p.begin(), p.end());
        int ans = 0;
        int j = -1;
        for (int i = 0; i < n - 1; i++) {
            if (p[i].second > p[i + 1].second) {
                int l = i - j;
                for (int k = j; k >= 0; k--) {
                    if (p[k].first != p[j].first) {
                        break;
                    }
                    if (p[k].second < p[j + 1].second) {
                        l++;
                    }
                }
                for (int k = i + 1; k < n; k++) {
                    if (p[k].first != p[i + 1].first) {
                        break;
                    }
                    if (p[i].second < p[k].second) {
                        l++;
                    }
                }
                ans = max(ans, l);
                j = i;
            }
        }
        int l = n - 1 - j;
        for (int k = j; k >= 0; k--) {
            if (p[k].first != p[j].first) {
                break;
            }
            if (p[k].second < p[j + 1].second) {
                l++;
            }
        }
        ans = max(ans, l);
        ans = n - ans;
        cout << ans << '\n';
    }
    return 0;
}