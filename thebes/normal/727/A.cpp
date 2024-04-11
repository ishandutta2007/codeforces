#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b; map<ll,ll> vis;
bool wtf(ll n){
    if(n>10000000000LL) return 0;
    if(n==b) return 1;
    if(vis.count(n)) return 0;
    vis[n] = 0;
    if(wtf(2*n)){
        vis[n] = 2*n;
        return 1;
    }
    if(wtf(10*n+1)){
        vis[n] = 10*n+1;
        return 1;
    }
    return 0;
}
vector<ll> ans;
int main(){
    scanf("%lld%lld",&a,&b);
    if(!wtf(a)) printf("NO\n");
    else{
        printf("YES\n");
        ans.push_back(a);
        while(a != b){
            a = vis[a];
            ans.push_back(a);
        }
        printf("%d\n",ans.size());
        for(auto v : ans) printf("%lld ",v);
    }
    return 0;
}