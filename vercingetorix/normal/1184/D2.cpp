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

const long long mod = 1000000007;
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
const int A = 2005;
ll nfac[A];
ll ifac[A];
ll in[A];

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

string mtos(ll x) {
    forn(q,1,200) {
        if(x*q%mod < 200) return to_string(x*q%mod)+"/"+to_string(q);
        if((mod-x)*q%mod < 200) return "-"+to_string((mod-x)*q%mod)+"/"+to_string(q);
    }
    return "????";
}

int to[250][250];
int m;
class LE {
public:
    vpll t;
    ll c;

    LE() {}

    LE(int ind) {
        c = 0;
        t = vpll(1, mp(ind, 1));
    }
    void operator+=(LE b) {
        c = (c + b.c)%mod;
        for(auto x : t) b.t.pb(x);
        srt(b.t);
        int l = 0;
        t.clear();
        while(l < b.t.size()) {
            ll sum = b.t[l].second;
            int r = l+1;
            while(r<b.t.size() && b.t[r].first == b.t[l].first) sum += b.t[r++].second;
            sum %= mod;
            if(sum != 0) t.pb(mp(b.t[l].first, sum));
            l = r;
        }
    }
    
    void operator*=(ll x) {
        if(x==1) return;
        c = c*x%mod;
        for(auto & a : t) a.second = a.second*x%mod;
    }
    
    void print() {
        for(auto x : t) cout<<x.first<<';'<<mtos(x.second)<<' ';
        cout<<mtos(c)<<'\n';
    }
};

LE getpoint(int l, int r) {
    LE ret(to[l][r]);
    if(l > 1) {
        LE add(to[l-1][r]);
        add *= (mod-1);
        ret += add;
    }
    if(r > 1) {
        LE add(to[l][r-1]);
        add *= (mod-1);
        ret += add;
    }
    if(l>1 && r>1) {
        LE add(to[l-1][r-1]);
        ret += add;
    }
    return ret;
}

LE getV(int l, int r) {
    LE ret(to[l][r]);
    if(l>1 && r>1) {
        LE add(to[l-1][r-1]);
        add *= mod-1;
        ret += add;
    }
    return ret;
}

LE geteq(int l, int r) {
    LE ret = getpoint(l, r);
    ret *= mod-1;
    ll psplit = (l+r+1)*in[m]%mod;
    ll padd = (mod+1-psplit)%mod;
    if(l+r > 2) {
        LE v = getV(l, r);
        LE mpt =getpoint(l, r);
        mpt *= mod-1;
        v += mpt;
        v *= psplit*in[l+r]%mod;
        ret += v;
    }
    ret.c = psplit*(l+r+2)%mod*in[l+r]%mod;
    
    if(padd != 0) {
        LE al = getpoint(l+1, r);
        LE ar = getpoint(l, r+1);
        al *= padd*(l+1)%mod*invmod(l+r+2, mod)%mod;
        ar *= padd*(r+1)%mod*invmod(l+r+2, mod)%mod;
        ret += al;
        ret += ar;
    }
    
    return ret;
}

ll a[250][125*126];
ll c[250];
LE red[125*126];
ll ans[125*126];


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    int n,k;
    cin>>n>>k>>m;
    if(k == 1 || k == n) {
        cout<<n;
        exit(0);
    }
    if(k > n+1-k) k = n+1-k;
    int pt = 0;
    forn(l,1,m) forn(r,l,m-l) to[l][r] = pt++;
    forn(l,1,m) forn(r,1,l) to[l][r] = to[r][l];
    int pt2 = 0;
    forn(l,1,m) forn(r,l,m-l) {
        if(l != r && l+r+1!=m) {
            LE cur = geteq(l, r);
            pll t0 = cur.t.back();
            cur.t.pop_back();
            cur *= invmod(mod-t0.second, mod);
            reverse(all(cur.t));
            red[t0.first] = cur;
        }
        else {
            LE cur = geteq(l, r);
            c[pt2] = cur.c;
            for(auto x : cur.t) a[pt2][x.first] = x.second;
            pt2++;
        }
    }
    forn(i,0,m-2) {
        for(int j = pt-1; j >= pt2; j--) if(a[i][j] != 0) {
            for(auto x : red[j].t) a[i][x.first] = (a[i][x.first] + a[i][j]*x.second)%mod;
            c[i] = (c[i] + a[i][j]*red[j].c)%mod;
            a[i][j] = 0;
        }
    }
    for(int i = m-3; i>=0; i--) {
        int is = i;
        while(a[is][i] == 0) is--;
        forn(j,0,i+1) swap(a[i][j], a[is][j]);
        swap(c[i], c[is]);
        ll inv = (mod-invmod(a[i][i], mod))%mod;
        red[i].c = c[i]*inv%mod;
        forn(j,0,i) if(a[i][j] != 0) red[i].t.pb(mp(j, a[i][j]*inv%mod));
        forn(j,0,i) {
            if(a[j][i] != 0) {
                for(auto x : red[i].t) a[j][x.first] = (a[j][x.first] + a[j][i]*x.second)%mod;
                c[j] = (c[j] + a[j][i]*red[i].c)%mod;
                a[j][i] = 0;
            }
        }
    }
    forn(i,0,pt) {
        ans[i] = red[i].c;
        for(auto x : red[i].t) ans[i] += x.second*ans[x.first]%mod;
        ans[i] %= mod;
    }
    int l = k-1;
    int r = n-k;
    ll s = ans[to[l][r]];
    if(l > 1) s += mod-ans[to[l-1][r]];
    if(r > 1) s += mod-ans[to[l][r-1]];
    if(l>1 && r>1) s+=ans[to[l-1][r-1]];
    cout<<s%mod;
}