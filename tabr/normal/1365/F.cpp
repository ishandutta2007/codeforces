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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            mp[b[i]]--;
        }
        bool ok = true;
        for (auto e : mp) {
            if (e.second != 0) {
                ok = false;
                break;
            }
        }
        if (n & 1) {
            if (a[n / 2] != b[n / 2]) {
                ok = false;
            }
            a.erase(a.begin() + n / 2);
            b.erase(b.begin() + n / 2);
            n--;
        }
        if (!ok) {
            cout << "No" << '\n';
            continue;
        }
        if (n == 0) {
            cout << "Yes" << '\n';
            continue;
        }
        map<pair<int, int>, int> np;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] > a[n - 1 - i]) {
                swap(a[i], a[n - 1 - i]);
            }
            if (b[i] > b[n - 1 - i]) {
                swap(b[i], b[n - 1 - i]);
            }
            np[{a[i], a[n - 1 - i]}]++;
            np[{b[i], b[n - 1 - i]}]--;
        }
        for (auto e : np) {
            if (e.second != 0) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}