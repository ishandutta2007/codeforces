#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;


const int D = 7;
int a[2*D];

void solve() {
    int k;
    scanf("%d", &k);
    int suma = 0;
    for (int i = 0; i < D; i++)
    {
        scanf("%d", &a[i]);
        a[D + i] = a[i];
        suma += a[i];
    }
    int kx = (k - 1) % suma + 1;
    int ans = (k - kx) / suma * 7;

    int mn = D;
    for (int i = 0; i < D; i++)
    {
        int cur = 0;
        for (int j = i; j < 2 * D; j++)
        {
            cur += a[j];
            if (cur == kx)
                mn = min(mn, j - i + 1);
        }
    }
    ans += mn;

    printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif


    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}