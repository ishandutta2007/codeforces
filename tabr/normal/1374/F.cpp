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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        vector<int> c = a;
        sort(c.begin(), c.end());
        auto sw = [&](int id) {
            b.emplace_back(id);
            swap(a[id + 1], a[id + 2]);
            swap(a[id], a[id + 1]);
        };
        for (int i = 0; i < n - 2; i++) {
            int mn = a[i], pos = i;
            for (int j = i; j < n; j++) {
                if (a[j] < mn) {
                    pos = j;
                    mn = a[j];
                }
            }
            for (int j = pos - 2; j >= i; j -= 2) {
                sw(j);
            }
            while (a[i] != mn) {
                sw(i);
            }
        }
        if (a[n - 2] > a[n - 1]) {
            for (int i = n - 3; i >= 0; i--) {
                sw(i);
                if (c == a) {
                    break;
                }
            }
        }
        if (a == c) {
            cout << b.size() << '\n';
            for (int i : b) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}