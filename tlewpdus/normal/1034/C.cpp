#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
ll MOD = 1000000007;
ll sum[1000100];

ll gcd(ll a, ll b) {
    return a?gcd(b%a,a):b;
}

int par[1000100];
ll num[1000100];
ll ans[1000100];
int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&sum[i]);
    for (i=1;i<n;i++) {scanf("%d",&par[i]); --par[i];}
    for (i=n-1;i;i--) sum[par[i]]+=sum[i];
    for (i=0;i<n;i++) {
        ll g = gcd(sum[0],sum[i]);
        g = sum[0]/g;
        if (g<=n) num[g]++;
    }
    for (i=n;i;i--) {
        for (int j=2*i;j<=n;j+=i) num[j]+=num[i];
    }
    for (i=n;i;i--) {
        if (num[i]!=i) continue;
        ans[i]++;
        for (int j=2*i;j<=n;j+=i) ans[i] = (ans[i]+ans[j])%MOD;
    }
    printf("%lld\n",ans[1]);

    return 0;
}