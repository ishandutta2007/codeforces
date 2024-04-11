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
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        while (__builtin_popcount(cnt) != 6) {
            cnt++;
        }
        s[i] = cnt;
        cnt++;
    }
    vector<ll> x(13);
    for (int i = 0; i < 13; i++) {
        vector<int> ask;
        for (int j = 0; j < n; j++) {
            if (s[j] & (1 << i)) {
                ask.emplace_back(j + 1);
            }
        }
        if (ask.empty()) {
            continue;
        }
        cout << "? " << ask.size() << " ";
        for (int j : ask) {
            cout << j << " ";
        }
        cout << endl;
        cin >> x[i];
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        ll p = 0;
        for (int j = 0; j < 13; j++) {
            if (s[i] & (1 << j)) {
                continue;
            }
            p |= x[j];
        }
        cout << p << " ";
    }
    cout << endl;
    return 0;
}