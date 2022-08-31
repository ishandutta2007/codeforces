#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 998244353;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
//class stree {
//public:
//    vll t;
//    void build (const vll & a, int v, int tl, int tr) {
//        if(v==1) {
//            t.resize(a.size() * 4);
//        }
//        if (tl == tr)
//            t[v] = a[tl];
//        else {
//            int tm = (tl + tr) / 2;
//            build (a, v*2, tl, tm);
//            build (a, v*2+1, tm+1, tr);
//            t[v] = 1;
//        }
//    }
//
//    void update (int v, int tl, int tr, int l, int r, ll val) {
//        if (l > r)
//            return;
//        if (l == tl && tr == r)
//            t[v] = t[v]*val%mod;
//        else {
//            int tm = (tl + tr) / 2;
//            update (v*2, tl, tm, l, min(r,tm), val);
//            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
//        }
//    }
//
//    ll get (int v, int tl, int tr, int pos) {
//        if (tl == tr)
//            return t[v];
//        int tm = (tl + tr) / 2;
//        if (pos <= tm)
//            return t[v] * get (v*2, tl, tm, pos) %mod;
//        else
//            return t[v] * get (v*2+1, tm+1, tr, pos) %mod;
//    }
//};
class stree {
public:
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                 get (v*2, tl, tm, l, min(r,tm)) +
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] += new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
    }
};
const int A = 200500;
ll nfac[A];
ll ifac[A];
ll in[A];
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

ll cnk(int n, int k) {
    if(k<0 || k>n) return 0;
    return nfac[n]*ifac[k]%mod*ifac[n-k]%mod;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    readv(b,m);
    int l = n;
    vi cnt(A,0);
    for(auto x : a) cnt[x]++;
    ll full = nfac[n];
    for(auto x : cnt) full = full * ifac[x] % mod;
    stree st;
//    vll def;
//    ll fool = full*in[n]%mod;
//    forn(i,0,A) def.pb(fool*cnt[i]%mod);
    st.build(cnt, 1, 0, A-1);
    ll ans = 0;
    int wasn = n;
    forn(i,0,m) {
        ans += full*st.get(1, 0, A-1, 0, b[i]-1)%mod*in[n]%mod;
        if(cnt[b[i]] == 0) break;
        full = full*cnt[b[i]]%mod*in[n]%mod;
        n--;
        cnt[b[i]]--;
        st.update(1, 0, A-1, b[i], -1);
        if(n == 0) {
            if(m > wasn) ans++;
            break;
        }
    }
    cout<<ans%mod;
    
}