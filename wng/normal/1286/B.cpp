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

int n;
VI ps,c;
vector<VI> cs;
bool isok=true;

VI solve(int root){
    VI classbelow(0);
    for (auto c:cs[root]){
        VI s=solve(c);
        classbelow.insert(classbelow.end(),s.begin(),s.end()); 
    }
    if (classbelow.size()<c[root]) {isok=false; return VI(0);}
    else {
        classbelow.insert(classbelow.begin()+c[root],root);
    }
    return classbelow;
}

int main(){
    RI(n);
    ps=VI(n);
    c=VI(n);
    cs=vector<VI>(n);
    int root=-1;
    REP(i,n){
        DRII(x,y);
        if (x==0) {ps[i]=i; root=i;}
        else {ps[i]=x-1; cs[x-1].PB(i);} 
        c[i]=y;
    }
    VI res=solve(root);
    if (!isok) {printf("NO\n"); return 0;}
    VI rr(n);
    REP(i,n) {rr[res[i]]=i+1;}
    printf("YES\n");
    REP(i,n){
        printf("%d%c",rr[i],i==n-1?'\n':' ');
    }
}