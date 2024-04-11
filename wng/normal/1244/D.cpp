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
    vector<VI> c(3,VI(n));
    REP(i,n){
        RI(c[0][i]);
    }
    REP(i,n){
        RI(c[1][i]);
    }
    REP(i,n){
        RI(c[2][i]);
    }
    VI nbc(n,0);
    VI sc(n,0);
    REP(i,n-1){
        DRII(x,y);
        x--; y--;
        nbc[x]++;
        nbc[y]++;
        sc[x]+=y;
        sc[y]+=x;
    }
    bool isok=true;
    int start=-1;
    LL bestres=(LL)1<<50;
    VI bestcol;

    REP(i,n){
        if (nbc[i]>2) isok=false;
        if (nbc[i]==1) start=i;
    }
    if (isok){
        VPII pos;
        pos.PB({0,1});
        pos.PB({0,2});
        pos.PB({1,2});
        pos.PB({1,0});
        pos.PB({2,0});
        pos.PB({2,1});
        int kk=0;
        for (auto k:pos){
            VI col(n);
            int st=start;
            int nc=sc[st];
            int pc=k.F;
            int cc=k.S;
            LL res=c[pc][st];
            col[st]=pc+1;
            while (true){
                res+=c[cc][nc];
                col[nc]=cc+1;
                if (nbc[nc]==1) break;
                int nnc=sc[nc]-st;
                int newc= 3 - pc - cc;
                st=nc;
                nc=nnc;
                pc=cc;
                cc=newc;
            }
            if (bestres>res){
                bestres=res;
                bestcol=col;
            }
        }
    }
    if (isok){
        printf("%I64d\n",bestres);
        REP(i,n){
            printf("%d%c",bestcol[i],(i==n-1)?'\n':' ');
        }
    }
    else{
        printf("-1\n");
    }
}