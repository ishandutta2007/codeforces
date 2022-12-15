#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

const int MN = 1e6+6, mod = 1e9+7;
ll n, i, x, y, cur, ans, h[MN];

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&h[i]), h[i]--;
    for(i=1;i<=n;i++){
        ans = (ans+h[i])%mod;
        ans = (ans+cur*min(h[i],h[i-1]))%mod;
        cur = (cur*min(h[i],min(h[i-1],h[i+1]))+min(h[i],h[i+1]))%mod;
    }
    printf("%lld\n",ans);
    return 0;
}