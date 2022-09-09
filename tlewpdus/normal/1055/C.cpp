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

ll la, ra, ta, lb, rb, tb, g;

ll gcd(ll a, ll b) {
    return a?gcd(b%a,a):b;
}

ll llb(ll x, ll g) {
    if (x>=0) return x/g*g;
    return x/g*g-g;
}

int main() {
    scanf("%lld%lld%lld%lld%lld%lld",&la,&ra,&ta,&lb,&rb,&tb);
    g = gcd(ta,tb);
    if (ra-la>rb-lb) {
        swap(la,lb);
        swap(ra,rb);
        swap(ta,tb);
    }
    ll x;
    if (lb%g==la%g) x = lb;
    else x = llb(lb-la,g)+g+la;
    ll ans = 0;
    ans = max(ans,min(rb-x+1,ra-la+1));
    x = llb(rb-ra,g)+ra;
    ans = max(ans,min(x-lb+1,ra-la+1));
    printf("%lld\n",ans);

    return 0;
}