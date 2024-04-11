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
        int a, b, ab, ba;
        cin >> a >> b >> ab >> ba;
        string s;
        cin >> s;
        int n = (int) s.size();
        int aa = (int) count(s.begin(), s.end(), 'A');
        int bb = (int) count(s.begin(), s.end(), 'B');
        if (aa != a + ab + ba || bb != b + ab + ba) {
            cout << "NO" << '\n';
            continue;
        }
        int c = 0;
        vector<int> ad, bd;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && (s[i] + i) % 2 == (s[j] + j) % 2) {
                j++;
            }
            int t = j - i;
            if (t > 1) {
                c += (t - 1) / 2;
                if (t % 2 == 0) {
                    if (s[i] == 'A') {
                        ad.emplace_back(t / 2);
                    } else {
                        bd.emplace_back(t / 2);
                    }
                }
            }
        }
        int need = max(ab + ba - c, 0);
        sort(ad.begin(), ad.end());
        sort(bd.begin(), bd.end());
        for (int x : ad) {
            if (need > 0 && ab >= x) {
                ab -= x;
                need--;
            }
        }
        for (int x : bd) {
            if (need > 0 && ba >= x) {
                ba -= x;
                need--;
            }
        }
        if (need > 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}