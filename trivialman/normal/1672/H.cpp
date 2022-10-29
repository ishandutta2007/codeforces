#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 2e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q, l, r;
int num[4][N], li[N], ri[N], tmp[4];
char s[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    cin >> (s + 1);
    int last = 1;
    rep(i, 1, n) if (s[i] == s[i + 1] || i == n) {
        rep(j, last, i) {
            rep(k, 0, 3) num[k][j] = num[k][last - 1];
            num[(s[last] - '0') << 1 | (s[j] - '0')][j]++;
            li[j] = last, ri[j] = i;
        }
        last = i + 1;
    }
    while (q--) {
        cin >> l >> r;
        int ans = 0;
        memset(tmp, 0, sizeof tmp);
        rep(k, 0, 3) tmp[k] = num[k][r] - num[k][ri[l - 1]];
        if (li[l] != l)
            tmp[(s[l] - '0') << 1 | (s[ri[l]] - '0')]++;
        int a = tmp[0], b = tmp[1], c = tmp[2], d = tmp[3];
        ans = a + b + c + d - min(a, d) - min(b, c);
        if (b == c && b > 0) 
            ans += a == d ? 1 : s[l] == (a > d ? '1' : '0');
        cout << ans << "\n";
    }
    return 0;
}