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


VI d1, dn;
vector<VI>cs;
VI ps;

int main(){
    DRIII(n,m,k);
    VI sf(k);
    d1=VI(n,-1);
    dn=VI(n,-1);
    ps=VI(n,-1);
    cs=vector<VI>(n);
    REP(i,k) {RI(sf[i]); sf[i]--;}
    REP(i,m){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        cs[y].PB(x);
    }
    d1[0]=0;
    VI tv(1,0);
    while (SZ(tv)){
        VI ntv(0);
        for (auto v:tv){
           // cout<<"ving "<<v<<endl;
            for (auto c:cs[v]){
                if (d1[c]==-1){
                    d1[c]=d1[v]+1;
                    ntv.PB(c);
                }
            }
        }
        tv=ntv;
    }
    dn[n-1]=0;
    tv=VI(1,n-1);
    while (SZ(tv)){
        VI ntv(0);
        for (auto v:tv){
            for (auto c:cs[v]){
                if (dn[c]==-1){
                    dn[c]=dn[v]+1;
                    ntv.PB(c);
                }
            }
        }
        tv=ntv;
    }
    /*cout<<"d1 :"<<endl;
    for (auto i:d1) cout<<i<<" "; cout<<endl;
    cout<<"dn :"<<endl;
    for (auto i:dn) cout<<i<<" "; cout<<endl;*/

    int basev=d1[n-1];
    vector<pair<PII,int>> poss;
    for (auto i:sf){
        PII np={d1[i],dn[i]};
        poss.PB({np,i});
    }
    sort(poss.rbegin(),poss.rend());
    int maxy=0;
    int bd=0;
    bool stry=false;
    for (auto i:poss){

        if (stry) bd=max(bd,min(basev,i.F.F+maxy+1));
        maxy=max(maxy,i.F.S);
        stry=true;
    }
    printf("%d\n",bd);
    /*
    return 0;
    vector<pair<PII,int>> p2;
    
    PII previous={0,0};
    for (auto i: poss){
        if (!SZ(p2)){
            p2.PB({i.F,-1});
            previous=i.F;
        }
        else{
            if (i.F.S>previous.S){
                p2.PB({i.F,-1});
                previous=i.F;
            }
            else{
                int cost=min(previous.S-i.F.S,previous.F-i.F.F);
                if (p2[SZ(p2)-1].S==-1 or p2[SZ(p2)-1].S>cost){
                    p2[SZ(p2)-1].S=cost;
                }
            }
        }
    }
    
    //cout<<"p2 :"<<endl;
    //for (auto i:p2) cout<<"{"<<i.F.F<<","<<i.F.S<<"):"<<i.S<<" ; "; cout<<endl;

    int bestdist=0;
    //bon j'ai tout...
    REP(i,SZ(p2)){
        if (i){
            //pairer i et i-1
            bestdist=max(bestdist,min(basev,min(p2[i].F.F+p2[i-1].F.S,p2[i].F.S+p2[i-1].F.F)+1));
        }
        if (p2[i].S!=-1) bestdist=max(bestdist,p2[i].F.F+p2[i].F.S-p2[i].S+1);
    }
    printf("%d\n",bestdist);*/
}