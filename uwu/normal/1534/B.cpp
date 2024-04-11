#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e5+5;

ll a[MAXN], tmp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=0;i<=n+10;++i) a[i]=0;
        for (int i=1;i<=n;++i) cin >> a[i];
        iota(tmp+1,tmp+1+n,1);
        sort(tmp+1,tmp+1+n,[](ll x, ll y){ return a[x]>a[y]; });
        ll ans=0;
        for (int i=1;i<=n;++i){
            int j=tmp[i];
            int curr=min(a[j],max(a[j-1],a[j+1]));
            ans+=a[j]-curr;
            a[j]=curr;
        }
        for (int i=1;i<=n+1;++i) ans+=abs(a[i]-a[i-1]);
        cout << ans << '\n';
    }
}