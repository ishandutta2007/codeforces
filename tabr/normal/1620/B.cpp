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
        long long w, h;
        cin >> w >> h;
        int k;
        cin >> k;
        vector<long long> x1(k);
        for (int i = 0; i < k; i++) {
            cin >> x1[i];
        }
        cin >> k;
        vector<long long> x2(k);
        for (int i = 0; i < k; i++) {
            cin >> x2[i];
        }
        cin >> k;
        vector<long long> y1(k);
        for (int i = 0; i < k; i++) {
            cin >> y1[i];
        }
        cin >> k;
        vector<long long> y2(k);
        for (int i = 0; i < k; i++) {
            cin >> y2[i];
        }
        cout << max(w * max(y1.back() - y1[0], y2.back() - y2[0]), h * max(x1.back() - x1[0], x2.back() - x2[0])) << '\n';
    }
    return 0;
}