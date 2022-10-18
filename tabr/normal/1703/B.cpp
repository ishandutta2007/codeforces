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
        cin >> n;
        string s;
        cin >> s;
        int ans = (int) s.size();
        sort(s.begin(), s.end());
        s.resize(unique(s.begin(), s.end()) - s.begin());
        ans += (int) s.size();
        cout << ans << '\n';
    }
    return 0;
}