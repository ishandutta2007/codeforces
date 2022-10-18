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
    /*
    vector<vector<vector<int>>> memo(110, vector<vector<int>>(110, vector<int>(2, -1)));
    memo[0][0][0] = 0;
    memo[0][0][1] = 1;
    function<bool(int, int, int)> Solve = [&](int c0, int c1, int me) {
        if (!memo[c0][c1][me] != -1) {
            return memo[c0][c1][me];
        } else if (c0 != 0 && c1 != 0) {
            return memo[c0][c1][me] = max(Solve(c0 - 1, c1, ) ^ 1, Solve(c0, c1 - 1, ) ^ 1);
        } else if (c0 != 0) {
            return memo[c0][c1][me] = Solve(c0 - 1, c1, ) ^ 1;
        } else {
            return memo[c0][c1][me] = Solve(c0, c1 - 1, ) ^ 1;
        }
    };
    */
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= 2;
            a[i] += 2;
            a[i] %= 2;
        }
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                c1++;
            } else {
                c0++;
            }
        }
        if (n % 2 == 0) {
            if (c1 % 4 != 2) {
                cout << "Alice" << '\n';
            } else {
                cout << "Bob" << '\n';
            }
        } else {
            if (c1 % 4 == 3 || c1 % 4 == 0) {
                cout << "Alice" << '\n';
            } else {
                cout << "Bob" << '\n';
            }
        }
    }
    return 0;
}