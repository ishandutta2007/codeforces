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

int n, m;
ll p, q;
int arr[200100];
ll w[200100];

ll po(ll a, ll n) {
    if (!n) return 1;
    ll t = po(a,n/2);
    return t*t%MOD*(n%2?a:1)%MOD;
}
ll inv(ll a) {
    return po(a,MOD-2);
}

ll D[3010][3010];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=0;i<n;i++) scanf("%lld",&w[i]);
    for (i=0;i<n;i++) {
        if (!arr[i]) p+=w[i];
        else q+=w[i];
    }
    p%=MOD;
    q%=MOD;
    int s;
    ll ans = 0, tans = 0;
    for (s=0;s<=m;s++) {
        for (i=0;i<=s;i++) {
            j = s-i;
            if (p-j<0) continue;
            if (i==0&&j==0) {
                D[i][j] = 1;
            }
            if (s==m) {
                ans=(ans+D[i][j]*(p-j)%MOD)%MOD;
                tans=(tans+D[i][j]*(q+i)%MOD)%MOD;
                continue;
            }
            D[i][j+1]=(D[i][j+1]+D[i][j]*inv(p+q+i-j)%MOD*(p-j))%MOD;
            D[i+1][j]=(D[i+1][j]+D[i][j]*inv(p+q+i-j)%MOD*(q+i))%MOD;
        }
    }
    ans = ans*inv(p)%MOD;
    tans = tans*inv(q)%MOD;
    for (i=0;i<n;i++) {
        if (!arr[i]) printf("%lld\n",ans*w[i]%MOD);
        else printf("%lld\n",tans*w[i]%MOD);

    }

    return 0;
}