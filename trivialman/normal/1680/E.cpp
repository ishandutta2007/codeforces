#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 5e15 + 5;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, k;
int f[2][N];
char s[2][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> (s[0] + 1);
        cin >> (s[1] + 1);
        bool chip = false;
        rep(i, 1, n) {
            f[0][i] = f[0][i - 1] + chip + (s[1][i] == '*');
            f[1][i] = f[1][i - 1] + chip + (s[0][i] == '*');
            if (s[0][i] == '*' && s[1][i] == '*') {
                f[0][i] = f[1][i] = min(f[0][i], f[1][i]);
            } else {
                f[0][i] = min(f[0][i], f[1][i] + 1);
                f[1][i] = min(f[0][i] + 1, f[1][i]);
            }
            chip |= s[0][i] == '*' || s[1][i] == '*';
            //cerr << i << " " << f[0][i] << " " << f[1][i] << endl;
        }
        //cerr << endl;
        int ans = 0;
        rrep(i, n, 1) if (s[0][i] == '*' || s[1][i] == '*') {
            ans = min(f[0][i], f[1][i]);
            break;
        }
        cout << ans << "\n";
    }
    return 0;
}