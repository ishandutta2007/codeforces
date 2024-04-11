#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1200005;
const int mod = 998244353;
const int inv2 = (mod+1)/2;
ll fpow(ll a,ll b) {
    a%=mod;ll ret=1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll w[maxn];
void ntt(vector<ll> &a, int n, int f=0) {
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

void inv(vector<ll> &a, vector<ll>&b, int l) {
    if(l==1){b[0]=fpow(a[0],mod-2);return;}
    inv(a,b,(l+1)>>1);
    vector<ll> c=vector<ll>(a.begin(),a.begin()+l);
    int len=1; while(len<(l<<1))len<<=1;
    c.resize(len);b.resize(len);
    ntt(c,len);ntt(b,len);
    for(int i=0;i<len;++i) b[i]=(2-c[i]*b[i]%mod+mod)%mod*b[i]%mod;
    ntt(b,len,1);
    for(int i=l;i<len;++i) b[i]=0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nxt(k, -1), pre(k, -1), in(k, 0), bad(k, 0);
    for(int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        int lst = -1;
        for(int j = 0; j < p; ++j) {
            int x;
            cin >> x;
            --x;
            if(j > 0) {
                if(nxt[lst] != -1 && nxt[lst] != x) {
                    bad[nxt[lst]] = bad[x] = bad[lst] = 1;
                }
                if(pre[x] != -1 && pre[x] != lst) {
                    bad[pre[x]] = bad[lst] = bad[x] = 1;
                }
                nxt[lst] = x;
                pre[x] = lst;
                in[x] = 1;
            }
            lst = x;
        }
    }
    vector<int> vis(k, 0);
    vector<ll> a(m + 1);
    for(int i = 0; i < k; ++i) {
        if(vis[i] || in[i] || bad[i]) continue;
        int cur = i, len = 0, ok = 1;
        while(cur != -1 && !vis[cur]) {
            if(bad[cur]) ok = 0;
            vis[cur] = 1;
            len += 1;
            cur = nxt[cur];
        }
        if(len <= m && ok) a[len] += 1;
    }
    a[0] = -1;
    vector<ll> ans(m + 1);
    inv(a, ans, m + 1);
    cout << (mod - ans[m] % mod) % mod << '\n';
}