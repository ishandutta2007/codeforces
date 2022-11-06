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
    DRI(t);
    while (t--){
        DRI(n);
        map<int,int> nbp;
        REP(i,n){
            DRI(x);
            nbp[x]++;
        }
        int nbn=0;
        bool stillnull=true;
        int maxnull=-1;
        for (auto i: nbp){
            nbn+=i.S;
            if ((n-nbn)<=n/2) {stillnull=false;
            maxnull=i.F;
            break;}
        }
        int nbg=-1;
        int nbs=0;
        int nbb=0;
        for (auto it=nbp.rbegin();it!=nbp.rend();it++){
            if (it->F==maxnull){ break;}
            if (nbg==-1) nbg=it->S;
            else{
                if (nbs<=nbg) {nbs+=it->S;}
                else nbb+=it->S;
            }
        }
        if (nbg!=-1 and nbs>nbg and nbb>nbg){
            printf("%d %d %d\n",nbg,nbs,nbb);
        }
        else{
            printf("%d %d %d\n",0,0,0);
        }
    }

}