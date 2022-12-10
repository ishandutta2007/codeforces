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


void gcd(int a, int b, int &ka, int &kb)
{
    if (b == 0)
    {
        ka = 1;
        kb = 0;
        return;
    }
    int x, y;
    gcd(b, a % b, x, y);
    ka = y;
    kb = x - a / b * y;
}

void solve() {
    int n;
    scanf("%d", &n);
    int x = 1, y = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int nn = n;
            while (nn % i == 0)
            {
                nn /= i;
                x *= i;
            }
            y = n / x;
            break;
        }
    }
    if (x == 1 || y == 1)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    printf("2\n");
    
    int kx, ky;
    gcd(x, y, kx, ky);
    kx *= -1;
    ky *= -1;
    if (kx < 0)
        kx += y;
    else if (ky < 0)
        ky += x;
    printf("%d %d\n%d %d\n", kx, y, ky, x);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}