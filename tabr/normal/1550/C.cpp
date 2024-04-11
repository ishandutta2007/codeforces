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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> b;
            for (int j = i; j < n; j++) {
                b.emplace_back(a[j]);
                int ng = 0;
                for (int x = 0; x < (int) b.size(); x++) {
                    for (int y = x + 1; y < (int) b.size(); y++) {
                        for (int z = y + 1; z < (int) b.size(); z++) {
                            if (b[x] <= b[y] && b[y] <= b[z]) {
                                ng = 1;
                            }
                            if (b[x] >= b[y] && b[y] >= b[z]) {
                                ng = 1;
                            }
                        }
                    }
                }
                if (ng) {
                    break;
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}