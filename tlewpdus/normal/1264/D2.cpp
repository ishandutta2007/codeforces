#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353  ;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll po(ll a, ll n) {
    if (!n) return 1;
    ll t = po(a,n/2);
    return t*t%MOD*(n%2?a:1)%MOD;
}

int n, m;
char str[1000100];
int sumr[1000100];
int sumq[1000100];
ll fac[1000100];
ll fnv[1000100];

ll comb(ll n, ll r) {
    return fac[n]*fnv[r]%MOD*fnv[n-r]%MOD;
}

int main() {
    int len;
    scanf("%s",str);
    fac[0] = fnv[0] = 1;
    for (int i=1;i<=1000010;i++) {
        fac[i]=fac[i-1]*i%MOD;
    }
    fnv[1000010] = po(fac[1000010],MOD-2);
    for (int i=1000009;i>0;i--) {
        fnv[i]=fnv[i+1]*(i+1)%MOD;
    }
    len = strlen(str);
    sumr[len] = sumq[len] = 0;
    for (int i=len-1;i>=0;i--) {
        sumr[i] = sumr[i+1]+(str[i]==')');
        sumq[i] = sumq[i+1]+(str[i]=='?');
    }
    int t = sumr[0];
    m = sumq[0];
    ll minv = po(m,MOD-2);
    ll ans = 0;
    for (int k=0;k<=sumq[0];k++) {
        ll c = sumq[t+k];
        ll b = sumr[t+k];
        ans += (b+k*minv%MOD*c%MOD)*comb(m,k)%MOD;
    }
    printf("%lld\n",(ans%MOD+MOD)%MOD);

	return 0;
}