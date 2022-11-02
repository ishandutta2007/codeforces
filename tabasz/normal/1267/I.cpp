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

int R(int a, int b){return rand()%(b-a+1)+a;}

VI seq;
int _n;
VPII que;
int get_n()
    {
    #ifdef DEB
    seq.clear();
    que.clear();
    _n = 3;//R(3, 4);
    REP(i, _n * 2)seq.PB(i+1);
    random_shuffle(ALL(seq));

    debug(seq);
    return _n;
    #endif

    cin >> _n;
    return _n;
    }

int query(int a, int b) // czy a < b
    {
//    debug(a, b);
     assert(a != b);
    
    #ifdef DEB
    assert(1 <= a && a <= 2 * _n);
    assert(1 <= b && b <= 2 * _n);
    que.PB(MP(a-1, b-1));
    
    return seq[a-1] < seq[b-1];
    
    #endif
    
    cout << "? " << a << " " << b << endl;
    fflush(stdout);
    char ans;
    cin >> ans;
    return ans == '<';
    }
int bigger(int a, int b)
    {
    if(a == 0)return b;
    if(b == 0)return a;
    
    if(query(a, b) == 0)return a;
    return b;
    }
int smaller(int a, int b)
    {
    if(a == 0)return b;
    if(b == 0)return a;
    
    
    if(query(a, b) == 1)return a;
    return b;
    }
set<VI> bad;
void end()
    {
    #ifdef DEB
    set<VI> S_big;
    set<VI> S_big_m;
    VI V;
    REP(i, 2*_n)V.PB(i+1);
    do
        {
        bool ok = 1;
        for(auto i: que)
            {
            if((seq[i.f] < seq[i.s]) != (V[i.f] < V[i.s]))ok = 0;
            }
        if(ok)
            {
            VI pos_big;
            VI pos_big2;
            REP(i, 2 *_n)
                if(V[i] > _n)
                  {
                  pos_big.PB(i);
                  pos_big2.PB(V[i]);
                  }
            S_big.insert(pos_big);
            S_big_m.insert(pos_big2);
            }
        }
    while(next_permutation(ALL(V)));
    
    assert(S_big.size() == 1);
    debug(I(S_big_m.size()));
    
    if(S_big_m.size() == 1)
        bad.insert(seq);
    debug(bad.size(), bad);
    assert(S_big_m.size() != 1);
    que.clear();
    return;
    #endif
    
    cout << "!" << endl;
    fflush(stdout);
    }


void solve3()
{
    VPII V;
    FOR(i, 1, 3)
    {
        PII x = MP(i, i + 3);
        if (query(x.s, x.f))
        {
            swap(x.f, x.s);
        }
        V.PB(x);
    }
    if (query(V[1].f, V[0].f))
    {
        swap(V[1], V[0]);
    }
    if (query(V[2].f, V[1].f))
    {
        swap(V[2], V[1]);
    }
    if (query(V[1].f, V[0].f))
    {
        swap(V[1], V[0]);
    }
    PII x = V[2];
    PII y = MP(V[1].s, V[0].s);
    if (query(y.s, y.f))
    {
        swap(y.f, y.s);
    }
    query(x.f, y.f);
    end();
}

const int BASE = 256;
int t[BASE*2];
void solve()
    {
    int n = get_n();

    if(n == 3)
        {
        solve3();
        return;
        }


    VI V;
    FOR(i, 1, 2*n)V.PB(i);
    random_shuffle(ALL(V)); // TODO
    
    REP(i, 2*BASE)t[i] = 0;
    REP(i, 2*n)t[i+BASE] = V[i];
    
    
    debug(V);
    FORD(i, BASE-1, 1)
        {
        t[i] = smaller(t[i*2], t[i*2+1]);
//        if(t[i])debug(t[i*2], t[i*2+1]);
        }
    
    VI biggest;
    REP(i, n)
        {
        int id = 1;
        while(id < BASE)
            {
            if(t[id*2] == t[id])
                {
                id = id * 2;
                }
            else 
                {
                assert(t[id*2+1] == t[id]);
                id = id *2 + 1;
                }
            }
        debug(id, t[id]);
        biggest.PB(t[id]);
        
        if(i + 1 == n)break;
        
        t[id] = 0;
        id /= 2;
        while(id)
            {
            t[id] = smaller(t[id*2], t[id*2+1]);
            id /= 2;
            }
        }
//    for(auto i: biggest)
//        for(auto j: biggest)
//            if(i < j)bigger(i, j);
    debug(biggest);
    end();
    }


int main()
    {
    srand(5111);
    int z;
    cin >> z;
    while(z--)
        {
        debug(I(z));
        solve();
        }
    }