#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> in[500001];
map<vector<int>,ll> x;
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll val[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&val[i]);
        in[i].clear();
    }
    x.clear();
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        --u; --v;
        in[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(in[i].size()==0) continue;
        sort(in[i].begin(),in[i].end());
        x[in[i]]+=val[i];
    }
    ll ans = 0;
    for(auto &it : x){
        ans = __gcd(ans,it.second);
    }
    printf("%lld\n",ans);
}
int main(){
    int t; scanf("%d",&t);
    while(t--) solve();
}