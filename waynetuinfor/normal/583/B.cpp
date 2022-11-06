#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn], dp[maxn];
bool v[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int now = 0, h = 0, d = 0, ans = 0;
    while (h < n) {
        bool g = false;
        if (d == 0) {
            for (int i = now + 1; i <= n; ++i) if (!v[i]) {
                if (a[i] <= h) {
                    now = i;
                    v[i] = true;
                    g = true;
                    ++h;
                }
            }
            if (g) continue;
            d = 1;
            ++ans;
            for (int i = now - 1; i >= 1; --i) if (!v[i]) {
                if (a[i] <= h) {
                    v[i] = true;
                    now = i;
                    g = true;
                    ++h;
                }
            }
        } else {
            for (int i = now - 1; i >= 1; --i) if (!v[i]) {
                if (a[i] <= h) {
                    v[i] = true;
                    now = i;
                    g = true;
                    ++h;
                }
            }
            if (g) continue;
            d = 0;
            ++ans;
            for (int i = now + 1; i <= n; ++i) if (!v[i]) {
                if (a[i] <= h) {
                    v[i] = true;
                    now = i;
                    g = true;
                    ++h;
                }
            }
        }
    }
    cout << ans << endl;
}