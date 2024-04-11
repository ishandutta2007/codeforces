#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long LL;
const int N = 1e5 + 5;

int T, n;
LL a, b, c, x[N];
char s[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%lld%lld%lld", &n, &a, &b, &c);
        scanf("%s", s + 1);

        LL n0 = 0, n1 = 0, na = 0, nb = 0;
        rep(i, 1, n) {
            (s[i] == '0') ? n0++ : n1++;
            if (i >= 2 && s[i] == s[i - 1])
                (s[i] == '0') ? na++ : nb++;
        }

        LL ans = 0;
        if (b <= c) {
            ans = min(na, nb) * (a + b) + (na > nb) * a + (nb > na) * b;
        } else {
            if (n0 < n1) {
                if (n1 > n0 + 1)
                    ans = (n0 + 1) * b + na * a - (n0 - na) * c;
                else if (s[1] == '1' && s[n] == '1')
                    ans = n0 * b + na * a - (n0 - na) * c;
                else
                    ans = n0 * b + na * a - (n0 - na - 1) * c;
            } else if (n0 == n1 && s[1] == '0' && s[n] == '0') {
                ans = (n0 - 1) * b + na * a - (n0 - 2 - na) * c;
            } else {
                int idx = 0;
                rep(i, 1, n) if (s[i] == '0') {
                    int j = i;
                    while (j <= n && s[j] == '0')
                        j++;
                    x[++idx] = j - i;
                    i = j;
                }
                int start = (s[1] == '0') ? 2 : 1, end = (s[n] == '0') ? idx - 1 : idx;
                bool flag = true;
                if (start <= end) {
                    sort(x + start, x + end + 1);
                    rep(i, start, end) {
                        if (nb >= x[i] - 1) {
                            nb -= (x[i] - 1), na -= (x[i] - 1);
                            ans += (x[i] - 1) * (a + b) + b - c;
                        } else {
                            ans += nb * b + (nb + 1) * a;
                            nb = 0, na = 0;
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                    ans += nb * (a + b) + (na > nb) * a;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}