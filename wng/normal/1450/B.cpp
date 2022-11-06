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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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
        DRII(n,k);
        VPII a(n);
        vector<VI> cs(n,VI(0));
        REP(i,n){
            DRII(x,y);
            a[i]={x,y};
            REP(j,i){
                if (abs(a[i].F-a[j].F)+abs(a[i].S-a[j].S)<=k){
                    //cout<<"parenting "<<i<<" "<<j<<" "<<abs(a[i].F-a[j].F)+abs(a[i].S-a[j].S)<<endl;
                    cs[i].PB(j);
                    cs[j].PB(i);
                }
            }
        }
        int lim=10000;
        int minres=lim;
        REP(i,n){
            int r=0;
            VI lvl(n,-1);
            lvl[i]=0;
            queue<int> tt;
            tt.push(i);
            int nbv=0;
            //cout<<"doing "<<i<<endl;
            nbv++;
            int f=tt.front();
            tt.pop();
            int hm=0;
            for (auto c:cs[f]){
                if (lvl[c]==-1){
                    //cout<<c<<" is child of "<<f<<endl;
                    hm++;
                    lvl[c]=lvl[f]+1;
                    tt.push(c);
                    nbv++;
                }
            }
            if (hm) r++;
            //cout<<"for "<<i<<" "<<nbv<<endl;
            if (nbv==n) {minres=min(minres,r); break;}
        }
        if (minres==1) {printf("%d\n",minres);}
        else {printf("-1\n");}
    }
}