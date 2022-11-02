#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define LL long long
#define LD long double
#define VPII vector<PII>
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " =", (x), " "
const int M = 100;

int T[M];
LL sil[M];

LL newt(int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    return sil[n] / sil[k] / sil[n - k];
}

void solve()
{
    LL n;
    scanf("%lld", &n);
    VI X;
    int tmp = 0;
    FOR(i, 0, M - 1)
    {
        T[i] = 0;
    }
    FOR(i, 2, M - 1)
    {
        if (n > 0)
        {
            tmp++;
            X.PB(n % i);
            T[n % i]++;
            n /= i;
        }
    }
    debug(tmp, X);
    LL res = 1;
    int zuz = 0;
    FORD(i, M - 1, 0)
    {
        if (T[i] == 0)
        {
            continue;
        }
        debug(tmp, zuz, i);
        debug(i, T[i], tmp - zuz - max(0, i - 1), newt(tmp - zuz - max(0, i - 1), T[i]));
        res *= newt(tmp - zuz - max(0, i - 1), T[i]);
        zuz += T[i];
    }
    LL res2 = 0;
    if (T[0] > 0)
    {
        zuz = 0;
        tmp--;
        T[0]--;
        res2 = 1;
        FORD(i, M - 1, 0)
        {
            if (T[i] == 0)
            {
                continue;
            }
            debug(tmp, zuz, i);
            debug(i, T[i], tmp - zuz - max(0, i - 1), newt(tmp - zuz - max(0, i - 1), T[i]));
            res2 *= newt(tmp - zuz - max(0, i - 1), T[i]);
            zuz += T[i];
        }
    }
    printf("%lld\n", res - res2 - 1);
}

int32_t main()
{
    sil[0] = 1;
    FOR(i, 1, M - 1)
    {
        sil[i] = sil[i - 1] * i;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
}