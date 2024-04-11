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
    map<pair<int, int>, int> a;
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        if (h > w) {
            swap(h, w);
        }
        if (h != w) {
            a[make_pair(h, w)]++;
        }
        b[h]++;
        if (h != w) {
            b[w]++;
        }
    }
    long long ans = 0;
    for (auto [k, v] : a) {
        ans -= 1LL * v * (v - 1) / 2;
    }
    for (auto [k, v] : b) {
        ans += 1LL * v * (v - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}