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
    int n = 22;
    vector<int> pn(1, 2);
    int tmp = 3;
    while (pn.size() != 300) {
        bool ok = true;
        for (int i : pn) {
            if (tmp % i == 0) {
                ok = false;
                tmp += 2;
                break;
            }
        }
        if (ok) {
            pn.emplace_back(tmp);
            tmp += 2;
        }
    }
    while (tt--) {
        int ans = 1;
        vector<int> can;
        int j = 0;
        for (int i = 0; i < 18; i++) {
            ll q = 1;
            int st = j;
            while ((double)q * pn[j] < 1e18) {
                q *= pn[j];
                j++;
            }
            cout << "? " << q << endl;
            cin >> q;
            for (int k = st; k < j; k++) {
                int t = 1;
                while (q != 0 && q % pn[k] == 0) {
                    if (t == 1 && pn[k] < 100) {
                        can.emplace_back(pn[k]);
                    }
                    q /= pn[k];
                    t++;
                }
                ans *= t;
            }
        }
        while (can.size() < 8) {
            can.emplace_back(103);
        }
        debug(can);
        for (int i = 0; i < 4; i++) {
            ll q = 1;
            double p = 1;
            for (int k = 0; k < 2; k++) {
                p *= 1e9;
                while ((double)q * can[2 * i + k] < p) {
                    q *= can[2 * i + k];
                }
            }
            cout << "? " << q << endl;
            cin >> q;
            for (int k = 0; k < 2; k++) {
                if (can[2 * i + k] == 103) {
                    continue;
                }
                int t = 1;
                while (q != 0 && q % can[2 * i + k] == 0) {
                    q /= can[2 * i + k];
                    t++;
                }
                debug(can[2 * i + k], t);
                ans *= t;
                ans /= 2;
            }
        }
        ans += ans;
        cout << "! " << max(ans, 8) << endl;
    }
    return 0;
}