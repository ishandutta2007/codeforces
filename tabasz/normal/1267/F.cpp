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

int n, m, a, b;
map<int, int> last;
VI V[2];
VPII R;

int32_t main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    FOR(i, 1, a)
    {
        int x;
        scanf("%d", &x);
        V[0].PB(x);
    }
    FOR(i, 1, b)
    {
        int x;
        scanf("%d", &x);
        V[1].PB(x);
    }
    if (a >= m || b >= n)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    
    FOR(i, a + 1, m - 1)
    {
        V[0].PB(1);
    }
    FOR(i, b + 1, n - 1)
    {
        V[1].PB(n + 1);
    }
    FOR(i, 0, 1)
    {
        FORD(j, SIZ(V[i]) - 1, 0)
        {
            if (last.count(V[i][j]))
            {
                continue;
            }
            last[V[i][j]] = j;
        }
    }
    set<int> secik;
    FOR(i, 1, n + m)
    {
        if (!last.count(i))
        {
            secik.insert(i);
        }
    }
    int i1 = 0, i2 = 0;
    FOR(i, 1, n + m - 2)
    {
        int v = *secik.begin();
        secik.erase(v);
        if (v <= n)
        {
            int u = V[1][i2];
            R.PB(MP(u, v));
            if (last[u] == i2)
            {
                secik.insert(u);
            }
            i2++;
        }
        else
        {
            int u = V[0][i1];
            R.PB(MP(u, v));
            if (last[u] == i1)
            {
                secik.insert(u);
            }
            i1++;
        }
    }
    R.PB(MP(*secik.begin(), n + m));
    
    for (auto x : R)
    {
        printf("%d %d\n", x.f, x.s);
    }
}