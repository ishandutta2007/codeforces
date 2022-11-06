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
    DRI(k);
    string s;
    R(s);
    reverse(s.begin(), s.end());
    VI tt(1<<k,0);
    int n=1<<(k-1);
    REP(i,n){
        tt[n+i]=(s[n+i-1]=='?')?2:1;
    }
    for (int i=n-1;i>=1; i--){
        int location = i-1;
        //cout<<i<<"  "<<location<<endl;
        if (s[location]=='0') tt[i]=tt[2*i+1];
        if (s[location]=='1') tt[i]=tt[2*i];
        if (s[location]=='?') tt[i]=tt[2*i]+tt[2*i+1];
    }
    //for (auto i:tt) {cout<<i<<" ";} cout<<endl;
    DRI(q);
    REP(i,q){
        DRI(x);
        x=2*n-x;
        string cc;
        R(cc);
        char c=cc[0];
        s[x-1]=c;
        int fx=x-1;
        int rloc = x;
        int fn=n;
        while (x){
            if (x>=n){
                tt[x]=(s[x-1]=='?')?2:1;
            }
            else{
                if (s[x-1]=='0') tt[x]=tt[2*x+1];
                if (s[x-1]=='1') tt[x]=tt[2*x];
                if (s[x-1]=='?') tt[x]=tt[2*x]+tt[2*x+1];
            }
            x>>=1;
        }
        //cout<<s<<endl;
        //for (auto i:tt) {cout<<i<<" ";} cout<<endl;
        cout<<tt[1]<<"\n";
    }
}