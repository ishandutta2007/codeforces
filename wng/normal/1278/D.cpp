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


VI ps;

int findp(int i){
    if (ps[i]!=i) ps[i]=findp(ps[i]);
    return ps[i];
}

void merge (int i, int j){
    ps[findp(i)]=ps[findp(j)];
}

int n,n2;

int main(){
    RI(n);
    VPII a(n);
    n2=2*n;
    map<int,int> closedate;
    REP(i,n){
        DRII(x,y);
        a[i]={x,y};
    }
    sort(ALL(a));
    LL res=0;

    int nbv=0;
    VPII vs;

    int ii=0;
    for (auto i:a){
        auto it=closedate.lower_bound(i.F);
        while (it!=closedate.end() and it->F<i.S) {nbv++; vs.PB({it->S,ii}); it++;}
        closedate[i.S]=ii;
        ii++;
        if (nbv>n-1) {break;}
    }

    int nbp=0;
    if (nbv==n-1){
        ps=VI(n);
        REP(i,n) {ps[i]=i;}
        for (auto i:vs){
            merge(i.F,i.S);
        }
        REP(i,n) {if (findp(i)==i) nbp++;}
    }

    if (nbp==1){
        printf("YES\n");
    }
    else {printf("NO\n");}

}