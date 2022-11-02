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
const int M = 101;

int n;
LD x, res;
LD dp[M][M * M], C[M], sum;

int32_t main()
{
    scanf("%d%Lf", &n, &x);
    x /= 2;
    FOR(i, 0, n - 1)
    {
        C[i] = x * (2 * n - i) / (n - i);
    }
    dp[0][0] = 1;
    FOR(i, 1, n)
    {
        int a;
        scanf("%d", &a);
        res += a;
        sum += a;
        FORD(j, i - 1, 0)
        {
            FORD(k, M * M - a - 1, 0)
            {
                dp[j + 1][k + a] += dp[j][k] / (n - j) * (j + 1);
            }
        }
    }
    debug(res);
    FOR(i, 0, n - 1)
    {
        FOR(j, 0, M * M - 1)
        {
            if ((sum - j) / (n - i) > C[i])
            {
                //debug(i, j, dp[i][j]);
                res -= dp[i][j] * ((sum - j) / (n - i) - C[i]);
            }
        }
    }
    printf("%.10Lf\n", res);
}