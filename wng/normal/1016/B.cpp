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
    int n,m,q;
    RIII(n,m,q);
    
    char s[1000];
    char t[1000];
    RS(s);
    RS(t);
    
    VI a(m);
    VI starts(n+1);
    VI ends(n+1);
    int totocc=0;
    //REP(i,m){assert(t[i]=='a');}
    //REP(i,n){if (s[i]!='a') {cout<<s[i]<<" "<<(int)s[i]<<" "<<i; return 0;}}
    REP(i,n){
        for(int j=m-1;j>=0;j--){
            if (s[i]==t[j]){
                a[j]=j?a[j-1]:1;
            }
            else {a[j]=0;}
        }
        ends[i+1]= ends[i]+(a[m-1]?1:0);
        if (i-m+2>0){ starts[i-m+2]=starts[i-m+1]+(a[m-1]?1:0);}
        totocc+=(a[m-1]?1:0);
    }
    REPP(i,1,n+1){
        starts[i]=max(starts[i],starts[i-1]);
    }
   /* for (auto i:starts) {cout<<i<<" ";} cout<<endl;
    for (auto i:ends) {cout<<i<<" ";} cout<<endl;*/
    REP(i,q){
        int l,r;
        RII(l,r);
        printf("%d\n",max(0,ends[r]-starts[l-1]));
    }
    
}