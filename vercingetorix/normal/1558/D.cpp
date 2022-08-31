#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
vi touch;
vi was;
class stree {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = 1;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
//
//    int get (int v, int tl, int tr, int l, int r) {
//        if (l > r)
//            return 0;
//        if (l == tl && r == tr)
//            return t[v];
//        int tm = (tl + tr) / 2;
//        return  (
//                 get (v*2, tl, tm, l, min(r,tm)) +
//                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
//                 );
//    }
//
//    void update (int v, int tl, int tr, int pos, int new_val) {
//        if (tl == tr)
//            t[v] = new_val;
//        else {
//            int tm = (tl + tr) / 2;
//            if (pos <= tm)
//                update (v*2, tl, tm, pos, new_val);
//            else
//                update (v*2+1, tm+1, tr, pos, new_val);
//            t[v] =  (t[v*2]+ t[v*2+1]);
//        }
//    }
    
    int getpos(int v, int tl, int tr, int pos) {
        was.pb(t[v]);
        touch.pb(v);
        if(tl == tr) {
            t[v] = 0;
            return tl;
        }
        else {
            int tm = (tl + tr) / 2;
            int ret;
            if(t[v*2] <= pos) ret = getpos(v*2+1, tm+1, tr, pos-t[v*2]);
            else ret = getpos(v*2, tl, tm, pos);
            t[v] = t[v*2] + t[v*2+1];
            return ret;
        }
    }
};

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
vll imod;
class cnk {
public:
    ll curc, ck, cn;
    void adjust(ll n, ll k) {
        if(k>n) {
            curc = 0;
            return;
        }
        while(ck > k) {
            curc = curc*ck%mod;
            curc = curc*imod[cn-ck+1]%mod;
            ck--;
        }
        while(cn < n) {
            curc = curc * (cn+1)%mod;
            curc = curc * imod[cn-ck+1]%mod;
            cn++;
        }
        while(ck < k) {
            curc = curc * (cn-ck)%mod;
            curc = curc * imod[ck+1]%mod;
            ck++;
        }
        while(cn > n) {
            curc = curc * (cn-ck) %mod;
            curc = curc *imod[cn] % mod;
            cn--;
        }
    }
};



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    stree st;
    int A = 200500;
    imod.pb(0);
    forn(i,1,2*A) imod.pb(invmod(i, mod));
    st.build(A, 1, 0, A-1);
    vll cn2n;
    cn2n.pb(1);
    cnk x;
    x.ck = 0;
    x.cn = 1;
    x.curc = 1;
    forn(i,1,A) {
        x.adjust(2*i, i);
        cn2n.pb(x.curc);
    }
    
    int t;
    read(t);
    vi taken(A,0);
    vi touchtaken;
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        vi x(m),y(m);
        forn(i,0,m) scanf("%d %d", &x[i], &y[i]);
        forn(i,0,m) x[i]--;
        forn(i,0,m) y[i]--;
        vpi q;
        forn(i,0,m) q.pb(mp(x[i], i));
        touch.clear();
        was.clear();
        srtrev(q);
        int br = 0;
        for(auto xx : q) {
            int to = st.getpos(1, 0, A-1, y[xx.second]);
            br++;
            if(taken[to+1]) br--;
            taken[to] = 1;
            touchtaken.pb(to);
        }
        cnk xa;
        xa.curc = cn2n[n];
        xa.cn = 2*n;
        xa.ck = n;
        xa.adjust(2*n-br-1, n-br-1);
//        cout<<2*n-br-1<<' '<<n-br-1<<endl;
        printf("%lld\n", xa.curc);
        for(auto x : touchtaken) taken[x] = 0;
        while(!touch.empty()) {
            st.t[touch.back()] = was.back();
            was.pop_back();
            touch.pop_back();
        }
        touchtaken.clear();
    }
    
    
}