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


VI ved;
vector<VI> cs;
int n;
VL br0, br1;
VI a,b;

void solve(int i){
    if (ved[i]==0){
        ved[i]=1;
        for (auto c: cs[i]){
            if (!ved[c]){
                solve(c);
                br0[i]+= max( br0[c] + abs(a[c] - a[i]),  br1[c] + abs(b[c] - a[i]));
                br1[i]+= max( br0[c] + abs(a[c] - b[i]),  br1[c] + abs(b[c] - b[i]));
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CASET{
        R(n);
        cs = vector<VI>(n, VI(0));
        ved=VI(n,0);
        a=VI(n);
        b=VI(n);
        REP(i,n) {
            RII(a[i], b[i]);
        }
        br0=VL(n,0);
        br1=VL(n,0);

        REP(i,n-1){
            DRII(x,y);
            x--;
            y--;
            cs[x].PB(y);
            cs[y].PB(x);
        }
        solve(0);
        /*for (auto i: br0){
            cout<<i<<" ";
        }
        cout<<endl;

        for (auto i: br1){
            cout<<i<<" ";
        }
        cout<<endl;*/

        cout<<max(br0[0], br1[0])<<"\n";
    }
}