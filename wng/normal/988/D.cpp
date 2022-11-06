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
    int n;
    RI(n);
    VI a(n);
    int am=1<<30;
    REP(i,n) {RI(a[i]);}
    sort(a.begin(),a.end());
    set<int> s;
    int res=0;
    VI brr(4);
    brr[0]=a[0];
    for (auto i:a){
        int it=1;
        s.insert(i);
        while (true){
            if (s.count(i-it)){
                if (s.count(i-2*it)) {
                    if (res<2) {brr[0]=i-it; brr[1]=i;brr[2]=i-2*it;}
                    res=max(2,res);} 
                else{
                    if (res<1) {brr[0]=i-it; brr[1]=i;}
                    res=max(1,res);
                }
            }
            if (it==am) break;
            it<<=1;
        }
    }
    res++;
    printf("%d\n",res);
    REP(i,res){ printf("%d%c",brr[i],i==res-1?'\n':' ');}
}