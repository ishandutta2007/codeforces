#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n;
char s[N], t[N];
int nxt[N][26], pos[26], base[26], tr[N];

void add(int x, int val) {
    for (; x <= n; x += x & -x)
        tr[x] += val;
}
int get(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += tr[x];
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        rep(i, 0, 25) nxt[n + 1][i] = n + 1;
        rrep(i, n, 1) {
            rep(j, 0, 25) nxt[i][j] = nxt[i + 1][j];
            nxt[i][s[i] - 'a'] = i;
        }

        rep(j, 0, 25) pos[j] = nxt[1][j];
        rep(i, 0, n) tr[i] = 0;
        rep(i, 1, n) add(i, 1);

        LL ans = INF, cnt = 0;
        rep(i, 1, n) {
            int x = t[i] - 'a';
            rep(j, 0, x - 1) if (pos[j] <= n) ans = min(ans, cnt + get(pos[j]) - 1);
            if (pos[x] > n)
                break;
            cnt += get(pos[x]) - 1, add(pos[x], -1), pos[x] = nxt[pos[x] + 1][x];
        }
        printf("%lld\n", ans == INF ? -1 : ans);
    }
    return 0;
}