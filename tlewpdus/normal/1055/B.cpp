#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n, m;
ll l;
ll arr[100100];
ll ans;

int main() {
    int i;

    scanf("%d%d%lld",&n,&m,&l);
    for (i=1;i<=n;i++) scanf("%lld",&arr[i]);
    arr[0] = arr[n+1] = 0;
    for (i=0;i+1<n+2;i++) {
        if (arr[i]>l&&arr[i+1]<=l) ans++;
    }
    for (i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        if (!a) {
            printf("%lld\n",ans);
            continue;
        }
        ll p, d;
        scanf("%lld%lld",&p,&d);
        if (arr[p-1]>l&&arr[p]<=l) ans--;
        if (arr[p]>l&&arr[p+1]<=l) ans--;
        arr[p]+=d;
        if (arr[p-1]>l&&arr[p]<=l) ans++;
        if (arr[p]>l&&arr[p+1]<=l) ans++;
    }

    return 0;
}