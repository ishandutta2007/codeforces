#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
ll arr[2010], brr[2010], x;

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for (i=1;i<=m;i++) scanf("%lld",&brr[i]);
    scanf("%lld",&x);
    for (i=1;i<=n;i++) arr[i]+=arr[i-1];
    for (i=1;i<=m;i++) brr[i]+=brr[i-1];
    vector<pll> vec;
    for (i=1;i<=n;i++) {
        for (j=i;j<=n;j++) {
            vec.push_back(pll(arr[j]-arr[i-1],j-i+1));
        }
    }
    sort(vec.begin(),vec.end());
    for (i=1;i<vec.size();i++) {
        vec[i].second = max(vec[i].second,vec[i-1].second);
    }
    ll ans = 0;
    for (i=1;i<=m;i++) {
        for (j=i;j<=m;j++) {
            ll v = brr[j]-brr[i-1];
            int t = upper_bound(vec.begin(),vec.end(),pll(x/v,10000))-vec.begin()-1;
            if (t<0) continue;
            ans = max(ans,vec[t].second*(j-i+1));
        }
    }
    printf("%lld\n",ans);

    return 0;
}