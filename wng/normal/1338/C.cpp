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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nbt;
    cin>>nbt;
    while (nbt--){
        LL n;
        cin>>n;
        LL k=(n-1)/3;
        int rk=(n-1)%3;
        int i=0;
        while (k >= (1LL<<(2*i))){
            k-=1LL<<(2*i);
            i++;
        }
        LL d2i=1LL<<(2*i);
        LL t0=d2i+k;
        if (rk==0){
            cout<<t0<<"\n";
            continue;
        }
        VI u={0,2,3,1};
        LL t1=(d2i<<1);
        while (k){
            d2i>>=2;
            int part=k/d2i;
            t1+=u[part]*d2i;
            k%=d2i;
        }
        LL t2=t1^t0;
        if (rk==1){
            cout<<t1;
        }
        else{
            cout<<t2;
        }
        cout<<"\n";
    }
}