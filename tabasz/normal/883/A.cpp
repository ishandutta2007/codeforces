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
LL N, A, m, D;
set<LL> S;

pair<LL, LL> konrad(LL lkon, LL x)//zwraca ile przedziaw, koniec ostatniego otwartego przed x
    {
    LL first = A * (lkon / A + 1);
    if (first >= x)
    return MP(0, lkon);
    
    
    LL s = A * (D / A + 1);
    LL ile = (x - first) / s;
    if (first + s * ile > x)
        return MP(ile, first + s * (ile - 1) + D);
    else
        return MP(ile + 1, first + s * ile + D);
         
    }

int main()
    {
    scanf("%lld%lld%lld%lld", &N, &m, &A, &D);
    REP(i, m)
        {
        LL a;
        scanf("%lld", &a);
        S.insert(a);
        }
    S.insert(N*A);
    
    LL lkon = 0;
    LL result = 0;
    while(1)
        {
//        cerr<<lkon<<endl;
        while(S.size() && *S.begin() <= lkon)S.erase(S.begin());
        if(S.size() == 0 && lkon >= N*A)break;
        
        auto x = konrad(lkon, *S.begin()); // set nie pusty bo dodaem N*A
        if(x.f == 0 || *S.begin() > N*A)
            {
            result++;
            lkon = *S.begin() + D;
            }
        else
            {
//            cerr<<lkon<<" "<<*S.begin()<<" | "<<x.f<<" "<<x.s<<endl;
            
            result += x.f;
            lkon = x.s;
            }
        }
    cout<<result<<endl;
    }