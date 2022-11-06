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
    DRI(n);
    char s[210];
    RS(s);
    VI a(n);
    VI b(n);
    bool isok=true;
    VI res(0);
    REP(i,n){
        if (s[i]=='W') a[i]=1;
        if (i and a[i]^a[i-1]^b[i-1]^b[i]) {
            if (i==n-1) {isok=false; break;}
            res.PB(i+1);
            b[i]^=1;
            b[i+1]^=1;
        }
    }
    if (isok){
        printf("%d\n",res.size());
        REP(i,res.size()){
            printf("%d%c",res[i],(i==res.size()-1)?'\n':' ');
        }
    }
    else{
        if (n%2){
            REP(i,n/2){
                res.PB(2*i+1);
            }
            printf("%d\n",res.size());
            REP(i,res.size()){
                printf("%d%c",res[i],(i==res.size()-1)?'\n':' ');
            }
        }
        else printf("-1\n");
    }

}