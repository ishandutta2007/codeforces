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
    int n;
    RI(n);
    VI a(2*n);
    REP(i,2*n) {RI(a[i]);}
    LL res1=0;
    VI a1(2*n);
    REP(i,n) {a1[i]=a[i];}
    REPP(i,n,2*n) {a1[i]=a[3*n-1-i];}
    REP(i,2*n){
        res1+=(LL)i*a1[i];
        }
    
    
    LL res2=0;
    VI a2(2*n);
    REP(i,n) { if (i%2) {a2[2*i]=a[n+i]; a2[2*i+1]=a[i];} else {a2[2*i]=a[i]; a2[2*i+1]=a[n+i];}}
    REP(i,2*n){
        res2+=(LL)i*a2[i];
        }
    
   // printf("%I64d\n",max(res1,res2));
    
    //Bon en fait, on commence par du serpent puis on finit par du   aller retour droit.
    
    //J'ai besoin de cout de serpent jusqu'a n-1,   de cout de aller retour from n  (attention, ca depend de la parite)
  
    vector<LL> car(n+1);
    vector<LL> carr(n+1);
    vector<LL> sp(n+1);
    LL sommepart=0;
    LL basesum=0;
    LL basesumr=0;
    for (int i=n-1;i>=0;i--) {
            basesum+=(LL)sommepart + (LL)(2*(n-1-i)+1)*a[n+i];
            basesumr+=(LL)sommepart + (LL)(2*(n-1-i)+1)*a[i];
            car[i]=basesum;
            carr[i]=basesumr;
            sommepart+=(a[i]+a[n+i]);
            sp[i]=sommepart;
        }
    
        
    vector<LL> cs(n+1);
    REP(i,n) { if (i%2) {a2[2*i]=a[n+i]; a2[2*i+1]=a[i];} else {a2[2*i]=a[i]; a2[2*i+1]=a[n+i];}}
   
    LL res3=0;
    REP(i,2*n){
        res3+=(LL)i*a2[i];
        if ((i%2)) {cs[i/2+1]=res3;}
        }
  /* for (auto i:car) {cout<<i<<" ";} cout<<endl;
    for (auto i:carr) {cout<<i<<" ";} cout<<endl;
    for (auto i:cs) {cout<<i<<" ";} cout<<endl;
    for (auto i:sp) {cout<<i<<" ";} cout<<endl;
    cout<<res1<<" "<<res2<<endl; /**/
    
    LL rr=0;
    REP(i,n+1){
        rr=max(rr,cs[i]+(LL)2*i*sp[i]+((i%2)?carr[i]:car[i]));
    }
    printf("%I64d\n",rr);
    
}