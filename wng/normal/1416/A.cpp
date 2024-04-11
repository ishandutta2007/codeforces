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

int main(){
    CASET{
        DRI(n);
        VI a(n);
        VI b(n,-1);
        VI c(n,0);
        REP(i,n){
            DRI(x);
            x--;
            a[i]=x;
            c[a[i]]=max(c[a[i]],i-b[a[i]]);
            b[a[i]]=i;
        }
        set<PII> s;
        REP(i,n){
            c[i]=max(c[i], n-b[i]);
            s.insert({c[i],i+1});
        }

        int lim=1000000;
        int mr=lim;
        auto it=s.begin();
        REPP(i,1,n+1){
            while (it!=s.end() and it->F<=i){
                mr=min(mr,it->S);
                it++;
            }
            if (mr<lim){
                printf("%d",mr);
            }
            else{
                printf("-1",mr);
            }
            printf("%c",(i==n)?'\n':' ');
        }
    }

}