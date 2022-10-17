#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 400005;
const int mod = 998244353;
ll fpow(ll a,ll b) {
    a%=mod;ll ret=1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll w[maxn];
void ntt(vector<ll> &a, int f=0) {
    int n=a.size();
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
vector<ll> fpow(vector<ll> a,ll b) {
    vector<ll> ret{1};
    while(b){if(b&1) mul(ret,a);mul(a,a);b>>=1;}
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int m = 0;
    for(int i = 0; i < n; ++i) if(a[i] != a[(i + 1) % n]) ++m;
    vector<ll> b {1, k - 2, 1};
    b = fpow(b, m);
    ll ans = 0;
    for(int i = m + 1; i < b.size(); ++i) {
        ans += b[i];
    }
    ans %= mod;
    ans = ans * fpow(k, n - m) % mod;
    cout << ans << endl;
}