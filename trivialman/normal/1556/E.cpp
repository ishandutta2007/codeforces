#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

struct dat {
    LL min, max;
} b[20][N];
int T, n, q, l, r, lg2[N];
LL a[N], x;

LL getmax(int l, int r) {
    int i = lg2[r - l];
    return max(b[i][l].max, b[i][r - (1 << i) + 1].max);
}
LL getmin(int l, int r) {
    int i = lg2[r - l];
    return min(b[i][l].min, b[i][r - (1 << i) + 1].min);
}

int main() {
    cin >> n >> q;
    rep(i, 1, n) scanf("%lld", a + i);
    rep(i, 1, n) scanf("%lld", &x), a[i] -= x;
    rep(i, 2, n) a[i] += a[i - 1];

    rep(i, 2, n) lg2[i] = lg2[i >> 1] + 1;

    rep(j, 1, n) b[0][j] = {a[j], a[j]};
    rep(i, 1, lg2[n]) rep(j, 1, n - (1 << i - 1)) {
        b[i][j].max = max(b[i - 1][j].max, b[i - 1][j + (1 << i - 1)].max);
        b[i][j].min = min(b[i - 1][j].min, b[i - 1][j + (1 << i - 1)].min);
    }

    rep(i, 1, q) {
        scanf("%d%d", &l, &r);
        if (a[l - 1] != a[r] || getmax(l, r - 1) > a[r]) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", a[r] - getmin(l, r - 1));
    }
    return 0;
}