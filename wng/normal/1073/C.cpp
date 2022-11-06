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


int md(PII a,PII b){
    return abs(a.F-b.F)+abs(a.S-b.S);
}

int main(){
    DRI(n);
    char s[200009];
    RS(s);
    DRII(x,y);
    VPII a(n+1,{0,0});
    REP(i,n){
        a[i+1]=a[i];
        if (s[i]=='R') a[i+1].F++;
        if (s[i]=='L') a[i+1].F--;
        if (s[i]=='U') a[i+1].S++;
        if (s[i]=='D') a[i+1].S--;
        //cout<<a[i+1].F<<","<<a[i+1].S<<endl;
    }       
    int kk=-1;
    int t=1<<20;
    if ((n-x+y)%2 or n<abs(x)+abs(y)) {printf("-1\n"); return 0;}
    //PII left= {x-a[n].F,y-a[n].S};
    //cout<<left.F<<" "<<left.S<<endl;
    while (t){
        if (kk+t<=n){
            int tt=kk+t;
            int mind=md({x,y},{a[n].F-(a[tt].F-a[0].F),a[n].S-(a[tt].S-a[0].S)});
            REPP(i,1,n-tt+1){
                mind=min(mind,md({x,y},{a[n].F-(a[tt+i].F-a[i].F),a[n].S-(a[tt+i].S-a[i].S)}));
            }
            if (mind>tt){
                kk=tt;
            }
          // cout<<t<<" "<<tt<<" "<<mind<<endl;
        }
        t>>=1;
    }
    printf("%d\n",kk+1);
}