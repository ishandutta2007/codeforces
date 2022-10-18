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
        int n;
        long long x;
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        map<long long, vector<long long>> mp;
        for (int i = 0; i < n; i++) {
            long long b = 0;
            while (a[i] % x == 0) {
                a[i] /= x;
                b++;
            }
            mp[a[i]].emplace_back(b);
        }
        int ans = 0;
        for (auto [_, v] : mp) {
            multiset<long long> s;
            for (auto i : v) {
                if (s.count(i - 1)) {
                    s.erase(s.find(i - 1));
                } else {
                    s.emplace(i);
                }
            }
            ans += (int) s.size();
        }
        cout << ans << '\n';
    }
    return 0;
}