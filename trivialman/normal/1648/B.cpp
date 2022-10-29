#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 1e6 + 5;
mt19937 rng(time(0));

int T, n, c, x;
int a[N], s[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> c;
        rep(i, 1, n) cin >> x, a[x] = 1;
        rep(i, 1, c) s[i] = s[i - 1] + a[i];

        bool flag = true;
        rep(y, 1, c) if (a[y]) {
            rep(z, 1, c / y) if (!a[z] && s[y * z - 1] != s[min(y * (z + 1) - 1, c)]) {
                flag = false;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");

        rep(i, 1, c) a[i] = s[i] = 0;
    }
    return 0;
}