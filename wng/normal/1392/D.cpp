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
        int n;
        cin>>n;
        string s;
        cin>>s;
        VI a(n,0);
        REP(i,n){
            if (s[i]=='L') a[i]=1;
        }
        REP(i,min(3,n)) a.PB(a[i]);
        int N=SZ(a);
        int bestsol=n;
        REP(i,N-n+1){
            // ca part de l
            VI poss(4, 1000000);
            poss[0]=0;
            /*cout<<"poss : ";
            for (auto k: poss) {cout<<k<<" ";} cout<<endl;*/
            REP(j,n){
                VI nposs(4, 1000000);
                nposs[0]=min(nposs[0], poss[3] + (1-a[i+j]));
                nposs[1]=min(nposs[1], poss[3] + a[i+j]);
                nposs[1]=min(nposs[1], poss[0] + a[i+j]);
                nposs[3]=min(nposs[3], poss[1] + (1-a[i+j]));
                nposs[2]=min(nposs[2], poss[1] + a[i+j]);
                nposs[3]=min(nposs[3], poss[2] + (1 - a[i+j]) );
                poss=nposs;
                /*cout<<j<<" poss : ";
                for (auto k: poss) {cout<<k<<" ";} cout<<endl;*/
            }
            bestsol=min(bestsol, min(poss[3], poss[0]));
            //cout<<"starting in "<<i<<" bestsol : "<<poss[3]<<" "<<poss[0]<<endl;
        }
        cout<<bestsol<<"\n";
    }
}