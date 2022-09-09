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

int w, h;

ll po(ll a, ll n) {
    if (!n) return 1;
    ll t= po(a,n/2);
    return t*t%MOD*(n%2?a:1)%MOD;
}

int main() {
    scanf("%d%d",&w,&h);
    printf("%lld\n",po(2,w+h));

    return 0;
}