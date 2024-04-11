#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
void ntt(vector<ll> &a, int f=0) {
    int n=a.size();
    vector<ll> w(n);
    for(ll i=0,j=0;i<n;++i) {
        if(i>j) swap(a[i],a[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    w[0]=1;
    for(int l=2;l<=n;l<<=1) {
        ll g=fpow(3,(mod-1)/l);
        if(f) g=fpow(g,mod-2);
        for(int j=(l>>1);j>=0;j-=2) w[j]=w[j>>1];
        for(int j=1;j<(l>>1);j+=2) w[j]=w[j-1]*g%mod;
        int m=l/2;
        for(int j=0;j!=n;j+=l) {
            for(int i=0;i<m;++i) {
                ll tmp=w[i]*a[j+i+m]%mod;
                a[j+i+m]=(a[i+j]-tmp+mod)%mod,a[i+j]=(a[i+j]+tmp)%mod;
            }
        }
    }
    if(f) {
        ll inv=fpow(n,mod-2);
        for(int i=0;i<n;++i) a[i]=a[i]*inv%mod;
    }
}
void mul(vector<ll>&a,vector<ll>b) {
    if(max(a.size(),b.size())<128) {
        int sza=a.size(),szb=b.size(),len=sza+szb-1;
        vector<ll> ret(len);
        for(int i=0;i<sza;i++)
            for(int j=0;j<szb;j++)
                ret[i+j]+=a[i]*b[j]%mod;
        a.resize(len);
        for(int i=0;i<len;++i) a[i]=ret[i]%mod;
        return;
    }
    int m=a.size()+b.size(),len=1;
    for(;len<=m;len<<=1);
    a.resize(len);b.resize(len);
    ntt(a);ntt(b);
    for(int i=0;i<len;++i) a[i]=a[i]*b[i]%mod;
    ntt(a,-1);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    int m2 = m;
    vector<ll> a(n), sp(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        sp[x] = 1;
    }
    vector<ll> ans(n);
    for(int qwq = 0; qwq < 2; ++qwq) {
        vector<ll> suf(3 * n), pre(n);
        vector<ll> p2(n + 1, 1), inv2(n + 1, 1);
        for(int i = 1; i <= n; ++i) p2[i] = p2[i - 1] * 2 % mod;
        for(int i = 1; i <= n; ++i) inv2[i] = inv2[i - 1] * ((mod + 1) / 2) % mod;
        for(int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + sp[i];
        pre[0] = sp[0]; for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + sp[i];
        vector<ll> a1(n), a2(n), a3(2 * n, 1);
        for(int i = 0; i < n; ++i) {
            a1[i] = sp[i] * i * inv2[suf[i]] % mod;
            a2[i] = sp[i] * inv2[suf[i]] % mod;
            a3[i] = p2[suf[i + 1]];
        }
        vector<ll> dp(n);
        function<void(int,int)> solve = [&](int l, int r) {
            if(l == r) return;
            int m = (l + r) / 2;
            solve(l, m);
            vector<ll> a1(m - l + 1), a2(m - l + 1), a3(2 * r - 2 * l + 1, 1);
            for(int i = l; i <= m; ++i) {
                a1[i - l] = sp[i] * i * inv2[suf[i]] % mod;
                a2[i - l] = sp[i] * inv2[suf[i]] % mod;
            }
            for(int i = l; i - l < a3.size(); ++i) {
                a3[i - l] = qwq ? p2[suf[i]] : p2[suf[i + 1]];
            }
            mul(a1, a3);
            mul(a2, a3);
            for(int i = m + 1; i <= r; ++i) {
                dp[i] = (dp[i] + a2[2 * i - 2 * l] * i - a1[2 * i - 2 * l]) % mod;
            }
            solve(m + 1, r);
        };
        solve(0, n - 1);
        for(int i = 0; i < n; ++i) {
            if(dp[i] < 0) dp[i] += mod;
            dp[i] = dp[i] * p2[m] % mod;
        }
        reverse(sp.begin(), sp.end());
        if(qwq) reverse(dp.begin(), dp.end());
        for(int i = 0; i < n; ++i) {
            ans[i] = (ans[i] + dp[i]) % mod;
        }
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        res += ans[i] * a[i] % mod;
    }
    res %= mod;
    res = res * fpow(fpow(2, m) - 1, mod - 2) % mod;
    cout << res << '\n';
}