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
    int t = 1;
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (__gcd(i, n) == 1) {
            ans.emplace_back(i);
            t = (int)(1LL * t * i % n);
        }
    }
    if (t != 1) {
        for (int i = 0; i < (int)ans.size(); i++) {
            if (t == ans[i]) {
                ans.erase(ans.begin() + i);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}