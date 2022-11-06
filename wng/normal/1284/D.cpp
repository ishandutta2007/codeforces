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
    VPII a(n);
    VPII b(n);
    VPII c;
    VPII d;
    REP(i,n){
        RII(a[i].F,a[i].S);
        RII(b[i].F,b[i].S);
        c.PB({a[i].F,-i-1});
        c.PB({a[i].S,i+1});
        d.PB({b[i].F,-i-1});
        d.PB({b[i].S,i+1});
    }
    sort(ALL(c));
    sort(ALL(d));
    map<int,int> mstarts;
    map<int,int> ends;
    bool isok=true;
    for (auto i:c){
        if (i.S<0){
            int j=-i.S-1;
            if (mstarts.size()){
                if ( -(mstarts.begin()->F)>b[j].S) isok=false;
                if ( ends.begin()->F<b[j].F) isok=false;
            }
            mstarts[-b[j].F]++;
            ends[b[j].S]++;
        }
        else{
            int j=i.S-1;
            mstarts[-b[j].F]--;
            ends[b[j].S]--;
            if (!mstarts[-b[j].F]) mstarts.erase(-b[j].F);
            if (!ends[b[j].S]) ends.erase(b[j].S);
        }
        if (!isok) {break;}
    }
    mstarts.clear();
    ends.clear();
    for (auto i:d){
        if (i.S<0){
            int j=-i.S-1;
            if (mstarts.size()){
                if ( -(mstarts.begin()->F)>a[j].S) isok=false;
                if ( ends.begin()->F<a[j].F) isok=false;
            }
            mstarts[-a[j].F]++;
            ends[a[j].S]++;
        }
        else{
            int j=i.S-1;
            mstarts[-a[j].F]--;
            ends[a[j].S]--;
            if (!mstarts[-a[j].F]) mstarts.erase(-a[j].F);
            if (!ends[a[j].S]) ends.erase(a[j].S);
        }
        if (!isok) {break;}
    }
    if (isok) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

}