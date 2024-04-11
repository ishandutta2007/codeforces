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
    VI place(n);
    VI a(n);
    VPII res(0);
    REP(i,n){
        DRI(x);
        x--;
        a[i]=x;
        place[x]=i;
    }
    int ns2=n/2;
    REP(i,n){
        int j=place[i];
        if (place[i]!=i){
            if (place[i]-i>=ns2) {res.PB({i+1,place[i]+1});}
            else{
                bool abovei=(i>=ns2);
                bool abovej=(place[i]>=ns2);
                if (abovei and abovej) {
                    res.PB({1,j+1});
                    res.PB({1,i+1});
                    res.PB({1,j+1});
                }
                if ((!abovei) and (!abovej)) {
                    res.PB({n,j+1});
                    res.PB({n,i+1});
                    res.PB({n,j+1});
                }
                if ((!abovei) and (abovej)){
                    res.PB({1,j+1});
                    res.PB({n,1});
                    res.PB({n,i+1});
                    res.PB({n,1});
                    res.PB({1,j+1});
                }
                if ((abovei) and (!abovej)){
                    res.PB({n,j+1});
                    res.PB({n,1});
                    res.PB({1,i+1});
                    res.PB({n,1});
                    res.PB({n,j+1});
                }
            }
            // take care of j!!!
            int deplace=a[i];
            a[i]=i;
            a[j]=deplace;
            place[deplace]=j;
            place[i]=deplace;
        }
    }
    printf("%d\n",res.size());
    REP(i,res.size()){
        printf("%d %d\n",res[i].F,res[i].S);
    }

}