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
    DRII(n,m);
    VPII a(n);
    VI mc(m+1,1000000);
    mc[0]=0;
    REP(i,n){
        DRII(x,y);
        a[i]={x-y-1,x+y-1};
        //cout<<x<<" "<<y<<" "<<a[i].F<<" "<<a[i].S<<endl;
    }
    int mintocover=1;
    sort(ALL(a));
    REP(i,n){
        REP(j,m){
            int x=a[i].F-j;
            int y=a[i].S+j;
            int nc=mc[max(0,x)]+j;
            int upto=min(y+1,m);
            while (mc[upto]>nc and upto) {mc[upto]=nc; upto--;}
            if (x<0 and y>=m) break;
        }
        //cout<<a[i].F<<" "<<a[i].S<<" "<<mc[42]<<" "<<mc[m]<<endl;
    }
    printf("%d\n",mc[m]);

}