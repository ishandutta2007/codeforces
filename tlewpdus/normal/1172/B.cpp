#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll fac[200100];
int deg[200100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        deg[a]++;deg[b]++;
    }
    fac[0] = 1;
    for (i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    ll gob = 1;
    for (i=1;i<=n;i++) {
        gob = gob*fac[deg[i]]%MOD;
    }
    printf("%lld\n",gob*n%MOD);

    return 0;
}