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
#define siz(c) SIZ(c)
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
const int MXN = 2e6+6;
int cnt[MXN];
int res[MXN];

void solve()
    {
    int n;
    scanf("%d", &n);
    FOR(i, 1, n)cnt[i] = 0;
    FOR(i, 1, n+1)res[i] = 0;
    FOR(i, 1, n)
        {
        int a;
        scanf("%d", &a);
        cnt[a]++;
        }
    int mx_res = 1e9;
    FOR(i, 1, n)
        {
        if(cnt[i] == 0)continue;
        FOR(siz, 1, cnt[i]+1)
            {
            int x;
            if(cnt[i] % siz == 0)x = cnt[i] / siz;
            else 
                {
                x = cnt[i] / siz + 1;
                if(x * (siz -1) > cnt[i])x = 1e9;
                }
            res[siz] += x;
            mini(res[siz], inf);
            }
        mini(mx_res, cnt[i]+1);
        }
    int best = 1e9;
    FOR(i, 1, mx_res)
        {
        mini(best, res[i]);
        }
    printf("%d\n", best);
    }

int main()
    {
    int z;
    scanf("%d", &z);
    while(z--)solve();
    }