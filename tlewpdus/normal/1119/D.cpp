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
ll s[100100];
ll sum[100100];
ll val[100100];
int q;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&s[i]);
    sort(s,s+n);
    for (i=0;i+1<n;i++) val[i]=s[i+1]-s[i];
    sort(val,val+n);
    for (i=1;i<n;i++) sum[i]=val[i]+sum[i-1];
    scanf("%d",&q);
    for (i=0;i<q;i++) {
        ll a, b;
        scanf("%lld%lld",&a,&b); b-=a-1;
        int t = lower_bound(val,val+n,b)-val-1;
        printf("%lld\n",sum[t]+(n-t)*b);
    }

    return 0;
}