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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<n; ___I++) scanf("%d", &(X[___I]))  
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

int n,k;
VI a;


bool canI(LL p){
    // can I build a sequence with (k-k//2) any  and  k//2  lower
    int goal1=0;
    int goal2=0;
    for (auto c: a){
        if (goal1%2==0) goal1++;
        else {if (c<=p) goal1++;}
        if (goal2%2) goal2++;
        else {if (c<=p) goal2++;}
        
    }
    return max(goal1,goal2)>=k;
}

int main(){
    RII(n,k);
    a = VI(n);
    REP(i,n) RI(a[i]);
    LL res=0;
    LL tt=1<<30;
    while (tt){
        LL att=res+tt;
        if (!canI(att)) res+=tt;
        tt>>=1;
    }
    res+=1;
    printf("%lld\n",res);
}