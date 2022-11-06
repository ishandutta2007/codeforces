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
    DRI(n);
    VI a(n);
    int nf=-1;
    set<PII> cheapest;
    REP(i,n){
        RI(a[i]);
        if (a[i]==-1) nf=i;
    }
    if (nf==n-1) { printf("0\n"); return 0;}
    LL res=0;
    // on fait battre au premier les n/2 -1 plus chers parmi les n/2 meilleurs. Le cheapest sera le winner...
    cheapest.insert({a[n-1],n-1});
    while (n>=1){
            int costbribebest=cheapest.begin()->F;
            if (!costbribebest) {break;}
            res+=costbribebest;
            cheapest.erase(cheapest.begin());
            int nextn= n/2;
            for (int i=n-1; i>=nextn; i--) {
                if (a[i-1]==-1) {cheapest.insert({0,0}); break;}
                cheapest.insert({a[i-1],i-1});
            }
            //cout<<n<<" "<<nextn<<" "<<res<<" "<<costbribebest<<" "<<amiin<<endl;
            n/=2;
        }
    printf("%I64d\n",res);
}