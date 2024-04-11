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

ll n, p, k;
ll arr[300100];
ll trr[300100];

int main() {
    int i;

    scanf("%lld%lld%lld",&n,&p,&k);
    for (i=0;i<n;i++) scanf("%lld",&arr[i]);
    for (i=0;i<n;i++) {
        trr[i] = (arr[i]*arr[i]%p*arr[i]%p*arr[i]%p-k*arr[i]%p+2*p)%p;
    }
    sort(trr,trr+n);
    ll p = 0, ans = 0;
    for (i=0;i<n;i++) {
        if (i==n-1||trr[i]!=trr[i+1]) {
            ans += (i-p)*(i-p+1)/2;
            p = i+1;
        }
    }
    printf("%lld\n",ans);

    return 0;
}