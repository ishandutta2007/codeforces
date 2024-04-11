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
#define DRVL(N, X) VL X(N); for (int ___I=0; ___I<N; ___I++) scanf("%I64d", &(X[___I]))  
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
    DRVL(n,a);
    DRVL(m,b);
    if (n==1){
        REP(i,m){
            LL g=0;
            LL gg=__gcd(g, a[0]+b[i]);
            printf("%I64d%c", gg, (i==m-1)?'\n':' ');
        }
        return 0;
    }
    sort(ALL(a));
    LL g= a[1]-a[0];
    REPP(i,2,n){
        g=__gcd(g, a[i]-a[0]);
    }

    REP(i,m){
        LL gg=__gcd(g, a[0]+b[i]);
        printf("%I64d%c", gg, (i==m-1)?'\n':' ');
    }
}