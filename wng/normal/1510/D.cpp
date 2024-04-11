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
    DRII(n,d);
    DRVI(n,a);
    vector<VI> dd(10,VI(0));

    vector<VI> ddd(n+1,VI(10,-2));
    vector<VI> pred(n+1,VI(10,-2));
    vector<VI> pred2(n+1,VI(10,-2));
    vector<vector<double>> logs(n+1,vector<double>(10,0));
    ddd[0][1]=-1;
    REP(i,n){

        REP(j,10) {
            logs[i+1][j] = logs[i][j];
            ddd[i+1][j] = ddd[i][j];
            pred[i+1][j] = pred[i][j];
            pred2[i+1][j] = pred2[i][j];

        }

        REP(j,10){
            int nj=(j*a[i])%10;
            if (ddd[i][j]>-2){
                if (logs[i][j]+log(a[i])>=logs[i+1][nj]){
                    logs[i+1][nj] = logs[i][j]+log(a[i]);
                    ddd[i+1][nj] = a[i];
                    pred[i+1][nj] = j;
                    pred2[i+1][nj] = i;
                }
            }
        }
        //REP(j,10){cout<<SZ(dd[j])<<" ";} cout<<endl;
    }
    /*REP(i,n){
        REP(j,10){
            cout<<ddd[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //cout<<"oui"<<ddd[n][d]<<"\n";
    if (ddd[n][d]!=-2){
        VI res(0);
        int nn=n;
        int cj=d;
        while (nn>0){
            if (ddd[nn][cj] !=-1){
                res.PB(ddd[nn][cj]);
                int a = pred[nn][cj];
                int b = pred2[nn][cj];
                cj=a;
                nn=b;
            } else {
                break;
            }
        }
        int m=SZ(res);
        if (!m){
            cout<<"-1\n";
        }
        else{
            cout<<m<<endl;
            REP(i,m){
                cout<<res[i]<<(i==m-1?"\n":" ");
            }
        }
    }
    else{
        cout<<"-1\n";
    }
}