#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll mod = 1e9+7;
ll n, m, sq, i, l, r, x, s, ans, hm;

int main(){
    scanf("%lld%lld",&n,&m);
    sq = sqrt((long double)n);
    hm = n/(sq+1)+1;
    for(i=1;i<hm&&i<=m;i++) ans=(ans+(n%i))%mod;
    for(i=sq;i>=1;i--){
        r=n/i, l=n/(i+1)+1;
        if(l>m) continue;
        r=min(r,m);
        x=(r-l+1)%mod;
        s=(n%l)%mod;
        ll wth = (x*(x-1)/2)%mod;
        ans=(ans+s*x-i*wth)%mod;
        if(ans<0) ans += mod;
    }
    if(m>n) ans=(ans+(n%mod)*((m-n)%mod))%mod;
    printf("%lld\n",ans);
    return 0;
}