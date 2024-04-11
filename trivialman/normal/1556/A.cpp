#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 105;
mt19937 rng(time(0));

int T, c, d;

int main() {
    cin >> T;
    while (T--) {
        cin >> c >> d;
        int res = (c + d) % 2 == 1 ? -1 : (c == d ? c != 0 : 2);
        cout << res << endl;
    }
    return 0;
}