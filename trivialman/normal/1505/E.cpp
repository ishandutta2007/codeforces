#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int n, m;
char s[9][9];

int main() {
    cin >> n >> m;
    rep(i, 1, n) cin >> (s[i] + 1);

    int x = 1, y = 1, ans = 0;
    ans += (s[1][1] == '*');
    while (true) {
        int dist2 = 123456, x1 = 0, y1 = 0;
        rep(i, x, n) rep(j, y, m) if ((i > x || j > y) && s[i][j] == '*') {
            int d2 = (i - x) * (i - x) + (j - y) * (j - y);
            if (d2 < dist2)
                x1 = i, y1 = j, dist2 = d2;
        }
        if (!x1)
            break;
        else
            ans++, x = x1, y = y1;
    }
    cout << ans << endl;
    return 0;
}