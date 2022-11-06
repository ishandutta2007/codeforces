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
    CASET{
        DRI(n);
        DRVI(n,a);
        VI sqs(999);
        REP(i,999){sqs[i]=(i+2)*(i+2);}
        map<int,int> zero;
        map<int,int> un;
        REP(i,n){
            zero[a[i]]++;
            for (auto sq:sqs){
                while (a[i]%sq==0){
                    a[i]/=sq;
                }
            }
            un[a[i]]++;
        }
        int r0=0;
        for (auto i: zero){
            r0=max(r0, i.S);
        }
        int r1=0;
        map<int,int> deux;
        for (auto i: un){
            r1=max(r1, i.S);
            if (i.S%2){
                deux[i.F]+=i.S;
            }
            else{
                deux[1]+=i.S;
            }
        }
        int r2=0;
        for (auto i: deux){
            r2=max(r2, i.S);
        }
        DRI(q);
        REP(i,q){
            LL p;
            scanf("%I64d", &p);
            if (p==0){
                printf("%d\n", r1);
            }
            else{
                printf("%d\n", r2);
            }
        }
    }
}