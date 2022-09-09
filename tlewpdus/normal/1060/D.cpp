#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
vector<ll> l, r;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        ll a, b;
        scanf("%lld%lld",&a,&b);
        l.push_back(a);
        r.push_back(b);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    ll ans = 0;
    for (i=0;i<n;i++) {
        ans += max(l[i],r[i]);
    }
    printf("%lld\n",ans+n);

    return 0;
}