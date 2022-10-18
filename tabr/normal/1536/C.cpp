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
        int a = 0, b = 0;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                a++;
            } else {
                b++;
            }
            int g = __gcd(a, b);
            int x = a / g, y = b / g;
            cout << ++mp[make_pair(x, y)] << " ";
        }
        cout << '\n';
    }
    return 0;
}