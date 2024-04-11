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
    auto Solve = [&](long long x) {
        if (x == 0) {
            return 0LL;
        }
        long long r = llround(floorl(sqrtl(x)));
        long long res = 3 * (r - 1);
        if (r * r <= x) {
            res++;
        }
        if (r * r + r <= x) {
            res++;
        }
        if (r * r + r + r <= x) {
            res++;
        }
        return res;
    };
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        cout << Solve(r) - Solve(l - 1) << '\n';
    }
    return 0;
}