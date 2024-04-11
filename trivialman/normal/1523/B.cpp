#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e4 + 5;
mt19937 rng(time(0));

int T, n;
int a[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", a + i);
        printf("%d\n", n * 3);
        for (int i = 1; i <= n; i += 2) {
            printf("1 %d %d\n", i, i + 1);
            printf("2 %d %d\n", i, i + 1);
            printf("1 %d %d\n", i, i + 1);
            printf("1 %d %d\n", i, i + 1);
            printf("2 %d %d\n", i, i + 1);
            printf("1 %d %d\n", i, i + 1);
        }
    }
    return 0;
}