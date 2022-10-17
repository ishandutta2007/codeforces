#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct cp {
    double x,y;
    cp(double a=0,double b=0){x=a,y=b;}
    inline cp operator + (cp &a) {return cp{x+a.x,y+a.y};}
    inline cp operator - (cp &a) {return cp{x-a.x,y-a.y};}
    inline cp operator * (cp &a) {return cp{x*a.x-y*a.y,x*a.y+y*a.x};}
    inline void operator /= (double a) {x/=a,y/=a;}
    inline void operator += (cp &a) {x+=a.x,y+=a.y;}
    inline cp conj() {return cp(x,-y);}
};
const double PI = acos(-1.0);
const int maxn = 800005;
void fft(vector<cp> &a, int n, int f=0) {
    vector<cp> w(n);
    for(int i=0,j=0;i<n;++i) {
        if(i>j) swap(a[i],a[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    w[0]=cp(1,0);
    for(int l=2;l<=n;l<<=1) {
        cp g=cp(cos(2*PI/l), sin(2*PI/l));
        if(f) g=g.conj();
        for(int j=(l>>1);j>=0;j-=2) w[j]=w[j>>1];
        for(int j=1;j<(l>>1);j+=2) w[j]=w[j-1]*g;
        int m=l/2;
        for(int j=0;j!=n;j+=l) {
            for(int i=0;i<m;++i) {
                cp tmp=w[i]*a[j+i+m];
                a[j+i+m]=a[i+j]-tmp,a[i+j]=a[i+j]+tmp;
            }
        }
    }
    if(f) for(int i=0;i<n;++i) a[i]/=n;
}
const int mod = 1e9 + 7;
void mul(vector<ll>&a,vector<ll>&b) {
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
    int m=a.size()+b.size(),len=1;for(;len<=m;len<<=1);
    vector<cp> A(a.begin(),a.end()),B(b.begin(),b.end());
    A.resize(len);B.resize(len);
    fft(A,len);fft(B,len);
    for(int i=0;i<len;++i) A[i]=A[i]*B[i];
    fft(A,len,-1);
    a.resize(len);
    for(int i=0;i<len;++i) a[i]=(ll)(A[i].x+0.5)%mod;
    while(len>0 && !a[len-1]) --len;
    a.resize(len);
}
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 1) {
        ll p = 1ll * n * m % mod;
        ll ans = p * (p + 1) / 2 % mod + (p - 2) * (p - 1) / 2 % mod;
        ans %= mod;
        cout << ans << '\n';
        return 0;
    }
    vector<int> a(n), pre(n + 1), suf(n + 1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) {
        pre[i + 1] = (pre[i] + a[i]) % k;
    }
    for(int i = n - 1; i >= 0; --i) {
        suf[i] = (suf[i + 1] + a[i]) % k;
    }
    int sum = pre[n];

    vector<ll> b(k), c(k);
    for(int i = 1; i <= n; ++i) {
        b[pre[i]] += 1;
    }
    for(int i = 0; i <= n - 1; ++i) {
        c[suf[i]] += 1;
    }
    mul(b, c);
    for(int i = k; i < b.size(); ++i) {
        (b[i % k] += b[i]) %= mod;
    }
    b.resize(k);
    auto solve1 = [&](int x) {
        vector<int> cnt(k);
        ll ret = 0;
        for(int i = 0; i <= n; ++i) {
            ret += cnt[(pre[i] - x + k) % k];
            cnt[pre[i]] += 1;
        }
        return ret % mod;
    };
    auto solve2 = [&](int x, int d) {
        x = (x - 1ll * (d - 1) * sum % k + k) % k;
        ll ret = b[x];
        return ret % mod;
    };
    ll ans = solve1(0) * m % mod;
    for(int i = 1; i <= m - 1; ++i) {
        ans += solve2(0, i) * (m - i) % mod;
    }
    ll r = 1ll * sum * m % k;
    ans += solve1(r) * m % mod;
    for(int i = 1; i <= m - 1; ++i) {
        ans += solve2(r, i) * (m - i) % mod;
    }
    vector<int> cnt1(k);
    for(int i = 1; i <= n; ++i) {
        cnt1[pre[i]] += 1;
    }
    ans -= cnt1[r];
    for(int i = 1; i < m; ++i) {
        ans -= cnt1[(r - 1ll * i * sum % k + k) % k];
    }
    vector<int> cnt2(k);
    for(int i = n - 1; i >= 0; --i) {
        cnt2[suf[i]] += 1;
    }
    ans -= cnt2[r];
    for(int i = 1; i < m; ++i) {
        ans -= cnt2[(r - 1ll * i * sum % k + k) % k];
    }
    ans += 1;
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << '\n';
}