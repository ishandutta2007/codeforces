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
        DRII(n,m);
        VI r(2,0);
        bool isok=true;
        REP(i,n){
            string s;
            R(s);

            REP(j,m){
                int tp=0;
                if (s[j]!='.'){
                    if (s[j]=='R'){
                        tp=1;
                    }
                    else tp=-1;
                }
                if (tp){
                    int w=(i+j)%2;
                    if (r[w] and r[w]!=tp) 
                        isok=false;
                    r[w]=tp;
                }
            }
        }
        if (r[0] and r[0]==r[1]) isok=false;
        if (r[0]==0 and r[1]==0) {r[0]=1; r[1]=-1;}
        if (r[0]==0) r[0]=-r[1];
        if (r[1]==0) r[1]=-r[0];
        if (isok){
            cout<<"YES\n";
            REP(i,n){
                REP(j,m){
                    cout<<(r[(i+j)%2]==1?"R":"W");
                }
                cout<<"\n";
            }
        }
        else cout<<"NO\n";
    }
}