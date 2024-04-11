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
    VPLL a(n);
    REP(i,n){
        DRII(x,y);
        a[i]={x,y};
    }



    int nbp=0;
    int nbi=0;
    while (min(nbp,nbi)==0){
        nbi=0;
        nbp=0;
        for (auto i:a){
            if ((i.F+i.S+10000000)%2) nbi++;
            else nbp++;
        }
        if (min(nbp,nbi)==0){
            bool isimp=(nbp==0);
            VPLL na(n);
            REP(i,n) {
                na[i]={(a[i].F-a[i].S+ (isimp?1:0))/2,(a[i].F+a[i].S+ (isimp?1:0))/2};
            }
            //for (auto i:a){ cout<<i.F<<","<<i.S<<" ";} cout<<endl;
            a=na;
            //for (auto i:na){ cout<<i.F<<","<<i.S<<" ";} cout<<endl;
            //break;
        }
    }
    VI ga(0);
    REP(i,n){
        if ((a[i].F+a[i].S+10000000)%2) ga.PB(i+1);
    }
    
    printf("%d\n",ga.size());
    REP(i,ga.size()){
        printf("%d%c",ga[i],(i==ga.size()-1)?'\n':' ');
    }
}