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
    DRII(n,k);
    VI a(n);
    VI divs;
    int d=2;
    int kk=k;
    map<int,int> kd;
    while (kk>=d){
        while (not (kk%d)) {kd[d]++; kk/=d; }
        d++;
       // cout<<kk<<" "<<d<<endl;
    }
    for (auto d:kd){
        int p=d.F;
        int pp=d.S;
        divs.PB(pp);
      //  cout<<p<<" "<<pp<<endl;
    }
    map<VPII,int> nbc;
    REP(i,n){
        RI(a[i]);
        VPII ma;
        int aa=a[i];
        int d=2;
         while (d*d<=aa){
            int nbd=0;
            while (not (aa%d)) {aa/=d; nbd++;}
            if (nbd%k) {ma.PB({d,nbd%k});}
            d+= (d>2)?2:1;
        }
        if (aa>1) { ma.PB({aa,1});}
        nbc[ma]++;
    }
    LL res=0;
    for (auto m:nbc){
        VPII vc=m.F;
        LL nb=m.S;
        //for (auto i:vc) {cout<<i.F<<","<<i.S<<" ";}
        //cout<<","<<nb<<endl;
        VPII match;
        REP(i,vc.size()){
            match.PB({vc[i].F,k-vc[i].S});
        }
        if (match==vc){ res+= nb*(nb-1);}
        else {
            if (nbc.find(match)!=nbc.end()){
                LL nb2 = nbc[match];
                res+=nb*nb2;
            }
        }
    }
    res>>=1;
    printf("%I64d\n",res);

}