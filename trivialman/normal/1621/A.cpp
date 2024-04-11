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

int T, n, k;
char s[N][N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k * 2 >= n + 2)
            cout << "-1\n";
        else {
            rep(i, 1, n) {
                rep(j, 1, n) s[i][j] = '.';
                s[i][n + 1] = 0;
            }
            rep(i, 1, k) s[i * 2 - 1][i * 2 - 1] = 'R';
            rep(i, 1, n) cout << (s[i] + 1) << endl;
        }
    }
    return 0;
}