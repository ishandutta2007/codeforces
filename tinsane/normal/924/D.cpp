#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;

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

using ll = long long;

const int N = 200500;

struct Frac
{
    ll a, b;
    Frac(): a(), b(1) {}
    Frac(ll _a, ll _b): a(_a), b(_b)
    {
        if (a < 0 && b < 0)
            a = -a, b = -b;
        if (a < 0 || b <= 0)
            throw;
    }
    bool operator<(const Frac& o) const
    {
        return a * o.b < b * o.a;
    }
    bool operator==(const Frac& o) const
    {
        return a * o.b == b * o.a;
    }
};

struct FenTree
{
    ll a[N];
    FenTree(): a() {}
    void add(int v, ll x)
    {
        for (int i = v; i < N; i |= i + 1)
            a[i] += x;
    }
    ll get(int v)
    {
        ll s = 0;
        for (int i = v; i >= 0; i = (i & (i + 1)) - 1)
            s += a[i];
        return s;
    }
};

int n;
ll w;
Frac ls[N], rs[N];
vector<Frac> crd;
int perm[N];
FenTree fen;

int get_crd(const Frac& f)
{
    return lower_bound(crd.begin(), crd.end(), f) - crd.begin();
}

void solve()
{
    scanf("%d%lld", &n, &w);
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        ls[i] = Frac(-x, y - w);
        rs[i] = Frac(-x, y + w);
        crd.push_back(rs[i]);
    }

    sort(crd.begin(), crd.end());
    crd.resize(unique(crd.begin(), crd.end()) - crd.begin());

    for (int i = 0; i < n; i++)
        perm[i] = i;
    sort(perm, perm + n, [] (int a, int b)
    {
        return ls[b] < ls[a];
    });

    ll ans = 0;
    int ptr = 0;
    for (int i = 1; i <= n; i++)
        if (i == n || ls[perm[ptr]] != ls[perm[i]])
        {
            ll len = i - ptr;
            ans += len * (len - 1) / 2;
            for (int j = ptr; j < i; j++)
                ans += fen.get(get_crd(rs[perm[j]]));
            for (int j = ptr; j < i; j++)
                fen.add(get_crd(rs[perm[j]]), 1);
            ptr = i;
        }

    printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}