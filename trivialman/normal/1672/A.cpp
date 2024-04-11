#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 25;
mt19937 rng(time(0));

int T, n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        int tot = 0;
        rep(i, 1, n) cin >> x, tot += x - 1;
        cout << (tot % 2 ? "errorgorn" : "maomao90") << "\n";
    }
    return 0;
}