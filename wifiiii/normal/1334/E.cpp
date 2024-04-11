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

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
const int maxn = 1005;
const int mod = 998244353;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init()
{
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    rf[maxn-1] = fpow(f[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
map<ll,ll> mp;
ll comb(ll n,ll k){if(n<k)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    ll n;
    cin>>n;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll g=gcd(a,b);
        ll tmp=a/g;
        if(!mp[tmp])
        {
            vector<int> v;
            for(ll i=2;i*i<=tmp;++i) {
                if(tmp % i == 0) {
                    int cnt = 0;
                    while(tmp % i == 0) tmp /= i, ++cnt;
                    v.push_back(cnt);
                }
            }
            if(tmp > 1) v.push_back(1);
            int s = 0;
            for(int i : v) s += i;
            ll res = 1;
            for(int i : v) res = res * comb(s, i) % mod, s -= i;
            mp[a/g] = res;
        }
        tmp = b/g;
        if(!mp[tmp])
        {
            vector<int> v;
            for(ll i=2;i*i<=tmp;++i) {
                if(tmp % i == 0) {
                    int cnt = 0;
                    while(tmp % i == 0) tmp /= i, ++cnt;
                    v.push_back(cnt);
                }
            }
            if(tmp > 1) v.push_back(1);
            int s = 0;
            for(int i : v) s += i;
            ll res = 1;
            for(int i : v) res = res * comb(s, i) % mod, s -= i;
            mp[b/g] = res;
        }
        cout << mp[a/g] * mp[b/g] % mod << endl;
    }
}