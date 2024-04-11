#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define sz(x) ((ll)x.size())
#define pb push_back
const ll mod=998244353;
ll fpow(ll a,ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
namespace linear_seq
{
    const ll maxn = 10010;
    ll res[maxn],base[maxn],c[maxn],md[maxn];
    vector<long long> v;
    void mul(ll *a,ll *b,ll k)
    {
        for(int i=0;i<k+k;++i) c[i]=0;
        for(int i=0;i<k;++i)
            if(a[i]) for(int j=0;j<k;++j)
                c[i+j]=(c[i+j]+a[i]*b[j])%mod;
        for (ll i=k+k-1;i>=k;i--)
            if(c[i]) for(int j=0;j<v.size();++j)
                c[i-k+v[j]]=(c[i-k+v[j]]-c[i]*md[v[j]])%mod;
        for(int i=0;i<k;++i) a[i]=c[i];
    }
    ll solve(ll n,vector<ll> a,vector<ll> b)
    {
        ll ans=0,cnt=0,k=a.size();
        for(int i=0;i<k;++i) md[k-1-i]=-a[i];md[k]=1;
        v.clear();
        for(int i=0;i<k;++i) if(md[i]!=0) v.push_back(i);
        for(int i=0;i<k;++i) res[i]=base[i]=0;
        res[0]=1;
        while ((1ll<<cnt)<=n) cnt++;
        for (ll p=cnt;p>=0;p--)
        {
            mul(res,res,k);
            if((n>>p)&1)
            {
                for(ll i=k-1;i>=0;--i) res[i+1]=res[i]; res[0]=0;
                for(int j=0;j<v.size();++j) res[v[j]]=(res[v[j]]-res[k]*md[v[j]])%mod;
            }
        }
        for(int i=0;i<k;++i) ans=(ans+res[i]*b[i])%mod;
        if(ans<0) ans+=mod;
        return ans;
    }
    vector<ll> bm(vector<ll> s)
    {
        vector<ll> C(1,1),B(1,1);
        ll k=0,m=1,b=1;
        for(int n=0;n<s.size();++n)
        {
            ll d=0;
            for(int i=0;i<=k;++i) d=(d+(ll)C[i]*s[n-i])%mod;
            if(!d) ++m;
            else if(k+k<=n)
            {
                vector<ll> T=C;
                ll c=mod-d*fpow(b,mod-2)%mod;
                while(sz(C)<sz(B)+m) C.pb(0);
                for(int i=0;i<B.size();++i) C[i+m]=(C[i+m]+c*B[i])%mod;
                k=n+1-k; B=T; b=d; m=1;
            }
            else
            {
                ll c=mod-d*fpow(b,mod-2)%mod;
                while(sz(C)<sz(B)+m) C.pb(0);
                for(int i=0;i<B.size();++i) C[i+m]=(C[i+m]+c*B[i])%mod;
                ++m;
            }
        }
        return C;
    }
    ll gao(vector<ll> a,ll n)
    {
        vector<ll> c=bm(a);
        c.erase(c.begin());
        for(int i=0;i<c.size();++i) c[i]=(mod-c[i])%mod;
        return solve(n,c,vector<ll>(a.begin(),a.begin()+sz(c)));
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<vector<ll>>> res(12, vector<vector<ll>>(12));
    int n = 66;
    vector<vector<vector<ll>>> dp(1 << 11, vector<vector<ll>>(12, vector<ll>(12)));
    dp[0][0][0] = 1;
    vector<ll> a;
    for(int i = 0; i < n; ++i) {
        vector<vector<vector<ll>>> ndp(1 << 11, vector<vector<ll>>(12, vector<ll>(12)));
        for(int j = 0; j < 1 << 11; ++j) {
            for(int p = 0; p <= 11; ++p) {
                for(int q = 0; q <= 11; ++q) {
                    if(dp[j][p][q] == 0) continue;
                    for(int r = 0; r <= 11 && r <= i; ++r) {
                        int np = p + r;
                        int nq = q + (r != 0);
                        if(r > 0 && j >> (r - 1) & 1) --nq;
                        int nj = (j & ((1 << (11 - 1)) - 1) & ~((1 << r) - 1)) << 1;
                        if(r > 0) {
                            nj |= 1 << (r - 1);
                            nj |= j & ((1 << (r - 1)) - 1);
                        }
                        if(np <= 11 && nq <= 11) {
                            ndp[nj][np][nq] = (ndp[nj][np][nq] + dp[j][p][q]) % mod;
                        }
                    }
                }
            }
        }
        for(int k = 1; k <= 11; ++k) {
            for(int x = 1; x <= 11; ++x) {
                ll ans = 0;
                for(int j = 0; j < 1 << 11; ++j) {
                    ans += dp[j][k][x];
                }
                ans %= mod;
                res[k][x].push_back(ans);
            }
        }
        dp = ndp;
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        cout << linear_seq::gao(res[k][x], n) << '\n';
    }
}