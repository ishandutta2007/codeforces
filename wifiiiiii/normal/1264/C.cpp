
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 998244353;
const int maxn = 200005;
int mark[maxn];
ll a[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll pre[maxn],sumpre[maxn],invpre[maxn];
const int inv100 = 828542813;
set<int> s;
inline ll get(int l,int r) {return ((sumpre[r-1] - sumpre[l-1] + mod) % mod * fpow(pre[l-1],mod-2) + 1) % mod;}
inline ll get2(int l,int r) {return invpre[r] * fpow(invpre[l-1], mod-2) % mod;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    ii cin>>a[i],a[i]=a[i]*inv100%mod;
    pre[0] = invpre[0] = sumpre[0] = 1;
    ii pre[i]=pre[i-1]*a[i]%mod, sumpre[i] = (sumpre[i-1] + pre[i]) % mod, invpre[i] = fpow(pre[i], mod-2);
    mark[1] = 1;
    s.insert(1);
    s.insert(n+1);
    ll ans = get(1,n) * invpre[n] % mod;
    while(q--)
    {
        int x;
        cin>>x;
        if(mark[x])
        {
            s.erase(x);
            auto p = s.lower_bound(x);
            int rr = (*p)-1;
            --p;
            int ll = *p;
            ans += get(ll, rr) * get2(ll ,rr) % mod;
            ans -= get(ll, x-1) * get2(ll, x-1) % mod;
            ans -= get(x, rr) * get2(x, rr) % mod;
            ans %= mod;
            if(ans < 0) ans += mod;
        }
        else
        {
            auto p = s.lower_bound(x);
            int rr = (*p) - 1;
            --p;
            int ll = *p;
            ans -= get(ll, rr) * get2(ll ,rr) % mod;
            ans += get(ll, x-1) * get2(ll, x-1) % mod;
            ans += get(x, rr) * get2(x, rr) % mod;
            ans %= mod;
            if(ans < 0) ans += mod;
            s.insert(x);
        }
        cout << ans << endl;
        mark[x] ^= 1;
    }
}