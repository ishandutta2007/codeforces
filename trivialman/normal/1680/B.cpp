#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e6;
const int N = 15;
mt19937 rng(time(0));

int T, n, m;
char s[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        rep(i, 1, n) cin >> (s[i] + 1);
        int mi = 10, mj = 10;
        rep(i, 1, n) rep(j, 1, m) if (s[i][j] == 'R') mi = min(mi, i), mj = min(mj, j);
        cout << (s[mi][mj] == 'R' ? "YES\n" : "NO\n");
    }
    return 0;
}