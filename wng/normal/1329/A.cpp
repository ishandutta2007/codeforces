#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<n; ___I++) scanf("%d", &(X[___I]))  
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
    int nbc=0;
    VI l(m);
    VL r(m+1,0);
    bool isok=true;
    REP(i,m){
        RI(l[i]);
        r[i+1]=l[i]+r[i];
    }
    if (r[m]<n) isok=false;
    LL left=(r[m]-n);
    LL totalr=0;
    REPP(i,1,m){
        int tr=min(left,r[i]-r[i-1]-totalr-1);
       // cout<<i<<"   "<<tr<<" "<<r[i]<<" "<<r[i-1]<<endl;
        totalr+=tr;
        left-=tr;
        r[i]-=totalr;
        if (r[i]+l[i]>n) isok=false;
    }
    if (isok) {
        REP(i,m){printf("%I64d%c",r[i]+1,(i==m-1)?'\n':' ');}
    }
    else{
        printf("-1\n");
    }

}