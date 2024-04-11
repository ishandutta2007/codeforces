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


    VI listmods;
    listmods.PB(1000000007);
    listmods.PB(999979699);
    listmods.PB(999982561);
    listmods.PB(999981523);
    listmods.PB(999981713);
    listmods.PB(999981547);
    int ms=SZ(listmods);
    int lim=500000;
    vector<VI> mods2p(ms,VI(500000+1,1));
    REP(i,ms){
        REP(j,lim){
            mods2p[i][j+1]=(2*mods2p[i][j])%listmods[i];
        }
    }

    CASET{
        DRII(n,m);
        VL c(n);
        vector<VL> rm(n,VL(ms,0));
        REP(i,n) {scanf("%I64d",&(c[i]));}
        REP(i,m){
            DRII(x,y);
            x--; y--;
            REP(i,ms){
                rm[y][i]+=mods2p[i][x];
            }
        }
        map<VL,LL> res;
        REP(i,n){
            bool isok=false;
            for (auto j:rm[i]) if (j) isok=true;
            if (isok) res[rm[i]]+=c[i];
        }
        LL g=res.begin()->S;
        for (auto i: res){
            g=__gcd(g,i.S);
        }
        printf("%I64d\n",g);
    }

}