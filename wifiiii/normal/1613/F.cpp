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
        while(len>0 && !a[len-1]) --len;
        a.resize(len);
        return;
    }
    int m=a.size()+b.size(),len=1;
    for(;len<=m;len<<=1);
    a.resize(len);b.resize(len);
    ntt(a);ntt(b);
    for(int i=0;i<len;++i) a[i]=a[i]*b[i]%mod;
    ntt(a,-1);
    while(len>0 && !a[len-1]) --len;
    a.resize(len);
}
typedef pair<int,int> pii;
vector<ll> mul(vector<vector<ll>> a) {
    if(a.empty()) return {1};
    priority_queue<pii,vector<pii>,greater<>> q;
    for(int i=0;i<a.size();++i) {
        q.push({a[i].size(), i});
    }
    while(q.size()>1) {
        auto [s1,i1]=q.top();q.pop();
        auto [s2,i2]=q.top();q.pop();
        mul(a[i1],a[i2]);
        q.push({a[i1].size(),i1});
    }
    return a[q.top().second];
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> f(n + 1); f[0] = 1;
    for(int i = 1; i <= n; ++i) f[i] = f[i-1] * i % mod;
    vector<vector<ll>> a;
    for(int i = 0; i < n; ++i) {
        a.push_back({ll(g[i].size() - (i != 0)), 1});
    }
    auto dp = mul(a);
    ll ans = 0;
    for(int i = 0; i < dp.size(); ++i) {
        ans += ((n - i) % 2 == 1 ? -1 : 1) * dp[i] * f[i] % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << '\n';
}