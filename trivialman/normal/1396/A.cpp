#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e5, M = 1e6;
mt19937 rng(time(0));

int T, n;
LL a[N + 5];

int main() {
    T = 1;

    rep(cas, 1, T) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%lld", a + i);
        if (n == 1) {
            printf("1 1\n%lld\n", -a[1]);
            printf("1 1\n0\n");
            printf("1 1\n0\n");
            continue;
        }

        printf("1 1\n");
        printf("%lld\n", -a[1]);
        printf("2 %d\n", n);
        rep(i, 2, n) printf("%lld ", a[i] * (n - 1));
        printf("\n1 %d\n", n);
        printf("0 ");
        rep(i, 2, n) printf("%lld ", -a[i] * n);
        printf("\n");
    }
    return 0;
}