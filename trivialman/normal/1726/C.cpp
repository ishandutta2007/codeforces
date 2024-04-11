#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 9e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n;
int stk[N];
char s[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n, n <<= 1;
        cin >> (s + 1);
        int x = 0, ans = 0;
        stk[0] = 1;
        rep(i, 1, n) if (s[i] == '(') {
            x++, stk[x] = 1;
        }
        else {
            x--, ans += stk[x], stk[x] = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}