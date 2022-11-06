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

int n;
VI a;

//int doomcount=0;

int f(int l, int r, int k){
    //kinear is fine
    //cout<<l<<" "<<r<<" "<<k<<" "<<doomcount<<endl;
    //doomcount++;
    //if (doomcount==100) {printf("%d\n",1/0);}
    if (k==-1) {return 0;}
    int t=1<<k;
    if ((a[l]^a[r])&t) {
        int kk=l;
        while (!(a[kk]&t)) kk++; 
        return t+min(f(l,kk-1,k-1),f(kk,r,k-1));
    }
    else{
        return f(l,r,k-1);
    }
}

int main(){
    RI(n);
    a=VI(n);
    REP(i,n) RI(a[i]);
    sort(ALL(a));
    printf("%d\n",f(0,n-1,29));
}