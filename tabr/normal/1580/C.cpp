#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const int N = (int) 2e5 + 10;
const int lim = 600;

int x[N], y[N], z[N];
int a[N];
int on[N];
int b[lim][lim];
int id[lim];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        z[i] = x[i] + y[i];
    }
    int ans = 0;
    for (int t = 0; t < m; t++) {
        int op, k;
        cin >> op >> k;
        k--;
        if (z[k] >= lim) {
            if (op == 1) {
                on[k] = t + x[k];
                int s = on[k];
                while (s < m) {
                    a[s]++;
                    s += y[k];
                    if (s < m) {
                        a[s]--;
                        s += x[k];
                    }
                }
            } else {
                int s = on[k];
                while (s < m) {
                    if (s < t && t <= s + y[k]) {
                        ans--;
                    }
                    a[s]--;
                    s += y[k];
                    if (s < m) {
                        a[s]++;
                        s += x[k];
                    }
                }
            }
        } else {
            if (op == 1) {
                on[k] = (t + x[k]) % z[k];
                b[z[k]][on[k]]++;
                int off = on[k] + y[k];
                if (off >= z[k]) {
                    off -= z[k];
                }
                b[z[k]][off]--;
                ans++;
            } else {
                int off = on[k] + y[k];
                if (off >= z[k]) {
                    off -= z[k];
                }
                int now = t % z[k];
                if (on[k] < now && now <= off) {
                    ans--;
                } else if (off < on[k] && (now <= off || on[k] < now)) {
                    ans--;
                }
                b[z[k]][on[k]]--;
                b[z[k]][off]++;
            }
        }
        ans += a[t];
        for (int i = 1; i < lim; i++) {
            ans += b[i][id[i]++];
            if (id[i] == i) {
                id[i] = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}