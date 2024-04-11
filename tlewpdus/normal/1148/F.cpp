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

int n;
ll val[300100], mask[300100];

int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld%lld",&val[i],&mask[i]);
    ll s = 0;
    for (i=0;i<n;i++) s+=val[i];
    if (s<0) for (i=0;i<n;i++) val[i]*=-1;
    ll ans = 0;
    for (j=61;j>=0;j--) {
        ll sum = 0;
        for (i=0;i<n;i++) {
            if ((mask[i]&-mask[i])==(1LL<<j)) sum += val[i];
        }
        if (sum>0) { // choose
            ans |= 1LL<<j;
            for (i=0;i<n;i++) {
                if (mask[i]>>j&1) val[i]*=-1;
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}