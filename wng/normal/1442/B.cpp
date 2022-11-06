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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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

const int mod = 998244353;
int main(){
    CASET{
        DRII(n,k);
        DRVI(n,a);
        DRVI(k,b);
        REP(i,n) {a[i]--;}
        REP(i,k) b[i]--;
        VI c(n);
        REP(i,n){
            c[a[i]]=i;
        }
        VI ob(k);
        REP(i,k) ob[i]=c[b[i]];

       /* for (auto i:a) cout<<i<<" "; cout<<endl;
        for (auto i:b) cout<<i<<" "; cout<<endl;
        for (auto i:c) cout<<i<<" "; cout<<endl;
        for (auto i:ob) cout<<i<<" "; cout<<endl;*/
        LL r=1;
        VI jadone(n,0);
        for (int i=k-1;i>=0;i--){
            jadone[ob[i]]=1;
           // cout<<i<<" "<<ob[i]<<endl;
            int nbp=2;
            if (ob[i]==n-1 or jadone[ob[i]+1]) nbp--;
            if (ob[i]==0 or jadone[ob[i]-1]) nbp--;
            r*=nbp;
            r%=mod;
        }
       /* for (auto i:jadone) cout<<i<<" "; cout<<endl;
        for (auto i:ob) cout<<i<<" "; cout<<endl;*/
        printf("%I64d\n",r);
    }

}