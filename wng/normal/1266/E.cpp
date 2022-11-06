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
    VI a(n);
    VI b(n,0);
    LL res=0;
    REP(i,n) {RI(a[i]);
        res+=a[i];
    }
    map<PII,int> bon;
    DRI(q);
    REP(i,q){
        DRIII(s,t,u);
        if (bon.find({s,t})==bon.end()){
            if (u){
                bon[{s,t}]=u;
                b[u-1]++;
                if (b[u-1]<=a[u-1]) res--;
            }
        }
        else{
            int prev=bon[{s,t}];
            b[prev-1]--;
            if (b[prev-1]<a[prev-1]) res++;
            if (u){
                bon[{s,t}]=u;
                b[u-1]++;
                if (b[u-1]<=a[u-1]) res--;
            }
            else{
                bon.erase({s,t});
            }
        }
        printf("%I64d\n",res);
    }



}