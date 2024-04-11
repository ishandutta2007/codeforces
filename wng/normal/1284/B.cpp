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
    int nba=0;
    map<int,int> m;
    VI nbmn(1000001,0);
    VI nbmx(1000001,0);
    REP(i,n){
        DRI(l);
        DRI(mx);
        int mn=mx;
        bool hasa=false;
        REP(i,l-1){
            DRI(a);
            mx=max(a,mx);
            if (a>mn) hasa=true;
            mn=min(a,mn);
        }
        if (hasa) nba++;
        else {
            nbmn[mn]++;
            nbmx[mx]++;
        }
        if (mn==mx) m[mn]++;
    }
    VI nbmnb(1000002,0);
    VI nbmxb(1000002,0);
    REPP(i,1,1000002){
        nbmnb[i]=nbmnb[i-1]+nbmn[i-1];
        nbmxb[i]=nbmxb[i-1]+nbmx[i-1];
    }
    LL res= (LL)n*n - (LL)(n-nba)*(n-nba);
    //cout<<nba<<"  "<<res<<endl;
    res<<=1;
    int nbna=n-nba;
    REP(i,1000001){
        res+=(LL)nbmn[i]*(nbna-nbmxb[i+1]); // nb mecs qui marchent after
        res+=(LL)nbmx[i]*(nbmnb[i]); // nb mecs qui marchent before
    //    if (nbmn[i]+nbmx[i]) cout<<i<<" "<<res<<"  "<<nbmn[i]<<" "<<nbmx[i]<<" "<<nbmnb[i]<<" "<<nbmxb[i+1]<<endl;
    }
    res>>=1;
    // J'ai compt 2 fois au lieu d'une les non constant sans ascension 
    // J'ai compt 0 fois au lieu de zro les constants sans ascension
    // Je retire nbna - nb constant
    //res+=(LL)nbna*(nbna-1)/2;
    /*int nbc=0;
    for (auto i:m){
        nbc+=i.S;
//        cout<<i.F<<" "<<i.S;
//       res-=(LL)i.S*(i.S-1)/2;
//        cout<<" "<<res<<endl;
    }*/
    //res-=(nbna-nbc);
    printf("%I64d\n",res);
}