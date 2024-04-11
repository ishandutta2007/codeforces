#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 2e5, M = 1e6;
mt19937 rng(time(0));

int T, n;
LL k, a[N + 5], b[N+5];

int main() {
    cin >> T;

    rep(cas, 1, T) {
        scanf("%d%lld", &n,&k);
        rep(i, 1, n) scanf("%lld", a + i);
        sort(a + 1, a + n + 1);
        rep(i, 1, n-1) b[i] = a[i+1] - a[i];
        LL num = b[1];
        rep(i, 2, n - 1) num = __gcd(num, b[i]);
        //rep(i, 1, n - 1) cerr << b[i] << " ";
        //cerr << endl;

        printf((abs(k - a[1]) % num == 0) ? "YES\n" : "NO\n");
    }
    return 0;
}