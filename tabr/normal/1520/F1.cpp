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
    int n, tt;
    cin >> n >> tt;
    vector<int> kk(tt);
    for (int i = 0; i < tt; i++) {
        cin >> kk[i];
    }
    auto ask = [&](int l, int r) {
        cout << "? " << l << " " << r << endl;
        int a;
        cin >> a;
        return a;
    };
    for (int k : kk) {
        int lo = 0, hi = n;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int a = ask(1, mid);
            if (mid - a >= k) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << "! " << hi << endl;
    }
    return 0;
}