#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[200005];
int n;
unordered_map<ll,ll> vis;
ll calc(ll x)
{
    if(vis.count(x)) return vis[x];
    ll ret = 0;
    for(int i=1;i<=n;++i)
    {
        ll tmp = a[i] % x;
        if(a[i] < x) ret += x - tmp;
        else ret += min(tmp, x - tmp);
        if(ret > n) break;
    }
    return vis[x] = ret;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ii cin >> a[i];
    ll ans = 0;
    ii if(a[i]&1) ++ans;
    srand(time(0));
    for(int i=1;i<=20;++i)
    {
        int p = mrand() % n + 1;
        for(ll j=max(2ll,a[p]-50);j<=a[p]+50;++j)
        {
            ll tmp = j;
            for(ll k=2;k*k<=tmp;++k)
            {
                if(tmp % k == 0)
                {
                    while(tmp % k == 0) tmp /= k;
                    ans = min(ans, calc(k));
                }
            }
            if(tmp > 1) ans = min(ans, calc(tmp));
        }
    }
    cout << ans << endl;
}