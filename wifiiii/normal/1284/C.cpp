#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 250005;
int n, mod;
ll f[maxn];
int main()
{
    cin>>n>>mod;
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    ll ans = 0;
    for(int k=1;k<=n;++k)
    {
        ll tmp = 1ll * (n-k+1) * (n-k+1) % mod;
        tmp = tmp * f[k] % mod * f[n-k] % mod;
        ans += tmp;
    }
    ans %= mod;
    cout << ans << endl;
}