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


vector<pair<PII,int>> trps(0);

int n,m,t,k;

int mintimepourpiegedsdekagi(int agi){
    int maxreached=0;
    int extrawork=0;
    auto it=trps.begin();
    while (it!=trps.end()){
        if (it->S <= agi) {it++; continue;}
        int start=(it->F).F;
        int maxtoreach=(it->F).S;
        it++;
        while ( it!=trps.end() and (it->F).F <= maxtoreach){
            if (it->S <= agi) {it++; continue;}
            maxtoreach=max(maxtoreach,(it->F).S);
            it++;
        }
        extrawork+=(maxtoreach-start+1)*2;
    }
    //cout<<agi<<" "<<extrawork <<"+"<<n+1<<endl;
    return extrawork + n+1;
}

int main(){
    RII(m,n);
    RII(k,t);
    VI a(m);
    VI ta(200000+1,0); //nb soldiers <= k agilite
    REP(i,m){
        RI(a[i]);
        ta[a[i]]++;
    }
    REPP(i,1,ta.size()){
        ta[i]+=ta[i-1];
    }
    REP(i,k){
        DRIII(l,r,d);
        trps.PB({{l,r},d});
    }
    sort(ALL(trps));
    int tt=1;
    while (tt<<1 <= 200000) tt<<=1;
    int res=0;
    while (tt) {
        if (res+tt<=200000 and mintimepourpiegedsdekagi(tt+res)>t) res+=tt;
        tt>>=1;
    }
    res++;
    printf("%d\n",m-ta[res-1]);
}