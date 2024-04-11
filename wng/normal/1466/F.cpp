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

VI ps;

int findp(int i){
    if (ps[i]!=i) {
        ps[i]=findp(ps[i]);
    }
    return ps[i];
}

void merge(int i, int j){
    int ii=findp(i);
    int jj=findp(j);
    ps[jj]=ii;
}

const int mod = 1000000007;

int main(){
    VI res(0);
    DRII(n,m);
    ps=VI(m+1,-1);
    REP(i, m+1) ps[i]=i;
    VL mods(n+1,1);
    REPP(i,1,n+1){
        mods[i]=(mods[i-1]*2)%mod;
    }
    REP(i,n){
        DRI(x);
        if (x==1){
            DRI(y);
            if (findp(y)){
                merge(0,y);
                res.PB(i+1);
            }
        }
        else{
            DRII(y,z);
            int py=findp(y);
            int pz=findp(z);
            if (py!=pz){
                res.PB(i+1);
                if (py<pz){
                    merge(py,pz);
                }
                else{
                    merge(pz,py);
                }
            }
        }
    }
    map<int,int> s;
    REP(i,m+1){
        s[findp(i)]++;
    }
    LL r=1;
    for (auto i:s){
        //cout<<i.F<<"->"<<i.S<<endl;
        r*=mods[i.S-1];
        r%=mod;
    }
    int sr=SZ(res);
    printf("%I64d %d\n", r, sr);
    REP(i,sr){
        printf("%d%c", res[i], (i==sr-1)?'\n':' ');
    }
}