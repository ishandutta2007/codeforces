#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+6;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n, i, x, y, ans, ds[MN], sz[MN], d[MN];
pair<ll,ll> arr[MN];
vector<int> adj[MN];
ll fnd(ll x){return ds[x]=(ds[x]==x)?x:fnd(ds[x]);}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
        ds[i]=i; sz[i]=1;
    }
    for(i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sort(arr+1,arr+n+1,[](pll i,pll j){return i.first<j.first;});
    for(i=1;i<=n;i++){
        x = arr[i].second; d[x] = 1;
        ans += arr[i].first;
        for(auto v : adj[x]){
            if(!d[v]) continue;
            ans += arr[i].first*sz[x]*sz[fnd(v)];
            sz[x] += sz[fnd(v)]; ds[fnd(v)] = x;
        }
    }
    for(i=1;i<=n;i++)
        ds[i] = i, d[i] = 0, sz[i] = 1;
    for(i=n;i>=1;i--){
        x = arr[i].second; d[x] = 1;
        ans -= arr[i].first;
        for(auto v : adj[x]){
            if(!d[v]) continue;
            ans -= arr[i].first*sz[x]*sz[fnd(v)];
            sz[x] += sz[fnd(v)]; ds[fnd(v)] = x;
        }
    }
    printf("%lld\n",ans);
    return 0;
}