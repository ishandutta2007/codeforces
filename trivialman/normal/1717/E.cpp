#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int INF = 1e9 + 1;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int n;
int p[N], phi[N];

LL lcm(int a, int b) { return 1ll * a * b / __gcd(a, b) % P; }

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) p[i] = i;
    rep(i, 2, n) if (p[i] == i)
    {
        for (int j = i + i; j <= n; j += i)
            p[j] = i;
    }
    phi[1] = 1;
    rep(i, 2, n)
    {
        int x = i;
        while (x % p[i] == 0)
            x /= p[i];
        phi[i] = phi[x] * (i / x) / p[i] * (p[i] - 1);
    }

    LL ans = 0;
    rep(m, 1, n - 1) for (int k = m + m; k < n; k += m)
        ans = (ans + 1ll * phi[k / m] * lcm(n - k, m)) % P;
    cout << ans;
    return 0;
}