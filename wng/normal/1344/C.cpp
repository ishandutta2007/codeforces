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

VI ved, ving;
VI vedc, vedp;
vector<VI> cs;
vector<VI> ps;

bool dfs(int i){ //returns false if cycle
    ving[i]=1;
    bool res=true;
    for (auto c:cs[i]){
        if (ving[c]) return false;
        if (!ved[c]){
            res&=dfs(c);
        }
    }
    ved[i]=1;
    ving[i]=0;
    return res;
}

void dfsc(int i){ //returns false if cycle
    vedc[i]=1;
    for (auto c:cs[i]){
        if (!vedc[c]){
            dfsc(c);
        }
    }
    vedc[i]=1;
}

void dfsp(int i){ //returns false if cycle
    vedp[i]=1;
    for (auto c:ps[i]){
        if (!vedp[c]){
            dfsp(c);
        }
    }
}


int main(){
    DRII(n,m);
    cs=vector<VI>(n,VI(0));
    ps=vector<VI>(n,VI(0));
    ved=VI(n,0);
    ving=VI(n,0);
    REP(i,m){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        ps[y].PB(x);
    }
    bool isok=true;
    REP(i,n){
        if (!ved[i]) {
            isok&=dfs(i);
        }
    }
    if (!isok) {printf("-1\n"); return 0;}
    
    //no cycle
    vedc=VI(n,0);
    vedp=VI(n,0);
    int score=0;
    vector<char> res(n);
    REP(i,n){
        if (!vedc[i] and !vedp[i]) {
            score+=1;
            res[i]='A';
        }
        else res[i]='E';
        if (!vedc[i]) dfsc(i);
        if (!vedp[i]) dfsp(i);
    }
    printf("%d\n",score);
    REP(i,n) {printf("%c",res[i]);}
    printf("\n");
}