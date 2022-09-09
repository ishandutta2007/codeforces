#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353 ;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int arr[510], loc[510];
int D[510][510];

ll calc(int s, int e) {
    if (s>e) return 1;
    if (~D[s][e]) return D[s][e];
    int mini = n+1, t = s;
    for (int i=s;i<=e;i++) {
        if (mini>arr[i]) {
            mini=arr[i];
            t=i;
        }
    }
    ll v = 0, w = 0;
    for (int i=t;i<=e;i++) {
        v += calc(t+1,i)*calc(i+1,e)%MOD;
    }
    for (int i=t;i>=s;i--) {
        w += calc(i,t-1)*calc(s,i-1)%MOD;
    }
    D[s][e] = v%MOD*(w%MOD)%MOD;
    return D[s][e];
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
        loc[arr[i]] = i;
    }
    memset(D,-1,sizeof(D));
    printf("%lld\n",calc(1,n));

    return 0;
}