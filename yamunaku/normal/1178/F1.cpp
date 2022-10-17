//
// Created by yamunaku on 2019/07/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    CFS;
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    rep(i,n){
        dp[i][i+1]=1;
        dp[i][i]=1;
    }
    dp[n][n]=1;
    repl(w,2,n+1){
        rep(i,n-w+1){
            int l=i,r=i+w;
            int mi=IINF;
            int idx=-1;
            repl(k,l,r){
                if(mi>a[k]){
                    mi=a[k];
                    idx=k;
                }
            }
            ll suml=0,sumr=0;
            repl(x,l,idx+1){
                suml=(suml+dp[l][x]*dp[x][idx]%MOD9)%MOD9;
            }
            repl(x,idx+1,r+1){
                sumr=(sumr+dp[idx+1][x]*dp[x][r]%MOD9)%MOD9;
            }
//            cout << l SP r SP idx SP suml SP sumr << endl;
            dp[l][r]=suml*sumr%MOD9;
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}