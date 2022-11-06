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
    int n,t;
    RII(n,t);
    VPII v;
    VI a(n);
    VI ti(n);
    LL tt=0;
    LL res=0;
    double soinfinal=0.0;
    REP(i,n) { RI(a[i]);}
    REP(i,n) { RI(ti[i]);ti[i]-=t;}
    REP(i,n) {v.PB({ti[i],a[i]}); tt+=(LL)a[i]*ti[i]; res+=a[i];}
    sort(v.begin(),v.end());
    //for (auto i:v) {cout<<i.F<<" "<<i.S<<endl;}
    if (tt>=0) {
        int it=n-1;
        while (tt>0 and it>=0 and v[it].F>0){
            LL tr= (LL)v[it].F*v[it].S;
            if (tr>tt) {
                soinfinal=v[it].S*(float)tt/tr;
                tt=0;
            }
            else {tt-=tr;res-=v[it].S;}
            it-=1;
        }
    }
    else{
        int it=0;
        while (tt<0 and it<n and v[it].F<0){
            LL tr= (LL)v[it].F*v[it].S;
            if (tr<tt) {
                soinfinal=v[it].S*(float)tt/tr;
                tt=0;
            }
            else {tt-=tr; res-=v[it].S;}
            it++;
        }
    }
    if (tt==0) {printf("%.8f\n",res-soinfinal);}
    else {printf("0\n");}
    
    }