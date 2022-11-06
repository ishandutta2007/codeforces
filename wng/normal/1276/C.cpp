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
    DRI(n);
    VI a(n);
    map<int,int> nb;
    REP(i,n){
        RI(a[i]);
        nb[a[i]]++;
    }
    VI nbs(n+1,0);
    int nbnb=nb.size();
    for (auto m:nb){
        nbs[m.S]++;
    }
    int nbtot=0;
    int curs=0;
    PII maxp;
    int maxsize=0;
    REPP(i,1,n+1){
       // cout<<i<<" "<<nbtot<<" "<<curs<<endl;
        nbtot+=nbnb-curs;
       // cout<<i<<" "<<nbtot<<" "<<curs<<endl;
        curs+=nbs[i];
        int j=nbtot/i;
        if (j>=i and i*j>maxsize){
            maxsize=i*j;
            maxp={i,j};
        }
    }
    //generate it
    if (!maxsize) {printf("ERROR"); return 0;}
    vector<VI> bestres(maxp.F,VI(maxp.S));
    int nbl=maxsize;
    int filled=0;
    for (auto m:nb){
        if (m.S>=maxp.F){
            REP(i,maxp.F){
                bestres[i][(i+(filled/maxp.F))%maxp.S]=m.F;
            }
            filled+=maxp.F;
            nbl-=maxp.F;
            if (!nbl) {break;}
        }
    }
    VI nxt(nbl);
    int ii=0;
    if (nbl){
        for (auto m:nb){
            if (m.S<maxp.F){
                REP(i,m.S){
                    nxt[ii++]=m.F;
                    if (ii>=nbl) {break;}
                }
                if (ii>=nbl) {break;}
            }
        }
        if (ii<nbl) {printf("ERROR2"); return 0;}
        int st=filled/maxp.F;
        REPP(j,st,maxp.S){
            REP(i,maxp.F){
                bestres[i][(i+j)%maxp.S]=nxt[(j-st)*maxp.F+i];
            }
        }
    }
    printf("%d\n",maxsize);
    printf("%d %d\n",maxp.F,maxp.S);
    REP(i,maxp.F){
        REP(j,maxp.S){
            printf("%d%c",bestres[i][j],(j==(maxp.S-1) ? '\n':' '));
        }
    }


}