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
    VI xor1(n);
    map<int,int> m;
    PII db={-1,-1};
    PII mindiff={2,-1};
    REPP(i,1,n){
        printf("XOR 1 %d\n", i+1);
        fflush(stdout);
        RI(xor1[i]);
        if (xor1[i]<mindiff.F) {mindiff= {xor1[i],i};}
        if (m.find(xor1[i])!=m.end()){
            db={m[xor1[i]],i};
        }
        m[xor1[i]]=i;
    }
    VI res(n);
    if (db.F!=-1 or mindiff.F==0){
        PII both = (db.F==-1)?MP(0,mindiff.S):db;
        printf("AND %d %d\n", both.F+1, both.S+1);
        fflush(stdout);
        DRI(aeb);
        res[both.F]=aeb;
        res[0]=aeb^xor1[both.F];
        REPP(i,1,n) res[i]=res[0]^xor1[i];
    }
    else{
        assert(mindiff.F==1);
        PII both = {0,mindiff.S};
        printf("AND %d %d\n", both.F+1, both.S+1);
        fflush(stdout);
        DRI(aeb);
        res[both.F]=aeb;
        REPP(i,1,n){
            if (i!=both.S and (xor1[i]&1)==0){
                printf("AND %d %d\n", both.F+1, i+1);
                fflush(stdout);
                DRI(aeo);
                if (aeo&1){
                    aeb++;
                }
                break;
            }
        }
        res[0]=aeb;
        REPP(i,1,n) res[i]=res[0]^xor1[i];
        
    }
    printf("!");
    REP(i,n){
        printf(" %d", res[i]);
    }
    printf("\n");
    fflush(stdout);
}