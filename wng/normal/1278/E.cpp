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

int n;
VI visited;

VI res;
vector<VI> cs;

void visit(int x){
    visited[x]=1;
    VI tc(0);
    for (auto c:cs[x]) if (!visited[c]) {visit(c); tc.PB(c);}
    res.PB(x);
    for (auto it=tc.rbegin();it!=tc.rend(); it++) res.PB(*it);
}

int main(){
    DRI(n);
    visited=VI(n);
    cs=vector<VI> (n);
    REP(i,n-1){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        cs[y].PB(x);
    }
    visit(0);
    res.PB(0);
    VPII rr(n,{0,0});
    int kk=0;
    for (auto c:res){
        kk++;
        if (rr[c].F==0) rr[c].F=kk;
        else rr[c].S=kk; 
    }
    for (auto i:rr){
        printf("%d %d\n",i.F,i.S);
    }
}