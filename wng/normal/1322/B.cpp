#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).rbegin(), (X).rend()
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
    REP(i,n) {RI(a[i]);}
    sort(ALL(a));
    int ms=a[0];
    int t=1;
    int k=0;
    while ((t<<1)<=ms) {t<<=1; k++;}

    
    VI ts(k+2,1);
    REP(i,k+1) {
        ts[i+1]=ts[i]<<1;
    }
    int res=0;
    VI nbk1(k+1,0);
    REP(i,n){
        REP(j,k+1){
            if (a[i]&ts[j]){
                nbk1[j]++;
            }
        }
    }
    //cb de paires above t<<1?
    while (k>=0){
        int p1=0;
        int p2=n-1;
        LL nbat1=0;
        while (p1<n){
            while (p2>=0 and a[p1]+a[p2]<(t<<1)) p2--;
            if (p2<=p1) break;
            nbat1+=(p2-p1);
         //   cout<<"add "<<p1<<" "<<p2<<" "<<(t<<1)<<endl;
            p1++;
        }
        //cout<<t<<" "<<nbat1<<" "<<k<<endl;
        if (nbat1%2) res^=ts[k+1];
        if (nbk1[k]%2 and (n+1)%2) res^=ts[k];
        REP(i,n){
            if (a[i]&t) a[i]^=t;
        }
        sort(ALL(a));
        t>>=1;
        k--;
    }

    printf("%d\n",res);

}