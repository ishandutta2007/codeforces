#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e6;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, s[N];
char a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> (a + 1);
        n = strlen(a + 1);
        rep(i, 1, n) s[i] = a[i] - '0';
        rep(i, 1, n) s[i] += s[i - 1];
        int n1 = s[n],ans = 0;
        rep(i, n1, n) ans = max(ans, s[i] - s[i - n1]);
        cout << n1 - ans << "\n";
    }
    return 0;
}