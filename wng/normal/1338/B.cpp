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

vector<VI> cs;
VI vised;
VI rankpar;
int nbleaves=0;

void dfs(int i,int rp){
    vised[i]=1;
    rankpar[i]=rp;
    int nbv=0;
    for (auto c:cs[i]){
        if (!vised[c]) {dfs(c,rp^1); nbv++;}
    }
    if (!nbv) nbleaves++; 
    if (nbv==1 and i==0){
        nbleaves++;
    }
}

int main(){
    DRI(n);
    vised=VI(n,0);
    rankpar=VI(n,0);
    cs=vector<VI>(n);
    set<int> ptouching;
    REP(i,n-1){
        DRII(x,y);
        x--;y--;
        cs[x].PB(y);
        cs[y].PB(x);
    }
    dfs(0,0);
    VI pars(2,0);
    REP(i,n){
        if (SZ(cs[i])==1){
            pars[rankpar[i]]++;
            ptouching.insert(cs[i][0]);
        }
    }
    int minimize=(pars[0] and pars[1])?3:1;
    int maximize=n-1-nbleaves+SZ(ptouching);
    printf("%d %d\n",minimize,maximize);

}