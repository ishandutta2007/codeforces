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
    DRI(q);
    REP(nt,q){
        DRI(n);
        VI p(n);
        REP(i,n) {RI(p[i]); p[i]/=100;}
        DRII(x,a);
        DRII(y,b);
        if (y>x){
            swap(a,b);
            swap(x,y);
        }
        LL k;
        scanf("%I64d",&k);
        //maximum m that gives less than k
        int mc=0;
        int tt=1;
        while (tt<n) tt<<=1;
        sort(p.rbegin(),p.rend());
        while (tt){
            int tatt= mc+tt;
            LL lcm = (LL)a*b/__gcd((LL)a,(LL)b);
            if (tatt<=n){
                int nbt= tatt/lcm;
                int nbx= tatt/a-nbt;
                int nby = tatt/b-nbt;
                LL res=0;
                REPP(i,0,nbt){
                    res+=(LL)p[i]*(x+y);
                } 
                REPP(i,nbt,nbt+nbx){
                    res+=(LL)p[i]*(x);
                } 
                REPP(i,nbt+nbx,nbt+nbx+nby){
                    res+=(LL)p[i]*(y);
                }
                assert (min(nbt,min(nbx,nby))>=0);
                assert (nbt+nbx+nby<=n);
                //cout<<tatt<<nbt<<" "<<nbx<<" "<<nby<<" "<<res<<" "<<k<<endl;
                if (res<k) mc=tatt;
            }
            tt>>=1;
        }
       //cout<<"result : ";
        if (mc<n) {printf("%d\n",mc+1);}
        else {printf("-1\n");}
    }
}