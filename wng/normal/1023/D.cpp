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
    DRII(n,q);
    VI a(n);
    int maxa=0;
    int nb0=0;
    REP(i,n) {RI(a[i]); maxa=max(maxa,a[i]); if (!a[i]) nb0=i+1;}
    if (!maxa) {
        printf("YES\n"); 
        REP(i,n) {printf("%d%c",q,i==n-1?'\n':' ');} 
            return 0;}
    if (maxa>q) {printf("NO\n"); return 0;}
    if (maxa<q and nb0==0) {printf("NO\n"); return 0;}
    if (maxa<q and nb0) {a[nb0-1]=q;}
    
    REPP(i,1,n) {if ((!a[i]) and a[i-1]) a[i]=a[i-1];}
    for (int i=n-2;i>=0;i--) {if ((!a[i]) and a[i+1]) a[i]=a[i+1];}
    
    VI fa(q+1);
    VI la(q+1);
    
    
    REP(i,n){
        if (!fa[a[i]]) fa[a[i]]=i+1;
        la[a[i]]=i+1;
        }
    VI tc(n+1);
    VI to(n+1);
    REPP(i,1,q+1){
        if (la[i]) tc[la[i]-1]=i;
        if (fa[i]) to[fa[i]-1]=i;
    }
        
    set<int> opens;
    REP(i,n){
        if (to[i]) {opens.insert(-to[i]);
        }
        if (*(opens.begin())!=-a[i]) {printf("NO\n"); return 0;};
        if (tc[i]) {opens.erase(-tc[i]);}
    }
    printf("YES\n"); 
    REP(i,n) {printf("%d%c",a[i],i==n-1?'\n':' ');} 
    return 0;
}