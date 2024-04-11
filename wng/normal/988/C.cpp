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
    int n;
    RI(n);
    map<int,PII> m;
    REP(i,n){
        int ni; 
        RI(ni);
        VI s(ni);
        int sum=0;
        REP(j,ni){
            RI(s[j]);
            sum+=s[j];
        }
        map<int,PII> m2;
        REP(j,ni){
            int r=sum-s[j];
            m2[r]={i+1,j+1};
        }
        for (auto j:m2){
            if (m.count(j.F)){
                printf("YES\n");
                printf("%d %d\n",m[j.F].F,m[j.F].S);
                printf("%d %d\n",j.S.F,j.S.S);
                return 0;
            }
            m[j.F]=j.S;
        }
    }
    printf("NO\n");
    return 0;
}