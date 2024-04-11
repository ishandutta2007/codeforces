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
        string s;
        R(s);
        int c1=0;
        REP(i,n){
            if (s[i]=='1') c1++;
        }
        bool isok=true;
        if (c1%2){
            isok=false;
        }
        VI a(n,0);
        VI b(n,0);
        int ca=0;
        int cb=0;
        if (isok){
            int k1=0;
            int k2=0;
            REP(i,n){
                if (s[i]=='1'){
                    if (k1++<c1/2){
                        a[i]=1;
                        b[i]=1;
                    }
                    else{
                        a[i]=-1;
                        b[i]=-1;
                
                    }
                }
                else{
                    if (k2++%2){
                        a[i]=-1;
                        b[i]=1;
                    }
                    else{
                        a[i]=1;
                        b[i]=-1;
                    }
                }
                ca+=a[i];
                cb+=b[i];
                if (min(ca,cb)<0) {isok=false; break;}
            }
        }
        if (isok) {
            assert(ca==cb and ca==0);
            cout<<"YES\n";
            REP(i,n){
                cout<<(a[i]==1?"(":")");
            }
            cout<<"\n";
            REP(i,n){
                cout<<(b[i]==1?"(":")");
            }
            cout<<"\n";
        }
        else cout<<"NO\n";

    }
}