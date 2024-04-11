#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n;
int x[5], y[5];

bool check(int a, int b) {
    int cntx = 0, cnty = 0;
    rep(i, 1, 3) cntx += x[i] == a, cnty += y[i] == b;
    return cntx == 2 && cnty == 2;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    rep(cas, 1, T) {
        cin >> n;
        rep(i, 1, 4) cin >> x[i] >> y[i];
        int xx = 0, yy = 0;
        if (check(1, 1))
            xx = yy = 1;
        if (check(1, n))
            xx = 1, yy = n;
        if (check(n, 1))
            xx = n, yy = 1;
        if (check(n, n))
            xx = n, yy = n;

        bool flag = false;
        if (xx) {
            flag = x[4] == xx || y[4] == yy;
        } else {
            rep(i, 1, 3) if (x[4] % 2 == x[i] % 2 && y[4] % 2 == y[i] % 2) flag = true;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}