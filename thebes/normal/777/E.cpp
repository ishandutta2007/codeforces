#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
struct idk{ll a, b, h;}arr[MN];
ll n, i, bit[2*MN], ans;
ll qu(ll p){ll r=0;for(;p;p-=p&-p)r=max(r,bit[p]); return r;}
void upd(ll p,ll v){for(;p<=2*n;p+=p&-p)bit[p]=max(bit[p],v);}
map<ll,ll> mp;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld%lld%lld",&arr[i].b,&arr[i].a,&arr[i].h);
        mp[arr[i].a]=mp[arr[i].b]=0;
    }
    auto it=mp.begin(); i=0;
    for(;it!=mp.end();it++) it->second=++i;
    sort(arr+1,arr+n+1,[](idk i,idk j){return i.a==j.a?i.b>j.b:i.a>j.a;});
    for(i=1;i<=n;i++){
        ll mx = qu(mp[arr[i].a]-1)+arr[i].h;
        ans = max(ans, mx);
        upd(mp[arr[i].b],mx);
    }
    printf("%lld\n",ans);
    return 0;
}