//
// Created by yamunaku on 2019/10/26.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD 1000000007
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    if(n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    mti cyoko(n, vi(m, 0)), ctate(n, vi(m, 0));
    rep(i, n){
        per(j, m - 1){
            cyoko[i][j] = cyoko[i][j + 1] + (s[i][j + 1] == 'R' ? 1 : 0);
        }
    }
    rep(j, m){
        per(i, n - 1){
            ctate[i][j] = ctate[i + 1][j] + (s[i + 1][j] == 'R' ? 1 : 0);
        }
    }
    mtl dpyoko(n + 1, vl(m + 1, 0)), dptate(n + 1, vl(m + 1, 0));
    dpyoko[0][1]=1;
    dpyoko[0][m-cyoko[0][0]]=(dpyoko[0][m-cyoko[0][0]]-1+MOD)%MOD;
    dptate[1][0]=1;
    dptate[n-ctate[0][0]][0]=(dptate[n-ctate[0][0]][0]-1+MOD)%MOD;
    rep(i, n){
        rep(j, m){
            if(i > 0) dptate[i][j] = (dptate[i][j] + dptate[i - 1][j]) % MOD;
            if(j > 0) dpyoko[i][j] = (dpyoko[i][j] + dpyoko[i][j - 1]) % MOD;
            if(j < m - 1){
                dpyoko[i][j+1] = (dpyoko[i][j+1]+dptate[i][j])%MOD;
                if(m - cyoko[i][j] > j)
                    dpyoko[i][m - cyoko[i][j]] = (dpyoko[i][m - cyoko[i][j]] - dptate[i][j] + MOD) % MOD;
            }
            if(i < n - 1){
                dptate[i+1][j] = (dptate[i+1][j]+dpyoko[i][j])%MOD;
                if(n - ctate[i][j] > i)
                    dptate[n - ctate[i][j]][j] = (dptate[n - ctate[i][j]][j] - dpyoko[i][j] + MOD) % MOD;
            }
        }
    }
    cout << (dpyoko[n - 1][m - 1] + dptate[n - 1][m - 1]) % MOD << endl;
    return 0;
}