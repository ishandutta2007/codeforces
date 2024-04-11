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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n;
    cin>>n;
    VL fs(0);
    LL ns=n;
    LL pd=1;
    while (!(n%2)) {pd<<=1; n>>=1;}
    if (pd>1) {fs.PB(pd);}
    for (LL i=3; i*i<=n;i+=2){
        pd=1;
        while (!(n%i)) {pd*=i; n/=i;}
        if (pd>1) {fs.PB(pd);}
    }
    if (n>1) {fs.PB(n);}
    //cout<<ra<<" "<<rb<<endl;
    //for (auto i:fs) {cout<<i<<" ";} cout<<endl;
    LL minres=ns;
    LL ra(1),rb(ns);

    REP(i,1<<SZ(fs)){
        LL a(1),b(1);
        LL t=1;
        REP(k,SZ(fs)){
            if (i&t) a*=fs[k];
            else b*=fs[k];
            t<<=1;
        }
        //cout<<i<<" "<<a<<" "<<b<<endl;
        if (max(a,b)<minres){
            minres=max(a,b);
            ra=a;
            rb=b;
        }
    }
    cout<<ra<<" "<<rb<<"\n";
}