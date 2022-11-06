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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    CASET{
        DRI(n);
        DRVI(n,u);
        DRVI(n,s);
        VPII a(n);
        REP(i,n) a[i]={u[i],s[i]};
        int pu=0;
        int pui=0;
        LL res=0;
        VL toadd(n+1,0);
        sort(ALL(a));
        a.PB({-1,0});
        int kk=0;
        for (auto c: a){
            if (c.F!=pu){
                VL ru(kk-pui+1,0);
                int nb=kk-pui;
                for (int i=kk-1; i>=pui;i--){
                   // cout<<"for "<<i<<" "<<a[i].S<<" "<<a[i].F<<endl;
                    int id=kk-1-i;
                    ru[id+1]=ru[id]+a[i].S;
                }
                res+=ru[nb];
                LL pv=nb;
                REP(i,nb+1){
                    LL nw=(nb/(i+1))*(i+1);
                 //   cout<<i<<"   "<<nw<<" "<<pv<<endl; 
                    if (nw!=pv){
                 //       cout<<"euh "<<nw<<" "<<pv<<endl;
                        toadd[i]+=ru[nw]-ru[pv];
                        pv=nw;
                    }
                    if (ru[pv]==0) break;
                }
                //for (auto i: ru)  cout<<i<<" "; cout<<endl;

                //cout<<"after "<<pu<<","<<res<<endl;
                //for (auto i: toadd) cout<<i<<" "; cout<<endl;
                pu=c.F;
                pui=kk;
            }
            kk++;
        }
        cout<<res;
        REP(i,n-1){
            res+=toadd[i+1];
            cout<<" "<<res;
        }
        cout<<"\n";
    }
}