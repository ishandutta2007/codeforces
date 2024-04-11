#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll solve(ll f, ll cnts, ll cntw, ll s, ll w){
    if (w<s) swap(s,w), swap(cnts,cntw);
    ll ans=min(cnts,(f/s));
    f-=min(cnts,(f/s))*s;
    ans+=min(cntw,(f/w));
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll p,f,cnts,cntw,s,w,ans=0;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        for (int i=0;i<=cnts;++i){
            if (i*s>p) continue;
            ll curr=i+min(cntw,(p-i*s)/w)+solve(f,cnts-i,cntw-min(cntw,(p-i*s)/w),s,w);
            ans=max(ans,curr);
        }
        cout << ans << '\n';
    }
}