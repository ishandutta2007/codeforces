#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 5e5+5, mod=1e9+7;
ll val[MN], N, M, K, i, x, y, ans, pw[MN]={1}, ds[MN];
map<ll,vector<ll>> id;
pair<ll,ll> e[MN];
bitset<MN> d, c;

ll fnd(ll x){return ds[x]=(ds[x]==x)?x:fnd(ds[x]);}

int main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    for(i=1;i<=N;i++) pw[i]=(pw[i-1]*2)%mod;
    for(i=1;i<=N;i++){
        scanf("%lld",&val[i]);
    }
    for(i=1;i<=M;i++){
        scanf("%lld%lld",&x,&y);
        e[i] = {x, y};
        id[val[x]^val[y]].push_back(i);
    }
    for(auto v : id){
        int non = N;
        for(auto wtf : v.second){
            tie(x, y) = e[wtf];
            ds[x] = x, ds[y] = y;
            if(!c[x]) c[x]=1, non--;
            if(!c[y]) c[y]=1, non--;
        }
        for(auto wtf : v.second){
            tie(x, y) = e[wtf];
            ds[fnd(x)] = fnd(y);
        }
        int cnt = 0;
        for(auto wtf : v.second){
            tie(x, y) = e[wtf];
            if(!d[fnd(x)]) d[fnd(x)]=1, cnt++;
        }
        ans = (1LL*ans+pw[non+cnt])%mod;
        for(auto wtf : v.second){
            tie(x, y) = e[wtf];
            c[x] = c[y] = 0;
            d[fnd(x)] = 0;
        }
    }
    ll rem = ((1LL<<K)-id.size())%mod;
    ans = (1LL*ans+1LL*pw[N]*rem)%mod;
    printf("%lld\n",ans);
    return 0;
}