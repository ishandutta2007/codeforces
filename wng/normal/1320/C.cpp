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
/*
int lim=1<<19;
vector<LL> st(lim+1,0); //running 

void add(int ii, int v){
    while (ii<=lim){
        st[ii]+=v;
        ii+=ii&-ii;
    }
}


int getv(int ii, int v){
    int res=0;
	while (ii>0){
		res+=st[ii];
		ii-=ii&-ii;
	}
    return res;
}*/


int main(){
    DRIII(n,m,p);
    VPII ws(n);
    VPII as(m);
    REP(i,n){
        DRII(x,y);
        ws[i]={x,y};
    }
    REP(i,m){
        DRII(x,y);
        as[i]={x,y};
    }
    sort(ALL(ws));
    VPII wws;
    PII lastw;
    REP(i,n){
        if (!i or ws[i].F>lastw.F) {
            while (SZ(wws) and wws[SZ(wws)-1].S>=ws[i].S) {wws.pop_back();}
            wws.PB(ws[i]);
            lastw=ws[i];
        }
    }
    ws=wws;
    n=SZ(ws);

    sort(ALL(as));
    VPII aas;
    PII lasta;
    REP(i,m){
        if (!i or as[i].F>lasta.F) {
            while (SZ(aas) and aas[SZ(aas)-1].S>=as[i].S) {aas.pop_back();}
            aas.PB(as[i]);
            lasta=as[i];
        }
    }
    as=aas;
    m=SZ(as);
    map<int,int> armors;
    armors[as[0].F]=as[0].S;
    REP(i,m-1){
        armors[as[i+1].F]=as[i+1].S-as[i].S;
    }
    //map<int,map<int,int>> mechants;
    vector<pair<int,PII>> m2;
    REP(i,p){
        DRIII(x,y,z); 
        m2.PB({x,{y,z}});
        //mechants[x][y]+=z;
    }
    sort(ALL(m2));
    int kw=0;
    int ka=0;
    LL br=-1000000000;
    br*=4;
    int cw=0;
    bool isok=false;
    for (auto bg:m2){
        int def=bg.F;
        while (kw<n and ws[kw].F<=def) {kw++;}
        if (kw==n) break;
        cw=ws[kw].S;
        auto bestarmor=armors.lower_bound(bg.S.F+1);
        if (bestarmor==armors.end()) continue;
        //add(bg.S.F, bg.S.S);
        bestarmor->S-=bg.S.S;
        if (bestarmor->S<=0){
            if (bestarmor!=armors.begin()){
                auto it=bestarmor;
                while (bestarmor->S<=0){
                    it--;
                    bestarmor->S+=it->S;
                    if (it==armors.begin()) break;
                }
                assert(it!=bestarmor);
                armors.erase(it,bestarmor);
            }
        }
        /*cout<<"  "<<bg.F<<"  "<<bg.S.F<<" "<<bg.S.S<<endl;
        for (auto i:armors){
            cout<<i.F<<","<<i.S<<";";
        }
        cout<<endl;
        cout<<" "<<cw<<endl;*/
        LL res=-armors.begin()->S-cw;
        br=max(br,res);
        isok=true;
    }
    if (isok)
    printf("%I64d\n",br);
    else (printf("%I64d\n",-(LL)ws[0].S-as[0].S));
}