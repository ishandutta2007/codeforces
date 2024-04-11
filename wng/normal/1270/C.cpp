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
    DRI(t);
    while (t--){
        DRI(n);
        VI a(n);
        LL sa=0;
        LL xa=0;
        REP(i,n){
            RI(a[i]);
            sa+=a[i];
            xa^=a[i];
        }
        VL ta(0);
        //cout<<sa<<" "<<xa<<endl;
        if (sa%2){
            LL tt=0;
            while (sa+tt+1>2*(xa^(tt+1))) { if (tt) tt<<=1; else tt=2;}
            ta.PB(tt+1);
            xa^=tt+1;
            sa+=tt+1;
        }
        else {
            LL tt=0;
            while (sa+tt>2*(xa^(tt))) {
                //cout<<"put"<<tt<<" "<<sa+tt<<" "<<2*(xa^(tt))<<endl;
                if (tt) tt<<=1; else tt=2;}
            if (tt){
                ta.PB(tt);
                sa+=tt;
                xa^=tt;
            }
        }
       // cout<<sa<<" "<<xa<<" "<<ta.size()<<endl;
        // ok now
        LL x= 2*xa-sa;
        assert (x>=0);
        if (x!=0){
            ta.PB(x/2);
            ta.PB(x/2);
        }
        printf("%d\n",ta.size());
        REP(i,ta.size()){
            printf("%I64d ",ta[i]);
        }
        printf("\n");
    }
}