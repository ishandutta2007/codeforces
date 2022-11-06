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

VI ps;

VI mns,mxs;

int findp(int i){
    if (ps[i]!=i){
        ps[i]=findp(ps[i]);
    }
    return ps[i];
}

void merge(int i,int j){
    int ii=findp(i);
    int jj=findp(j);
    if (ii!=jj){
        ps[jj]=ii;
        mns[ii]=min(mns[ii],mns[jj]);
        mxs[ii]=max(mxs[ii],mxs[jj]);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DRII(n,m);
    ps = VI(n);
    mns=VI(n);
    mxs=VI(n);
    REP(i,n) {ps[i]=i; mns[i]=i; mxs[i]=i;}
    REP(i,m){
        DRII(x,y);
        x--; y--;
        merge(x,y);
    }
    VPII fams;
    REP(i,n){
        if (ps[i]==i){
            fams.PB({mns[i],mxs[i]});
        }
    }
    sort(ALL(fams));
    int cmax=-1;
    int res=0;
    for (auto f:fams){
        if (cmax<f.F){ 
            cmax=f.S;
        }
        else{
            res++;
            cmax=max(cmax,f.S);
        }
    }
    printf("%d\n",res);
}