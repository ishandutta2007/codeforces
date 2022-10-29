#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 205;
mt19937 rng(time(0));

int T, n, k, x, y, p[N], unmatch[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        memset(p, 0, sizeof p);
        rep(i, 1, k) {
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            p[y] = x, p[x] = -1;
        }

        int m = 0;
        rep(i, 1, 2 * n) if (!p[i])
            unmatch[++m] = i;
        rep(i, 1, m / 2) {
            int x = unmatch[i], y = unmatch[i + m / 2];
            p[x] = -1, p[y] = x;
        }

        //rep(i, 1, 2 * n) cerr << p[i] << " ";
        //cerr << endl;
        int ans = 0;
        rep(i, 1, 2 * n) if (p[i] > 0) {
            rep(j, p[i] + 1, i - 1) ans += (p[j] > 0 && p[j] < p[i]);
        }
        cout << ans << endl;
    }
    return 0;
}