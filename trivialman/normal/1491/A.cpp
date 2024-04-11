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

int n, q, t, x, cnt1;
int a[N];

int main() {
    scanf("%d%d", &n, &q);
    rep(i, 1, n) scanf("%d", a + i), cnt1 += a[i];
    rep(i, 1, q) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            cnt1 = cnt1 - a[x] + (1 - a[x]);
            a[x] = 1 - a[x];
        }else{
            printf(x <= cnt1 ? "1\n" : "0\n");
        }
    }
    return 0;
}