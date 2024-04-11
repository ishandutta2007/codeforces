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
#define PLL pair<LL, LL>


int main()
    {
    int n;
    scanf("%d", &n);
//    queue<pair<LL, PLL>, vector<pair<LL, PLL>>, greater<pair<LL, PLL>>> konce; 
    // first_kon, t, end
    
    
    vector<pair<LL, LL>> events;
    
    FOR(i, 1, n)
        {
        LL poc, kon, t;
        scanf("%lld%lld%lld", &poc, &kon, &t);
        events.PB(MP(poc, t));
        events.PB(MP(kon-t+1, -t));
        }
    sort(ALL(events));
    
    vector<pair<PLL, LL>> minis; // (a, b), min_czas
    
    multiset<LL> S;
    LL pop_time = events[0].f;
    for(auto i: events)
        {
        if(S.size() && pop_time < i.f)
            minis.PB(MP(MP(pop_time, i.f-1), *S.begin()));

        if(i.s > 0)S.insert(i.s);
        else S.erase(S.find(-i.s));
        pop_time = i.f;
        }
    debug(minis);
    
    vector<LL> mipra(minis.size()+1, (LL)2e18);
    
    FORD(i, minis.size()-1, 0)
        {
        mipra[i] = min(mipra[i+1], minis[i].f.f + minis[i].s);
        }
    
    LL jestem = 0;
    LL res = 0;
    REP(i, minis.size())
        {
        maxi(jestem, minis[i].f.f);
        if(jestem > minis[i].f.s)continue;
        
        if(jestem + minis[i].s > mipra[i+1])continue;


        LL razy = (minis[i].f.s - jestem) / minis[i].s;
        
        debug(I(jestem), I(razy), I(minis[i]));
        
        res += razy;
        jestem += razy * minis[i].s;
        
        if(jestem + minis[i].s > mipra[i+1])continue;
        
        debug(I(jestem), "razy =", 1, I(minis[i]));
        res++;
        jestem += minis[i].s;
        }
    printf("%lld\n", res);
        
    }