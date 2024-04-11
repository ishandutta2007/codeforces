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
    DRI(q);
    REP(nt,q){
        DRI(n);
        VI a(n);
        VI b(n+1);
        REP(i,n) {RI(a[i]); b[a[i]]++;}
        int N=0;
        REPP(i,1,n+1) {if (b[i]) b[i]=++N;}
        REP(i,n){ a[i]=b[a[i]];}
        //determine c[i]= biggest j<i that appears after a i (1<=i<=N)
        VI c(N+1,N+1);
        set<int> suff;
        for (int i=n-1;i>=0;i--){
            set<int>::iterator it = suff.lower_bound(a[i]);
            if (it!=suff.begin()){
                it--;
                c[a[i]]=*it;
            }
            suff.insert(a[i]);
        }
        int ps=N-1;
        int ms=0;
        REPP(i,1,N+1){
            if (c[i]<N+1) ms=max(ms,c[i]);
            ps=min(ps,ms+N-i);
        }
        printf("%d\n",ps);
    }
}