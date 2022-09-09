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

ll D[1010][1010];
int pre[1010];
int arr[1010];
ll ans;
int n, k, M = 100010;

ll calc(int t) {
    int i, j;
    for (i=1;i<=n;i++) {
        while(arr[i]-arr[pre[i]]<t) pre[i]--;
    }
    for (j=1;j<=k;j++) {
        for (i=1;i<=n;i++) {
            if (j==1) {
                D[j][i] = D[j][i-1]+1;
            }
            else {
                D[j][i] = (D[j-1][pre[i]]+D[j][i-1])%MOD;
            }
        }
    }
    return D[k][n];
}

int main() {
    int i, j;

    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++) scanf("%d",&arr[i]);
    arr[0] = -M-10;
    sort(arr+1,arr+n+1);
    iota(pre+1,pre+n+1,1);
    ll pree = 0;
    for (i=0;i*(k-1)<=M;i++) {
        ll tmp = calc(i);
        if (!i) {
            pree = tmp;
            continue;
        }
        ans += (i-1)*(pree-tmp)%MOD;
        pree = tmp;
    }
    ans += (i-1)*pree%MOD;
    printf("%lld\n",(ans%MOD+MOD)%MOD);

    return 0;
}