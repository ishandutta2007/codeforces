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
    int n;
    cin >> n;
    if (n < 10) {
        for (int i = 2; i <= n; i++) {
            cout << "B " << i << endl;
            int a;
            cin >> a;
        }
        for (int i = n; i >= 1; i--) {
            cout << "A " << i << endl;
            int a;
            cin >> a;
            if (a) {
                cout << "C " << i << endl;
                return 0;
            }
        }
    }
    vector<int> p(n + 1, 1), q(n + 1);
    p[0] = p[1] = 0;
    vector<int> d;
    for (int i = 2; i <= n; i++) {
        if (p[i]) {
            d.emplace_back(i);
            q[i]++;
            for (int j = i * 2; j <= n; j += i) {
                if (p[j]) {
                    q[i]++;
                    p[j] = 0;
                }
            }
        }
    }
    debug(q);
    int ans = 1;
    int k;
    cout << "A 1" << endl;
    cin >> k;
    int m = 60;
    for (int i = 0; i < (int)d.size(); i++) {
        cout << "B " << d[i] << endl;
        int a;
        cin >> a;
        k -= q[d[i]];
        if (ans != 1 && a != q[d[i]]) {
            int x = d[i];
            while (1LL * x * d[i] <= n) {
                cout << "A " << x * d[i] << endl;
                cin >> a;
                if (!a) {
                    break;
                }
                x *= d[i];
            }
            ans *= x;
        }
        if (ans == 1 && (i % m == m - 1 || i == (int)d.size() - 1)) {
            cout << "A 1" << endl;
            cin >> a;
            if (a != k) {
                for (int j = max(0, i - (m - 1)); j <= i; j++) {
                    int x = 1;
                    while (1LL * x * d[j] <= n) {
                        cout << "A " << x * d[j] << endl;
                        cin >> a;
                        if (!a) {
                            break;
                        }
                        x *= d[j];
                    }
                    ans *= x;
                }
            }
            k = a;
        }
    }
    cout << "C " << ans << endl;
    return 0;
}