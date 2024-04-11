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
        string s;
        cin >> n >> s;
        function<int(int, int, char)> solve = [&](int x, int y, char c) {
            if (x == y) {
                return (s[x] == c ? 0 : 1);
            }
            int d = (y - x + 1) / 2 - 1;
            int a = solve(x, x + d, c + 1);
            for (int i = y - d; i <= y; i++) {
                if (s[i] != c) {
                    a++;
                }
            }
            int b = solve(y - d, y, c + 1);
            for (int i = x; i <= x + d; i++) {
                if (s[i] != c) {
                    b++;
                }
            }
            return min(a, b);
        };
        cout << solve(0, n - 1, 'a') << '\n';
    }
    return 0;
}