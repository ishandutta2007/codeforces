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
    int lim=10000000;
    DRII(n,m);
    vector<VI> cs(n);
    vector<pair<int,PII>> rtt(n,{lim,{-1,-1}});
    REP(i,m){
        DRII(x,y);
        x--; y--;
        cs[y].PB(x);
    }
    DRI(k);
    VI b(k);
    REP(i,k) {
        RI(b[i]); 
        b[i]--;
    }
    int t=b[k-1];
    rtt[t]={0,{-1,-1}};
    vector<VI> bd(n);
    bd[0].PB(t);
    REP(i,n){
        if (!SZ(bd[i])) break;
        for (auto j:bd[i]){
            for (auto c: cs[j]){
                if (rtt[c].F==i+1 and rtt[c].S.S<0){
                    rtt[c].S.S=c;
                }
                if (rtt[c].F>i+1){
                    rtt[c]={i+1,{c,-1}};
                    bd[i+1].PB(c);
                }
            }
        }
    }
    int nbmin=0;
    int nbmax=0;
    REP(i,k-1){

        if (rtt[b[i]].F!=rtt[b[i+1]].F+1) {nbmin++; nbmax++;}
        else{
            if (rtt[b[i]].S.S>=0) nbmax++;
        }
    }
    printf("%d %d\n",nbmin,nbmax);
}