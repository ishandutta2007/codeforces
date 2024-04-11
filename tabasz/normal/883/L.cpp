#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define F first
#define S second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
const int MXN = 2e5+5;

int n, m, k;
set<pair<LL, int>> t[MXN];
set<int> where_taxi;

//set<pair<LL, PII>> event_input;
set<pair<LL, PII>> event_free;

LL acttime = 0;
void add(pair<LL, PII> x)
    {
    int where = x.s.f;
    int who = x.s.s;
    LL time = x.f;
    maxi(acttime, time);
    where_taxi.insert(where);
    t[where].insert(MP(time, who));
    }
    
void go(int where, LL time, int a, int b)
    {
    int taxi = t[where].begin()->s;
    t[where].erase(t[where].begin());
    if(t[where].size() == 0)
        where_taxi.erase(where);
    
    printf("%d %lld\n", taxi, abs(where - a) + acttime - time);
    event_free.insert(MP(acttime + abs(where-a) + abs(a-b), MP(b, taxi)));
    }
int main()
    {
    scanf("%d%d%d", &n, &k, &m);
    FOR(i, 1, k)
        {
        int a;
        a = rand() % n + 1;
        scanf("%d", &a);
        event_free.insert(MP(0, MP(a, i)));
        }

    REP(i, m)
        {
        LL tt;
        int a, b;
        tt = 100000000LL * i + 3;
        a = rand() % n + 1;
        b = rand() % n + 1;
        scanf("%lld%d%d", &tt, &a, &b);
        maxi(acttime, tt);
        while(event_free.size() && (event_free.begin()->f <= acttime || where_taxi.size() == 0))
            {
            add(*event_free.begin());
            event_free.erase(event_free.begin());
            }
        if(where_taxi.size() == 1)
            {
            go(*where_taxi.begin(), tt, a, b);
            }
        else
            {
            auto x = where_taxi.upper_bound(a);
            if(x == where_taxi.end())x--;
            if(x == where_taxi.begin())
                {
                go(*x, tt, a, b);
                continue;
                }
            auto x2 = x; x2--;
            int p = *x;
            int l = *x2;
            
            if((abs(a-l) < abs(a-p))
               || ((abs(a-l) == abs(a-p) && (*(t[l].begin()) < *(t[p].begin())))))
                go(l, tt, a, b);
            else
                go(p, tt, a, b);
            }
        }

    
    }