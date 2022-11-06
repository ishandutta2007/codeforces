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
        string s;
        R(s);
        int n=SZ(s);
        int nb0=0;
        int nb1=0;
        LL res=0;
        REP(i,n){
            if (s[i]=='1'){
                nb1=nb0+1;
                nb0=0;
            }
            if (s[i]=='0'){
                nb0=nb1+1;
                nb1=0;
            }
            if (s[i]=='?'){
                int onb0=nb0;
                nb0=nb1+1;
                nb1=onb0+1;
            }
            res+=nb0+nb1;
        }
        //cout<<"preres "<<res<<endl;

        s+='1';
        int i=0;
        while (i<n){
            if (s[i]=='?'){
                LL c=1;
                while (s[i+1]=='?'){
                    i++;
                    c++;
                }
                res-=c*(c+1)/2;
            }
            i++;
        }
        cout<<res<<"\n";
    }
}