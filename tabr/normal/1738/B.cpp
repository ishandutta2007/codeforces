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
        int n, k;
        cin >> n >> k;
        vector<long long> s(k);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }
        vector<long long> a;
        for (int i = 0; i < k - 1; i++) {
            a.emplace_back(s[i + 1] - s[i]);
        }
        if (!is_sorted(a.begin(), a.end())) {
            cout << "No" << '\n';
            continue;
        }
        string ans = "Yes";
        k = n - k + 1;
        if (!a.empty() && s[0] > a[0] * k) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}