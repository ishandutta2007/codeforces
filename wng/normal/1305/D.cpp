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

VI visited;
VI ps;
vector<VI> cs;


int main(){
    DRI(n);
    cs=vector<VI>(n);
    VI nbc(n,0);
    REP(i,n-1){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        cs[y].PB(x);
        nbc[x]++;
        nbc[y]++;
    }
    VI fs(0);
    REP(i,n) {if (nbc[i]==1) fs.PB(i);}
    int nbl=n;
    int r;
    while (nbl>1){
        int a=fs[0];
        int b=fs[1];
        printf("? %d %d\n",a+1,b+1);
        fflush(stdout);
        RI(r);
        r--;
        if (r==a or r==b) {break;}
        nbl-=2;
        fs.erase(fs.begin(),fs.begin()+2);
        for (auto c:cs[a]) {nbc[c]--; if (nbc[c]==1) fs.PB(c);}
        for (auto c:cs[b]) {nbc[c]--; if (nbc[c]==1) fs.PB(c);}
    }
    if (nbl==1) {r=fs[0];}
    printf("! %d\n",r+1);
    fflush(stdout);

}