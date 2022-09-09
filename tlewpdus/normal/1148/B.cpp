#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll n, m, ta, tb, k;
ll a[200100], b[200100];

int main() {
    int i, j;

    scanf("%lld%lld%lld%lld%lld",&n,&m,&ta,&tb,&k);
    for (i=0;i<n;i++) scanf("%lld",&a[i]);
    for (i=0;i<m;i++) scanf("%lld",&b[i]);
    if (k>=min(n,m)) {
        puts("-1");
        return 0;
    }
    ll ans = -1;
    for (i=0;i<=k;i++) {
        int tt = (lower_bound(b,b+m,a[i]+ta)-b);
        if (tt+k-i>=m) {
            puts("-1");
            return 0;
        }
        ans = max(ans,b[tt+k-i]+tb);
    }
    printf("%lld\n",ans);

    return 0;
}