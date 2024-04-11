#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 2e5+5;
ll n, i, x, y, a, b, dp[MN][2];
vi adj[MN];

void solve(ll n,ll p){
    vi vec; int k = 0;
    dp[n][0] = 1;
    for(auto v : adj[n]){
        if(v==p) continue;
        solve(v, n);
        k += dp[v][0];
        vec.push_back(dp[v][0]-dp[v][1]);
    }
    sort(vec.begin(),vec.end(),[](int i,int j){return i>j;});
    dp[n][0] += k; dp[n][1] += k;
    if(vec.size()>0&&vec[0]>=0){
        dp[n][0] -= vec[0];
        dp[n][1] -= vec[0];
    }
    if(vec.size()>1&&vec[1]>=0)
        dp[n][0] -= vec[1];
}

int main(){
    for(scanf("%lld%lld%lld",&n,&a,&b),i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(a<b){
        solve(1, 0);
        printf("%lld\n",(dp[1][0]-1)*b+(n-dp[1][0])*a);
    }
    else{
        int f=0;
        for(i=1;i<=n;i++) if(adj[i].size()==n-1) f=1;
        if(f) printf("%lld\n",a+(n-2)*b);
        else printf("%lld\n",(n-1)*b);
    }
    return 0;
}