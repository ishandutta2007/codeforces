#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int maxn = 410005;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T sum(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
    int kth(T x) {
        int lg = 31 - __builtin_clz(n), pos = 0;
        for(int i = lg; i >= 0; --i) {
            if(pos + (1 << i) <= n && a[pos + (1 << i) - 1] < x) {
                pos += 1 << i;
                x -= a[pos - 1];
            }
        }
        return pos;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(maxn - 1);
    int t;
    cin >> t;
    fenwick<int> b(maxn);
    for(int i = 0; i < maxn; ++i) b.add(i, 1);
    vector<int> vis(maxn);
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> a(m);
        for(auto &[x, y] : a) cin >> x >> y, --x, --y;
        int cnt = 0;
        vector<int> mem, mem2;
        for(int i = m - 1; i >= 0; --i) {
            int pos = b.kth(a[i].second + 1);
            if(!vis[pos]) ++cnt;
            if(a[i].second) {
                int tmp = b.kth(a[i].second);
                vis[tmp] = 1;
                mem2.push_back(tmp);
            }
            b.add(pos, -1);
            mem.push_back(pos);
        }
        //for(int i = m - 1; i >= 0; --i) {
        //    int pos = b.kth(a[i].second + 1);
        //    if(b.kth(a[i].second + 2) == pos + 1) ++cnt;
        //    b.add(pos, -1);
        //    mem.push_back(pos);
        //}
        for(int i : mem2) vis[i] = 0;
        for(int i : mem) b.add(i, 1);
        cout << comb(n + n - cnt - 1, n) << '\n';
    }
}