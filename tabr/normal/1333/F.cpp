#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<bool> pn;
inline void sieve(int n) {
    pn.resize(n + 1, true);
    pn[0] = pn[1] = false;
    for (int i = 2; i <= n; i++) {
        if (pn[i]) {
            for (int j = 2; i * j <= n; j++) {
                pn[i * j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    sieve(n);
    int cnt = 1;
    vector<int> t;
    for (int i = 2; i <= n; i++) {
        if (pn[i]) {
            cnt++;
        } else {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    t.emplace_back(i / j);
                    break;
                }
            }
        }
    }
    sort(t.begin(), t.end());
    for (int i = 1; i <= cnt; i++) {
        ans[i] = 1;
    }
    for (int i = cnt + 1; i <= n; i++) {
        ans[i] = t[i - cnt - 1];
    }
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}