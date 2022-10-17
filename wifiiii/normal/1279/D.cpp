
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

inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int cnt[1000005];
const int mod = 998244353;
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll prob[1000005], inv[1000005];
int main()
{
    inv[1]=1;
    for(int i=2;i<=1000000;++i) inv[i]=(mod-(mod/i))*inv[mod%i]%mod;
    int n = read();
    int sum = 0;
    for(int i=1;i<=n;++i)
    {
        int k = read();
        for(int j=1;j<=k;++j)
        {
            int tmp = read();
            prob[tmp] += inv[k] * inv[n] % mod;
            cnt[tmp]++;
            if(prob[tmp] >= mod) prob[tmp] -= mod;
        }
        sum += k;
    }
    ll ans = 0;
    for(int i=1;i<=1000000;++i) ans += prob[i] * cnt[i] % mod * inv[n] % mod;
    ans %= mod;
    cout << ans << endl;
}