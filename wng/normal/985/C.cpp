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
    int n,k,l;
    RIII(n,k,l);
    int nbb=n*k;
    VI v(nbb);
    REP(i,nbb) {RI(v[i]);}
    sort(v.begin(),v.end());
    LL lim=(LL)v[0]+l;
    if (v[n-1]>lim) { printf("0\n"); return 0;}
    int i=n-1;
    while (i<nbb and v[i]<=lim) {i++;}
    LL res=0;
    int nbc=0;
    vector<bool> chopes(i,false);
    int nbl=i;
    for (int j=0;j<i;j+=k){
        chopes[j]=true;
        res+=v[j];
        nbc++;
        nbl--;
        if (nbc==n){
            break;
        }
    }
    int it=i-1;
    while (nbc<n){
        if (!chopes[it]) {
            nbc++;
            nbl--;
            chopes[it]=true;
            res+=v[it];
        }
        it--;
    }
    
    printf("%I64d\n",res);
}