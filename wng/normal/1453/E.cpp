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

vector<VI> cs;

VI ps;
VI mv;

void dfs(int i, int myk){
    int nbc=SZ(cs[i]) - (i?1:0);
    if (nbc) {
        int minmv=10000;
        int maxmv=0;
        for (auto c:cs[i]){
            if (ps[c]==-1){
                ps[c]=i;
                dfs(c, myk);
                minmv=min(minmv, mv[c]);
                maxmv=max(maxmv, mv[c]);
            }
        }
        if (minmv<=1) {mv[i]=0;}
        else mv[i]=maxmv-1;
    }
    else{
        mv[i]=myk;
    }
}

int main(){
    CASET{
        DRI(n);
        cs= vector<VI>(n,VI(0));
        REP(i,n-1){
            DRII(x,y);
            x--; y--;
            cs[x].PB(y);
            cs[y].PB(x);
        }
        int tt=1;
        while ((tt<<1)<n-1) tt<<=1;
        int cr=0;
        while (tt){
            if (tt+cr<n-1){
                ps=VI(n,-1);
                mv=VI(n,0);
                ps[0]=0;
                dfs(0, tt+cr);
                int nb1=0;
                bool isok=true;
                for (auto c:cs[0]){
                    if (mv[c]==1) nb1++;
                    if (mv[c]<1) isok=false;
                }
                
                //cout<<cr+tt<<"  ";
                //for (auto i: mv) {cout<<i<<" ";} cout<<endl;
                if (!isok or nb1>1){
                    cr+=tt;
                }
            }
            tt>>=1;
        }
        printf("%d\n", cr+1);
    }
}