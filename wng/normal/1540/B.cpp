#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define R(X) cin>>(X)
#define RII(X, Y) cin>>(X)>>(Y)
#define RIII(X, Y, Z)  cin>>(X)>>(Y)>>(Z)
#define DRI(X) int (X); cin>>(X)
#define DRII(X, Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X, Y, Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I]) 
#define DRVL(N, X) VL X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I])
#define RS(X) cin>>X
#define DRS(X) string X; cin>>X
#define CASET int ___T, case_n = 1; cin>>___T; while (___T-- > 0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define PB push_back
#define F first
#define S second
    
using namespace std;


vector<VI> cs;
int n;

LL p;
LL q;
VI ps;
VI nbc;
VI lvl;

LL mod=1000000007;
pair<LL,LL> rr={0,1};

pair<LL,LL> addf(LL p2, LL q2, LL p1, LL q1){
    LL nnum=(p2*q1)%mod + (p1*q2)%mod;
    LL nden = (q2*q1)%mod;
    //cout<<"add "<<p2<<"/"<<q2<<"+"<<p1<<"/"<<q1<<"="<<nnum<<"/"<<nden<<endl;
    return {nnum%mod, nden};
}

pair<LL,LL> mulf(LL p2, LL q2, LL p1, LL q1){
    LL nnum=(p1*p2)%mod;
    LL nden = (q2*q1)%mod;
    //cout<<"muling "<<p2<<"/"<<q2<<"*"<<p1<<"/"<<q1<<"="<<nnum<<"/"<<nden<<endl;
    return {nnum, nden};
}

vector<vector<PLL>> mns(201, vector<PLL>(201,{0,0}));


PLL magicnumber(int d0, int d1){
    return mns[d0][d1];
}


int dfscc(int i, int basei, int lv){
    int res=1;
    for (auto c:cs[i]){
        if (ps[c]==-1){
            ps[c]=i;
            lvl[c]=lv+1;
            res+=dfscc(c, basei, lv+1);
        }
    }
    nbc[i]=res;
    return res;
}

inline long long mpow(long long b, long long ex){
    if (b==1)return 1;
    long long r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p=0;
    q=0;

    REPP(i,1,200){
        mns[0][i]={1,1};
        mns[i][0]={0,1};
    }

    REPP(i,1,200){
        REPP(j,1,200){
            mns[i][j]=addf(mns[i-1][j].F, mns[i-1][j].S*2, mns[i][j-1].F, mns[i][j-1].S*2);
        }
    }

    //REP(i,10){
    //    REP(j,10){
    //        cout<<i<<","<<j<<": "<<mns[i][j].F<<"/"<<mns[i][j].S<<endl;
    //    }
    //}

    R(n);
    cs=vector<VI>(n,VI(0));
    REP(i,n-1){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        cs[y].PB(x);
    }

    REP(i,n){
        ps=VI(n,-1);
        nbc=VI(n,0);
        lvl=VI(n,0);
        ps[i]=i;
        dfscc(i,i,0);
        //cout<<"done "<<i<<" "<<rr.F<<"/"<<rr.S<<endl;
        REPP(j,i+1,n){
            rr=addf(rr.F, rr.S, nbc[j], n); // enfants de i
            int ii=j;
            ii=ps[ii];
            int pnbc=nbc[j];
            while (ii!=i){
                int distb= lvl[ii];
                int disti=lvl[j]-distb;
                int nbcii=nbc[ii]-pnbc;
                //cout<<j<<" "<<ii<<" nbc"<<nbcii<<endl;
                //for (auto nbb: nbc) cout<<nbb<<" "; cout<<endl;
                pnbc=nbc[ii];

                pair<LL,LL> toadd=magicnumber(disti,distb);
                toadd=mulf(toadd.F, toadd.S, nbcii, n);
                rr=addf(rr.F, rr.S, toadd.F, toadd.S);
                ii=ps[ii];
            }
        }
    }
    
    LL realres=(rr.F*mpow(rr.S,mod-2))%mod;
    cout<<realres<<"\n";
    }