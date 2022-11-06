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

const int mod=1000000007;

LL powmod(LL a, LL n){
    LL baseval = (n%2)?(a%mod):1;
    if (n>=2){
        LL tm=powmod(a,n/2);
        baseval*=tm;
        baseval%=mod;
        baseval*=tm;
        baseval%=mod;
    }
    return baseval;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DRI(n);
    DRVI(n,a);
    LL sa=0;
    REP(i,n) sa+=a[i];
    if (sa%n!=0){
        cout<<"0\n";
    }
    else{
        LL avg=sa/n;
        int nbsc(0);
        int nbsk(0);
        map<int,int> scs;
        map<int,int> sks;
        int nba(0);
        REP(i,n){
            if (a[i]<avg) {nbsk++; sks[a[i]]++;}
            if (a[i]>avg) {nbsc++; scs[a[i]]++;}
           if (a[i]==avg) nba++;
        }
        LL res=1;
        //cout<<"metrics "<<nbsk<<" "<<nbsc<<" "<<nba<<endl;
        if (nbsc>1 and nbsk>1){
            int nleft=nbsc;
            for (auto i: scs){
                REP(j,i.S){
                    res*=nleft;
                    nleft--;
                    res%=mod;
                    if (j) {res*=powmod(j+1, mod-2); res%=mod;}
                }
            }
/*            REP(i,nbsc){
                res*=(i+1);
                res%=mod;
            }*/
            nleft=nbsk;
            for (auto i: sks){
                REP(j,i.S){
                    res*=nleft;
                    nleft--;
                    res%=mod;
                    if (j) {res*=powmod(j+1, mod-2); res%=mod;}
                }
            }
            REP(i,nba){
                res*=(n-i);
                res%=mod;
                if (i) {res*=powmod(i+1, mod-2); res%=mod;}
            }
            res*=2;
            res%=mod;
        }
        else{
            /*REP(i,n){
                res*=i+1;
                res%=mod;
            }*/
            int nleft=n;
            for (auto i: scs){
                REP(j,i.S){
                    res*=nleft;
                    nleft--;
                    res%=mod;
                    if (j) {res*=powmod(j+1, mod-2); res%=mod;}
                }
            }
            for (auto i: sks){
                REP(j,i.S){
                    res*=nleft;
                    nleft--;
                    res%=mod;
                    if (j) {res*=powmod(j+1, mod-2); res%=mod;}
                }
            }
            REP(i,nba){
                res*=(nleft-i);
                res%=mod;
                if (i) {res*=powmod(i+1, mod-2); res%=mod;}
            }
        }
        cout<<res<<"\n";
    }
}