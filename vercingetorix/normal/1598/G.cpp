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

const long long mod = 1000000007;
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
vll prlist = {1100000017,1100000051,1100000059,1100000081,1100000123,1100000149,889995497,889995527 ,889995541, 889995563,889998359,    889998401,    889998413};
ll p[2];
ll i10[2];

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
string s,x;
struct res;

struct res {
    res(ll r1 = 0, ll r2 = 0) {
        r[0] = r1;
        r[1] = r2;
        //        r[2] = r3;
    };
    ll r[2];
    int l = 0;
    
    void add(ll x) {
        forn(i,0,2) r[i] = (r[i] + x) % p[i];
    }
    
    void sub(ll x) {
        forn(i,0,2) r[i] = (r[i] + p[i] - x) % p[i];
    }
    
    void mul(ll x) {
        forn(i,0,2) r[i] = (r[i] * x) % p[i];
    }
    
    //    void add(const res & b) {
    //        forn(i,0,2) r[i] = (r[i] + b.r[i]) % p[i];
    //    }
    
    void add(const res & b) {
        forn(i,0,2) {
            r[i] = (r[i] + b.r[i]);
            if(r[i] > p[i]) r[i] -= p[i];
        }
    }
    
    void sub(const res & b) {
        forn(i,0,2) r[i] = (r[i] + p[i] - b.r[i]) % p[i];
    }
    
    void mul(const res & b) {
        forn(i,0,2) r[i] = (r[i] * b.r[i]) % p[i];
    }
    
    void div10() {
        forn(i,0,2) r[i] = (r[i] * i10[i]) % p[i];
    }
    
    bool equal(const res & b) {
        forn(i,0,2) if(r[i] != b.r[i]) return false;
        return true;
    }
};

res target;

void count_x() {
    for(auto c : x) {
        target.mul(10);
        target.add(c-'0');
    }
}

vector<res> d10;
int n;
void t2x() {
    int l = x.size() - 1;
    //    l++;
    if(l == 0) return;
    if(s.size() < 2*l) return;
    res cur;
    forn(i,0,l) {
        cur.mul(10);
        cur.add(s[i]-'0' + s[i+l]-'0');
    }
    forn(st,0,n - 2*l+1) {
        if(cur.equal(target)) {
            printf("%d %d\n", st+1, st+l);
            printf("%d %d\n", st+l+1, st+2*l);
            exit(0);
        }
        if(st == n-2*l) break;
        auto dec = d10[l-1];
        dec.mul(s[st] - '0' + s[st+l] - '0');
        cur.sub(dec);
        cur.mul(10);
        cur.add(s[st+l]-'0' + s[st+2*l] -'0');
    }
}

res combine(const res & a, const res & b) {
    res ret = a;
    ret.mul(d10[b.l]);
    ret.add(b);
    ret.l += b.l;
    return ret;
}

class pref {
public:
    vector<res> t;
    void build(string & a) {
        res cur(0,0);
        for(auto x : a) {
            cur.mul(10);
            cur.add(x-'0');
            t.pb(cur);
        }
    }
    
    res get(int l, int r) {
        res ret = t[r];
        if(l>0) {
            res dec = t[l-1];
            dec.mul(d10[r-l+1]);
            ret.sub(dec);
        }
        return ret;
    }
};

class stree {
public:
    vector<res> t;
    void build(string & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr) {
            t[v].add(a[tl]-'0');
            t[v].l = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    res get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return res();
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  combine(
                        get (v*2, tl, tm, l, min(r,tm)),
                        get (v*2+1, tm+1, tr, max(l,tm+1), r)
                        );
    }
};

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

ll get_rand_prime() {
    ll ret;
    while (true) {
        ret = ll(5e8) + gen() % (ll)5e8;
        bool good = true;
        for (int i = 2; i * i <= ret; i++) {
            if (ret % i == 0) {
                good = false;
                break;
            }
        }
        if (good) return ret;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,2) {
        p[i] = get_rand_prime();
    }
    forn(i,0,2) i10[i] = invmod(10, p[i]);
    d10.pb(res(1,1));
    forn(i,0,1000000) {
        d10.pb(d10.back());
        d10.back().mul(10);
    }
    //    auto d10 = res(i10[0], i10[1], i10[2]);
    char c[1000500];
    scanf("%s", c);
    s = string(c);
    scanf("%s", c);
    x = string(c);
    //    s = string(500000, '4');
    //    x = string(20000,'8');
    n = s.size();
    count_x();
    t2x();
    //    stree st;
    pref st;
    int A = x.size() + 1;
    auto z = z_function(x + "#" + s);
    //    st.build(s, 1, 0, n-1);
    st.build(s);
    int k = x.size();
    forn(f, 0, n-k+1) {
        //        auto lisma = st.get(1, 0, n-1, f, f+k-1);
        auto lisma = st.get(f, f+k-1);
        int tk = z[A + f];
        forn(ap, k-tk - 1, k-tk+1) {
            if(ap > 0) {
                if(f-ap >= 0) {
                    //                    auto ts  = st.get(1, 0, n-1, f-ap, f-1);
                    auto ts = st.get(f-ap, f-1);
                    ts.add(lisma);
                    if(ts.equal(target)) {
                        printf("%d %d\n", f-ap+1, f);
                        printf("%d %d\n", f+1, f+k);
                        exit(0);
                    }
                }
                if(f+k+ap-1 < n) {
                    //                    auto ts  = st.get(1, 0, n-1, f+k, f+k+ap-1);
                    auto ts = st.get(f+k, f+k+ap-1);
                    ts.add(lisma);
                    if(ts.equal(target)) {
                        printf("%d %d\n", f+1, f+k);
                        printf("%d %d\n", f+k+1, f+k+ap);
                        exit(0);
                    }
                }
            }
        }
    }
}