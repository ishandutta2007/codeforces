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
    DRII(n,k);
    VI t(n);
    REP(i,n) { RI(t[i]);}
    VI c(k);
    REP(i,k) {RI(c[i]);}
    sort(RALL(t));
    vector<VI> tsts(n,VI(0));
    REP(i,n){
        int cj=-1;
        int cnt=SZ(tsts);
        int tt=1<<20;
        while (tt){
            if (cj+tt<n and SZ(tsts[cj+tt])>=c[t[i]-1]){
                cj+=tt;
            }
            tt>>=1;
        }
        //cj est le plus gros qui passe pas.
        cj++;
        //cout<<"for "<<t[i]<<" "<<cj<<endl;
        tsts[cj].PB(t[i]);
        
    }
    int ans=0;
    REP(i,n){
        if (SZ(tsts[i])==0) {ans=i; break;}
        if (i==n-1) ans=n;
    }
    printf("%d\n",ans);
    REP(i,ans){
        printf("%d ",SZ(tsts[i]));
        REP(j,SZ(tsts[i])){
            printf("%d%c",tsts[i][j],(j==SZ(tsts[i])-1)?'\n':' ');
        }
    }
    
}