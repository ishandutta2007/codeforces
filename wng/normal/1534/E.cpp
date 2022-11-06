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


vector<pair<PII,int>> parents;
int k;
int n;

int build(VI whom){
    
    //cout<<"doing ";
    //for (auto i: whom) {cout<<i<<" ";} cout<<endl;
    int m=SZ(whom);
    if (!m) return 0;
    if (m==k){
        cout<<"?";
        for (auto i:whom)
            cout<<" "<<i;
        cout<<"\n";
        cout.flush();
        DRI(res);
        return res;
    }
    else{
        int n1=parents[m].F.F;
        int n2=parents[m].F.S;
        int common=parents[m].S;
        VI whom1(0), whom2(0);
        VI isin(n+1,0);
        REP(i,n1-common){
            whom1.PB(whom[i]);
        }
        //cout<<"doing 3 "<<n1<<" "<<n2<<" "<<m<<" "<<common<<endl;
        REP(i,n2-common){
            whom2.PB(whom[n1-common+i]);
        }
        for (auto i:whom) isin[i]=1;
        
        if (common)
            REPP(i,1,n+1){
                if (!isin[i]){
                    whom1.PB(i);
                    whom2.PB(i);
                    if (--common==0) break;
                }
            }
        //cout<<"doing 2";
        //for (auto i: whom1) {cout<<i<<" ";} cout<<endl;
        //for (auto i: whom2) {cout<<i<<" ";} cout<<endl;
        int res=build(whom1);
        //cout<<SZ(whom1)<<"+"<<SZ(whom2)<<"="<<res<<"^";
        int tb2=build(whom2);
        res^=tb2;
        //cout<<tb2<<"="<<res<<"\n";
    
        return res;
    }
}


int main(){
    R(n);
    R(k);
    int inf=1000000000;
    VI mincost(n+1,inf);
    mincost[0]=0;
    parents=vector<pair<PII,int>>(n+1);
    mincost[k]=1;
    VI jatried=VI(0);
    VI tt(1,k);
    while (SZ(tt)){
        VI ntt(0);
        for (auto i:tt){
            //with himself : je peux gnrer tous les nombres pairs entre 0 et 2*i
            VI mincosti(n+1,inf);
            VPII psi(n+1);
            REP(j,i+1){
                if (i+j<=n)
                    if (mincosti[2*j]>=2*mincost[i]){
                        mincosti[2*j]=2*mincost[i];
                        psi[2*j]={i,i-j};
                    }
            }
            for (auto ot: jatried){
                REP(common,min(ot,i)+1){
                    int nw=i-common+ot-common;
                    if (nw+common<=n and mincosti[nw]>=mincost[i]+mincost[ot]){
                        mincosti[nw]=mincost[i]+mincost[ot];
                        psi[nw]={ot, common};
                    }
                }
            }
            REP(j,n+1){
                if (mincosti[j]<mincost[j]){
                    if (mincost[j]==inf) ntt.PB(j);
                    mincost[j]=mincosti[j];
                    parents[j]={{i,psi[j].F},psi[j].S};
                }
            }
            jatried.PB(i);
        }
        tt=ntt;
    }

    /*REP(i,n+1){
        cout<<i<<" "<<mincost[i]<<"   "<<parents[i].F.F<<" "<<parents[i].F.S<<" "<<parents[i].S<<endl;
    }*/
    if (mincost[n]==inf){
        cout<<"-1\n";
        cout.flush();
    }
    else{
        //build
        VI tb(n,0);
        REP(i,n){
            tb[i]=i+1;
        }
        int bld=build(tb);
        cout<<"! "<<bld<<"\n";
        cout.flush();
    }
}