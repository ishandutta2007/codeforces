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
    CASET{
        LL p;
        int q;
        scanf("%I64d %d",&p,&q);
        
        if (p%q) {
            printf("%I64d\n",p);
            continue;
        }
        map<int,int> m;
        map<int,int> mp;
        int i=2;
        LL np=p;
        while (i*i<=q){
            
            int qq=q%i;
            if (qq==0){
                while (p%i==0){
                    p/=i;
                    mp[i]++;
                }
            }
            while (q>1 and qq==0){
                q/=i;
                m[i]++;
                qq=q%i;
            }
            i++;
        }
        if (q>1){
            m[q]++;
            while (p%q==0){
                p/=q;
                mp[q]++;
            }
        }
        LL smallestdiv=np;
        for (auto d: m){
            int nbtr= 1 + max(mp[d.F]-d.S,0);
            LL sd=1;
            REP(i, nbtr) sd*=d.F;
            //cout<<d.F<<"  "<<sd<<" ("<<d.S<<","<<mp[d.F]<<endl;
            smallestdiv=min(sd,smallestdiv);   
        }
        printf("%I64d\n",np/smallestdiv);
    }
}