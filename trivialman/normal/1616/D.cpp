#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 2e11;
const int N = 5e4 + 5;
mt19937 rng(time(0));

int T, n, x;
LL a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) scanf("%lld", a + i);
        cin >> x;
        rep(i, 1, n) a[i] -= x;
        rep(i, 1, n) a[i] += a[i - 1];

        int j = 1, ans = 0;
        while (j <= n) {
            LL ma = a[j - 1];
            rep(i, j + 1, n) {
                if (a[i] < ma) {
                    ans += i - j;
                    j = i + 1;
                    break;
                }
                ma = max(ma, a[i - 1]);
                if (i == n) {
                    ans += i + 1 - j;
                    j = i + 1;
                    break;
                }
            }
            if (j == n)
                ans++, j++;
        }
        cout << ans << endl;
    }
    return 0;
}