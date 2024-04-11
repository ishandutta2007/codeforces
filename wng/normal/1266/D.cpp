#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

int main(){
    DRII(n,m);
    VL td(n);
    REP(i,m){
        DRIII(u,v,d);
        u--;v--;
        td[u]+=d;
        td[v]-=d;
    }
    vector<pair<LL,int>> tds(n);
    REP(i,n){
        tds[i]={td[i],i};
    }
    sort(ALL(tds));
    int ib=0;
    int ie=n-1;
    vector<pair<LL,PII>> cdebts(0);
    while (tds[ib].F<0){
        //cout<<ib<<" "<<ie<<endl;
        if (-tds[ib].F<tds[ie].F){
            cdebts.PB({-tds[ib].F,{tds[ie].S,tds[ib].S}});
            tds[ie].F+=tds[ib].F;
            ib++;
        }
        else{
            if (-tds[ib].F>tds[ie].F){
                cdebts.PB({tds[ie].F,{tds[ie].S,tds[ib].S}});
                tds[ib].F+=tds[ie].F;
                ie--;
            }
            else {
                cdebts.PB({tds[ie].F,{tds[ie].S,tds[ib].S}});
                ie--;
                ib++;
            }
        }
    }

    printf("%d\n",cdebts.size());
    for (auto c:cdebts){
        printf("%d %d %I64d\n",c.S.F+1,c.S.S+1,c.F);
    }
}