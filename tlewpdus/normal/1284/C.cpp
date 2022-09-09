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
ll m;
ll fac[300100];

int main() {
    scanf("%d%lld",&n,&m);
    fac[0] = 1;
    for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%m;
    ll ans = 0;
    for (int l=1;l<=n;l++) {
        ans = (ans+1LL*(n-l+1)*(n-l+1)%m*fac[l]%m*fac[n-l]%m)%m;
    }
    printf("%lld\n",ans%m);

	return 0;
}