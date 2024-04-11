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
    DRI(n);
    DRVI(n,a);
    int prev=-1;
    int cnt=0;
    int res0=0;
    int pva(-1), pvb(-1);
    a.PB(-1);
    VI b(0);
    REP(i,n+1){
        if (a[i]!=prev){
            if (i<n) b.PB(a[i]);
            //cout<<i<<" "<<cnt<<" "<<pva<<" "<<pvb<<endl;
            if (cnt==1){
                if (pvb>0) pvb=-1;
                else { 
                    if (pva>0) {
                        if (pva!=prev) pva=-1;
                        else pvb=prev;
                    }
                }
                res0++;
            }
            else{
                if (cnt>1){
                    if (pva==prev) res0++;
                    else res0+=2;
                    pvb=prev;
                    pva=prev;
                }
            }
            prev=a[i];
            cnt=1;
        }
        else{
            cnt++;
        }
        //cout<<i<<" "<<a[i]<<" "<<res0<<endl;
    }
    int m=SZ(b);
    int res1=m;
    VI lastseen(n+1, -1);
    int lastjumpfrom=-1;
    int lastjumpto=1;
    REP(i,m){
        if (lastseen[b[i]]>=max(lastjumpfrom+1, lastjumpto-1)){
            res1--;
            lastjumpfrom=lastseen[b[i]];
            lastjumpto=i;
        }
        lastseen[b[i]]=i;
    }

    cout<<res1<<"\n";
}