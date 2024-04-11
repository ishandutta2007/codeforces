#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " = " << x << endl
#define print_array(arr, len) {cerr << #arr << " = "; for (int i = 0; i < len; i++) cerr << arr[i] << " "; cerr << endl;}
#define print_iterable(it) {cerr << #it << " = "; for (const auto &e : it) cerr << e << " "; cerr << endl;}
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) (void)0
#define print_iterable(it) (void)0
#endif

typedef long long ll;
const int N = 200500;

int n, m;
bool black[N];
vector<int> divs;
int phi[N];
vector<int> go[N];
vector<int> good[N];
int dp[N], par[N];
int powers[N];

int gcd(int x, int y)
{
    if (x != 0)
        return gcd(y % x, x);
    return y;
}

int mul(int a, int b, int mod)
{
    return (ll)a * b % mod;
}

int sub(int a, int b, int mod)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int bin_pow(int a, int b, int mod)
{
    int c = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            c = mul(c, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return c;
}

vector<int> get_primes(int d)
{
    vector<int> primes;
    for (int i = 2; i * i <= d; i++)
        if (d % i == 0)
        {
            while (d % i == 0)
                d /= i;
            primes.push_back(i);
        }
    if (d > 1)
        primes.push_back(d);
    return primes;
}

int totient(int d)
{
    auto primes = get_primes(d);
    int res = d;
    for (int p : primes)
        res -= res / p;
    return res;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        black[x] = true;
    }

    for (int d = 1; d * d <= m; d++)
        if (m % d == 0)
        {
            divs.push_back(d);
            if (d * d != m)
                divs.push_back(m / d);
        }
    sort(divs.begin(), divs.end());

    for (int i = 0; i < (int)divs.size(); i++)
        for (int j = i + 1; j < (int)divs.size(); j++)
            if (divs[j] % divs[i] == 0)
                go[divs[i]].push_back(divs[j]);

    for (int d : divs)
    {
        for (int x = 1; x < m / d; x++)
            if (gcd(x, m / d) == 1 && !black[x * d])
                good[d].push_back(x);
    }

    for (int d : divs)
    {
        dp[d] += (int)good[d].size();
        for (int to : go[d])
            if (dp[to] < dp[d])
            {
                dp[to] = dp[d];
                par[to] = d;
            }
    }

    vector<int> path;
    for (int v = m; ; )
    {
        path.push_back(v);
        if (v == 1)
            break;
        v = par[v];
    }
    reverse(path.begin(), path.end());

    vector<int> ans;
    int cur = 1;

    for (int it = 0; it < (int)path.size(); it++)
    {
        int d = path[it];
        if (m / d == 1)
            continue;
        int tot = totient(m / d);

        int ml = it == 0 ? 1 : d / path[it - 1];
        cur %= m / d;
        for (int z : good[d])
        {
            int w = mul(ml, mul(z, bin_pow(cur, tot - 1, m), m), m);
            ans.push_back(w);
            cur = z;
            ml = 1;
        }
    }

    if (!black[0])
        ans.push_back(0);

    printf("%d\n", (int)ans.size());
    cur = 1;
    for (int x : ans)
    {
        cur = mul(cur, x, m);
        if (black[cur])
        {
            print_iterable(ans);
            throw;
        }
        black[cur] = true;
        printf("%d ", x);
    }
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}