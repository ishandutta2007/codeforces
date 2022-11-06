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


vector<VI> pss;
VI r;

int ancetre(int u, int k){
    if (k==0) return u;
    if (k>r[u]) return -1;
    int tt=1;
    int kk=0;
    while (2*tt<=k){
        tt*=2;
        kk++;
    }
    return ancetre(pss[u][kk], k-tt);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    DRIII(q,a0, c0);
    pss=vector<VI>(1,VI(0));
    VL a(1,a0);
    VL c(1,c0);
    r=VI(1,0);
    VI ids(1,0);
    int hm=1;
    VI mapid(q+1,-1);
    mapid[0]=0;
    REPP(qid,1,q+1){
        DRI(qt);
        if (qt==1){
            ids.PB(qid);
            mapid[qid]=hm;
            DRIII(parent, ai, ci);
            a.PB(ai);
            c.PB(ci);
            int idp=mapid[parent];
            r.PB(r[idp]+1);
            pss.PB(VI(1,idp));
            int tt=1;
            int kk=0;
            while (2*tt<=r[hm]){
                pss[hm].PB(pss[pss[hm][kk]][kk]);
                kk++;
                tt<<=1;
            }
            hm++;
        }
        if (qt==2){
            int v;
            LL w;
            R(v);
            R(w);
            //localiser le plus vieil ancetre non vide en log(r)
            int whov=mapid[v];
            int cv=whov;
            if (a[cv]==0){
                cout<<"0 0\n";
                fflush(stdout);
            }
            else{
                int t=1;
                while (t<r[cv]){
                    t<<=1;
                }
                int tt=0;
                while (t){
                    if (tt+t<=r[whov] and a[ancetre(whov, tt+t)]>0) tt+=t;
                    t>>=1;
                }
                LL res=0;
                int totaltaken=0;
                //tt est le rang du plus vieil ancetre qui a de la thune.
                while (w){
                    int ca=ancetre(whov, tt);
                    int hmtt=min(w,a[ca]);
                    a[ca]-=hmtt;
                    res+=hmtt*c[ca];
                    w-=hmtt;
                    totaltaken+=hmtt;
                    tt--;
                    if (tt<0) break;
                }
                cout<<totaltaken<<" "<<res<<"\n";
                fflush(stdout);
            }
        }
    }
}