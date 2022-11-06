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
    set<int> op;
    set<int> forb;
    VI split;
    bool isok=true;
    REP(i,n){
        RI(a[i]);
        if (a[i]>0){
            if (forb.find(a[i])!=forb.end()){
                isok=false;
            }
            else{
                op.insert(a[i]);
                forb.insert(a[i]);
            }
        }
        else{
            if (op.find(-a[i])==op.end()){
                isok=false;
            }
            else{
                op.erase(-a[i]);
                if (op.size()==0) {
                    forb.clear();
                    split.PB(i+1);
                }
            }
        }
    }
    if (!isok or op.size()!=0) {printf("-1\n"); return 0;}
    int ss=split.size();
    printf("%d\n",ss);
    REP(i,ss){
        printf("%d%c",i?split[i]-split[i-1]:split[i],(i==ss-1)?'\n':' ');
    }
}