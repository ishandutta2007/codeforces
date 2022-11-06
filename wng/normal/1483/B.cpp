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
        int numeat=0;
        DRI(n);
        DRVI(n,a);
        VI nextnode(n,0);
        REP(i,n){
            nextnode[i]=(i+1)%n;
        }
        VI res(0);
        VI dateeaten(n,-1);
        VI lastmeal(n,-1);
        VI listtocheck(0);
        REP(i,n){listtocheck.PB(i);}
        int j=0;
        while (SZ(listtocheck)){
            VI nltc(0);
            for (auto i: listtocheck){
                if (dateeaten[i]<0){
                    int cnn=nextnode[i];
                    int gcd=__gcd(a[i], a[cnn]);
                    //cout<<"euuh "<<i<<" "<<cnn<<" "<<gcd<<endl;
                    if (gcd==1){
                        if (cnn!=i) nltc.PB(i);
                        dateeaten[cnn]=numeat++;
                        res.PB(cnn);
                        nextnode[i]=nextnode[cnn];
                    }
                }
            }
            j++;
            listtocheck=nltc;
        }
        cout<<SZ(res);
        int sr=SZ(res);
        REP(i,sr){
                cout<<" "<<(res[i]+1);
        }
        cout<<"\n";
    }
}