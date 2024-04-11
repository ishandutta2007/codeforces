#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll fact[300001];
ll choose[300001];
ll inv(ll b, ll p){
    if(p==0) return 1;
    ll x = inv(b,p/2);
    if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
    else return ((x*x)%mod+mod)%mod;
}
map<int,vector<int>> m;
int main(){
    int n; scanf("%d",&n);
    int k; scanf("%d",&k);
    fact[0] = 1;
    for(int i=1;i<=n;i++) {
        fact[i] = fact[i-1]*1LL*i;
        fact[i]%=mod;
    }
    for(int i=k-1;i<=n;i++){
        ll x = fact[i];
        ll y = fact[i-(k-1)];
        ll z = fact[k-1];
        choose[i] = (x*1LL*inv(y,mod-2)%mod*1LL*inv(z,mod-2)%mod)%mod;
    }
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        m[l].push_back(r);
    }
    multiset<int> currIn;
    ll ans = 0;
    for(auto &it : m){
        auto endR = currIn.begin();
        while(endR!=currIn.end()){
            if(*endR<it.first)
                currIn.erase(endR++);
            else{
                break;
            }
        }
        for(int r : it.second){
            currIn.insert(r);
            if(currIn.size()>=k){
                ans+=choose[currIn.size()-1];
                ans%=mod;
            }
        }
    }
    cout << ans << endl;

}