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
    DRIII(n,p,k);
    VI a(n);
    REP(i,n){RI(a[i]);}
    vector<VI> s(n,VI(p));
    vector<pair<int,VI>> b(n);
    REP(i,n){
        VI ss(p);
        REP(j,p) RI(ss[j]);
        b[i]={a[i],ss};
    }
    sort(b.rbegin(),b.rend());
    vector<VI> oi(p+1,VI(0));
    REP(i,1<<p){
        int ii=i;
        int r=0;
        while (ii) {if (ii%2) r++; ii/=2;}
        oi[r].PB(i);
    }
    LL inf=-1000000010;
    inf*=n;
    VL res(1<<p,inf);
    res[0]=0;
    REP(i,n){
        for (int j=p; j>=0; j--){
            for (auto m: oi[j]){
              //  cout<<"cing "<<m;
                res[m]=max(res[m],res[m]+((i-j<k)?b[i].F:0));
                int t=1;
                int kk=0;
                while (t<=m){
                    if (t&m) {
                        res[m]=max(res[m],res[t^m]+b[i].S[kk]);
                    }
                    t<<=1;
                    kk++;
                }
                //cout<<" "<<res[m]<<endl;
            }
        }
//        for (auto kk: res) {cout<<kk<<" ";} cout<<endl;
    }
    printf("%I64d\n", res[(1<<p)-1]);
}