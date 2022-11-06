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
    CASET{
        LL n,m;
        scanf("%I64d%I64d",&n,&m);
        VL a(64,0);
        LL s=0;
        REP(i,m){
            DRI(x);
            s+=x;
            int k=-1;
            while (x){
                x/=2;
                k++;
            }
            a[k]++;
        }
        if (s<n){
            printf("-1\n");
            continue;
        }
        LL y=1;
        int kk=0;
        int nbd=0;
        while (y<=n){
            if (y&n){
                if (a[kk]>0) a[kk]--;
                else {
                    int nk=kk;
                    while (a[nk]==0) nk++;
                    a[nk]--;
                    for (int j=nk-1;j>=kk;j--) a[j]++;
                    nbd+=(nk-kk);
                }
            }
            a[kk+1]+=a[kk]/2;
            y<<=1;
            kk++;
        }
        cout<<nbd<<"\n";
    }

}