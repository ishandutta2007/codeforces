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
    REP(i,n) RI(a[i]);
    VI t(n);
    REP(i,n) RI(t[i]);
    vector<pair<PII,int>> s(n);
    REP(i,n){
        s[i]={{a[i],t[i]},i};
    }
    sort(ALL(s));
    LL res=0;
    LL st=0;
    int k=0;
    int curn=0;
    set<PII> cs;
    while (true){
        if (!cs.empty()){
            int tmin=cs.begin()->F;
            cs.erase(cs.begin());
            st+=tmin;
         //   cout<<"adding "<<st<<endl;
            res+=st;
            curn++;
        }
        else{
            curn=s[k].F.F;
        }
        while (k<n and s[k].F.F==curn){
            cs.insert({-s[k].F.S,s[k].S});
            st+=s[k].F.S;
            k++;
        }
       // cout<<k<<" "<<curn<<" "<<st<<" "<<SZ(cs)<<endl;
       // for (auto i:cs) {cout<<i.F<<","<<i.S<<";";} cout<<endl;
        if (k==n and cs.empty()) break;
    }
    printf("%I64d\n",res);

}