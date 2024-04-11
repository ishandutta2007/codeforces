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

int T, n;
char s[N], t[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> (s + 1);
        rep(i, 1, n) t[i] = s[i];
        sort(t + 1, t + n + 1);
        int ans = 0;
        rep(i, 1, n) ans += (s[i] != t[i]);
        cout << ans << endl;
    }
    return 0;
}