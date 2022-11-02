#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
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
const int MXN = 1e5+5;
int a[MXN];
int b[MXN];
int p[MXN];

int mxsuf[MXN];
int gdzie[MXN];
vector<int> V[MXN];
int main()
    {
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, n)
        {
        scanf("%d", &a[i]);
        mxsuf[i] = a[i];
        }
    REP(i, m)
        {
        scanf("%d", &b[i]);
        }
    REP(i, m)
        {
        scanf("%d", &p[i]);
        }
    
    FORD(i, n-1, 0)
        {
        maxi(mxsuf[i], mxsuf[i+1]);
        }
    REP(i, n)
        mxsuf[i] *= -1;
    mxsuf[n] = 1e9;
    //mxsuf: -9, -9, -5, -4, -2, -1 -1
//    REP(i, n)
//        cerr<<mxsuf[i]<<" ";
//    cerr<<endl;
    REP(i, m)
        {
        int x = upper_bound(mxsuf, mxsuf+n+1, -b[i]) - mxsuf - 1;
        gdzie[i] = x;
        if(x >= 0)V[x].PB(p[i]);
        }
    LL money = 0;
    multiset<int> S;
    REP(i, n)
        {
        money += a[i];
        for(auto v : V[i])
            {           
            while(v > money && S.size() && (*--S.end()) > v)
                {
                money += *--S.end();
                S.erase(--S.end());
                }
            if(v <= money)
                {
                money -= v;
                S.insert(v);
                }
            }
        }
    cout<<S.size()<<endl;
    }