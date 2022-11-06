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
        VI c0(3,0);
        vector<string> ss(3);
        REP(i,3){R(ss[i]);}
        REP(i,3){
            REP(j,2*n){
                if (ss[i][j]=='0') c0[i]++;
            }
        }
        //for (auto i:c0) {cout<<i<<" ";} cout<<endl;
        //for (auto i:ss) {cout<<i<<" ";} cout<<endl;
        VI l0(0);
        VI l1(0);
        REP(i,3){
            if (c0[i]>=n) l0.PB(i);
            if (c0[i]<=n) l1.PB(i);
        }/*
        //custom sort! what could go wrong?
        if (c0[0]>c0[1]){
            swap(ss[0],ss[1]);
            swap(c0[0],c0[1]);
        }
        if (c0[1]>c0[2]){
            swap(ss[2],ss[1]);
            swap(c0[2],c0[1]);
        }
        if (c0[0]>c0[1]){
            swap(ss[0],ss[1]);
            swap(c0[0],c0[1]);
        }*/
        int pivot=-1;
        int x,y;
        if (SZ(l0)>1){
            pivot=0;
            x=l0[0];
            y=l0[1];
        }
        else{
            pivot=1;
            x=l1[0];
            y=l1[1];
        }
        //cout<<"xy "<<x<<" "<<y<<" "<<pivot<<endl;
        string res="";
        int i=0;
        int j=0;
        while (max(i,j)<2*n){
            if (ss[x][i]==ss[y][j]) {res+=ss[x][i]; i++; j++;}
            else{
                if (ss[x][i]-'0'!=pivot) {res+=ss[x][i]; i++;}
                else {res+=ss[y][j]; j++;}
            }
            //cout<<i<<" a "<<j<<" "<<res<<endl;
        }
        while (i<2*n){
            res+=ss[x][i]; i++;
            //cout<<i<<" b "<<j<<" "<<res<<endl;
        }
        while (j<2*n){
            res+=ss[y][j]; j++;
            //cout<<i<<" c "<<j<<" "<<res<<endl;
        }
        cout<<res<<"\n";
    }
}