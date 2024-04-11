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
        int n, d;
        cin >> n >> d;
        int mx = n * (n - 1) / 2;
        int mn = 0;
        int aa = 1;
        vector<int> p(n), q(1), dep(n);
        set<int> st;
        for (int i = 1; i < n; i++) {
            p[i] = (i - 1) / 2;
            dep[i] = aa;
            if (dep[i] != dep[i - 1]) {
                st.emplace(i);
                q.emplace_back(i);
            }
            mn += aa;
            if (i + 2 == (1 << (aa + 1))) {
                aa++;
            }
        }
        if (d < mn || mx < d) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = n - 1; i > 0; i--) {
            if (st.count(i)) {
                continue;
            }
            if (mn == d) {
                break;
            }
            for (int j = dep[i]; j < q.size(); j++) {
                p[i] = q[j];
                mn++;
                if (mn == d) {
                    break;
                }
            }
            q.emplace_back(i);
        }
        for (int i = 1; i < n; i++) {
            cout << p[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}