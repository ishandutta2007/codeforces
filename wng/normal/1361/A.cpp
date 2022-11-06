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
    DRII(n,m);
    vector<VI> cs(n,VI(0));
    REP(i,m){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        cs[y].PB(x);
    }
    VPII a(n);
    REP(i,n){
        DRI(x);
        a[i]={x,i};
    }
    /*
    for (auto i:a){
        cout<<"jj "<<i.F<<" "<<i.S<<";";
    }
    cout<<endl;*/
    bool isok=true;
    VI res(0);
    sort(ALL(a));
    VI hn(n,0);
    VI done(n,0);
    for (auto i: a){
        int x,p;
        x=i.F;
        p=i.S;
        res.PB(p+1);
       // cout<<x<<" "<<p<<" "<<hn[p]<<endl;
        if (hn[p]!=x-1){
            isok=false;
            break;
        }
        done[p]=1;
        for (auto c: cs[p]){
            
            if (!done[c] and hn[c]<x-1){
           // cout<<"breaking "<<c<<" "<<x<<" "<<hn[c]<<endl;
                isok=false;
                break;
            }
            hn[c]=max(hn[c],x);
           // cout<<"bordel "<<c<<" "<<x<<" "<<hn[c]<<endl;
        }
        if (!isok) break;
    }
    if (!isok){
        printf("-1\n");
    }
    else{
        REP(i,n){
            printf("%d%c",res[i],(i==n-1)?'\n':' ');
        }
    }
}