#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 2e5 + 5;

int T, n;
char a[N], b[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        scanf("%s", a + 1);
        scanf("%s", b + 1);

        int na = 0, nb = 0;
        rep(i, 1, n) na += (a[i] == '1'), nb += (b[i] == '1');
        if (na == 0) {
            printf(nb == 0 ? "0\n" : "-1\n");
            continue;
        }
        if (na != nb && na + nb != n + 1) {
            printf("-1\n");
            continue;
        }

        int ans = n * 10;
        if (na == nb) {
            int cnt = 0;
            rep(i, 1, n) cnt += (a[i] == '1' && b[i] == '0');
            ans = min(ans, cnt * 2);
        }
        if (na + nb == n + 1) {
            int j = 0;
            rep(i, 1, n) if (a[i] == '1' && b[i] == '1') {
                j = i;
                break;
            }
            a[j] = '0' + '1' - a[j];
            rep(i, 1, n) a[i] = '0' + '1' - a[i];

            int cnt = 0;
            rep(i, 1, n) cnt += (a[i] == '1' && b[i] == '0');
            ans = min(ans, cnt * 2 + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}