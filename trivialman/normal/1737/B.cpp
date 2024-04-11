#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 205;
mt19937 rng(time(0));

int T, n;
LL l, r;

inline LL calc(LL x) {
    LL q = sqrt(x);
    while ((q + 1) * (q + 1) <= x)
        q++;
    return (q - 1) * 3 + (q * q <= x) + (q * q + q <= x) + (q * q + q + q <= x);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    rep(cas, 1, T) {
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << "\n";
    }
    return 0;
}