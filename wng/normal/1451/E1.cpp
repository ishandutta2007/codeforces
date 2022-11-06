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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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
    printf("XOR 1 2\n");
    fflush(stdout);
    DRI(axb);
    printf("XOR 2 3\n");
    fflush(stdout);
    DRI(bxc);
    int axc=axb^bxc;
    printf("OR 1 2\n");
    fflush(stdout);
    DRI(aob);
    int aeb=aob-axb;
    int apb=axb+(aeb<<1);
    printf("OR 1 3\n");
    fflush(stdout);
    DRI(aoc);
    int aec=aoc-axc;
    int apc=axc+(aec<<1);
    printf("OR 2 3\n");
    fflush(stdout);
    DRI(boc);
    int bec=boc-bxc;
    int bpc=bxc+(bec<<1);
    VI res(n);
    res[0]=(apb+apc -bpc)/2;
    res[1]=apb-res[0];
    res[2]=apc-res[0];
    REPP(i,3,n){
        printf("XOR %d %d\n", i, i+1);
    fflush(stdout);
        DRI(y);
        res[i]=res[i-1]^y;
    }
    printf("!");
    REP(i,n){
        printf(" %d", res[i]);
    }
    printf("\n");
    fflush(stdout);
}