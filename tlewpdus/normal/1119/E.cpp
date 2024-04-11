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
ll arr[300100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&arr[i]);
    ll s = 0;
    ll res = 0;
    for (i=0;i<n;i++) {
        ll v = min(arr[i]/2,s);
        res += v;
        arr[i]-=2*v; s-=v;
        if (arr[i]>=3) {
            res += arr[i]/3;
            arr[i] -= arr[i]/3*3;
        }
        s += arr[i];
    }
    printf("%lld\n",res);

    return 0;
}