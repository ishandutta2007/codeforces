#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const int mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int n;ll x,y;cin>>n>>x>>y;
    x-=y;
    vector<pii>arr(n);
    for(auto &i:arr)cin>>i.fi>>i.se;
    sort(arr.begin(),arr.end());
    ll ans=0;
    multiset<int>s;
    for(auto i:arr){
        (ans+=y*(i.se-i.fi+1))%=mod;
        auto p=s.lower_bound(i.fi);
        if(p!=s.begin()){
            p--;
            (ans+=min((i.fi-*p-1)*y,x))%=mod;
            s.erase(p);
        }
        else{
            (ans+=x)%=mod;
        }
        s.insert(i.se);
    }
    cout<<ans;
    return 0;
}