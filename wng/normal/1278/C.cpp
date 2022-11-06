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
    DRI(nbt);
    while (nbt--){
        DRI(n);
        int n2=2*n;
        VI a(n2);
        int td=0;
        REP(i,n2){
            RI(a[i]);
            if (a[i]==1) td++;
            else td--;
        }
        int inf=100000007;
        VI minposs=VI(4*n+1,inf);
        minposs[n2]=0;
        int cr=0;
        REPP(i,n,n2){
            if (a[i]==1) cr+=1;
            else cr-=1;
            minposs[cr+n2]=min(minposs[cr+n2],i-n+1);
        }
        cr=0;
       // cout<<"td "<<td<<endl;
       // cout<<"minposs :";
       // REP(i,minposs.size()) {cout<<(i-n2)<<" "<<minposs[i]<<endl;}
        int minres=minposs[n2+td];
        int ii=0;
        for (int i=n-1;i>=0;i--){
            ii++;
            if (a[i]==1) cr+=1;
            else cr-=1;
            minres=min(minres,minposs[n2+td-cr]+ii);
           // cout<<i<<" "<<ii<<" "<<n+td-cr<<" "<<minres<<endl;
        }
        printf("%d\n",minres);
    }
}