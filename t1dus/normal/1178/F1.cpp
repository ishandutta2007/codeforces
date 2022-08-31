#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pb push_back

const int MOD = 998244353;

int n,m,dp[1005][1005];
int a[1000005];
vi v;
int k;
vi gg[1005];
int bruh[1005][1005];

int solve(int l,int r){
    if(l == r+1) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    // cout << l << " " << r << "\n";
    int mn = bruh[l][r];
    if(gg[mn][0] < l or gg[mn].back() > r) return dp[l][r] = 0;
    int cur1 = 0,cur2 = 0;
    int cur = 1;
    FOR(i,l,gg[mn][0]+1){
        cur1 = (cur1+solve(l,i-1)*solve(i,gg[mn][0]-1))%MOD;
    }
    FOR(i,gg[mn].back(),r+1){
        cur2 = (cur2+solve(gg[mn].back()+1,i)*solve(i+1,r))%MOD;
    }
    FOR(i,1,(int)gg[mn].size()){
        cur = (cur*solve(gg[mn][i-1]+1,gg[mn][i]-1))%MOD;
    }
    cur = (cur*cur1)%MOD;
    cur = (cur*cur2)%MOD;
    return dp[l][r] = cur;
}

signed main(){
    cin >> n >> m;
    FOR(i,1,m+1){
        cin >> a[i];
    }
    v.pb(0);
    FOR(i,1,m+1){
        if(i == 1 or a[i] != a[i-1]) v.pb(a[i]);
    }
    k = (int)v.size()-1;
    if(k > 2*n+1){
        cout << "-1\n";
        return 0;
    }
    FOR(i,1,k+1){
        gg[v[i]].pb(i);
        int mn = n+1;
        FOR(j,i,k+1){
            mn = min(mn,v[j]);
            bruh[i][j] = mn;
            dp[i][j] = -1;
        }
    }
    cout << solve(1,k) << "\n";
}