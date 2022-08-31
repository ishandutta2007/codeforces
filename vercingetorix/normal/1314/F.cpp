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

typedef unsigned long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<ll> vll;
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

vll d2(1,1);
ll d2t[64][64];
ll mt[8][8][256][256];
ll mask[8];
map<ll, int> atos;

ll smart(ll a, ll b) {
    ll ret = 0;
    forn(l,0,8) forn(r,0,8) ret^= mt[l][r][(a&mask[l])>>(l*8)][(b&mask[r])>>(r*8)];
    return ret;
}

ll naive_multiply(ll a, ll b) {
    ll ret = 0;
    forn(bit1,0,64) {
        if(a&d2[bit1]) {
            forn(bit2,0,64) if(b&d2[bit2]) ret^=d2t[bit1][bit2];
        }
    }
    return ret;
}

ll multiply_powers_of_2(ll a, ll b) {
    if (a == 1 or b == 1) return a * b;
    ll n = 0;
    while(n<=4 && d2[d2[n+1]] <= max(a,b)) n++;
    ll power = d2[d2[n]];
    if (a >= power and b >= power) {
        return naive_multiply(power / 2 * 3, d2t[atos[a / power]][atos[b / power]]);
    } else if (a >= power) {
        return d2t[atos[a / power]][atos[b]] * power;
    } else {
        return d2t[atos[a]][atos[b/power]] * power;
    }
}

ll bsgs (ll a, ll b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    
    ll an = 1;
    for (int i=0; i<n; ++i)
        an = smart(an, a);
    
    map<ll,int> vals;
    ll cur = an;
    for (int i=1; i<=n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = smart(cur, an);
    }
    cur = b;
    for (int i=0; i<=n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = smart(cur, a);
    }
    return 0;
}

ll smartpow(ll a, ll k) {
    if(k == 0) return 1;
    else if(k==1) return a;
    ll ret = smartpow(a, k/2);
    ret = smart(ret, ret);
    if(k%2==1) ret = smart(ret, a);
    return ret;
}

vi pr({3,5,17,257,641,65537,6700417});
vll divs;

ll element_order(ll a) {
    for(auto x : divs) if(smartpow(a, x) == 1) return x;
    return -1;
}

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


ll update_res(ll r, ll m, ll p, ll r2) {
    if(m == 1) return r2;
    while(r%p != r2) r+= m;
    return r;
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,63) d2.pb(d2.back() * 2);
    forn(i,0,d2[pr.size()]) {
        ll cur = 1;
        forn(j,0,pr.size()) if(i&d2[j]) cur*=pr[j];
        divs.pb(cur);
    }
    srt(divs);
    forn(i,0,64) atos[d2[i]] = i;
    forn(i,0,64) {
        d2t[i][0] = d2[i];
        d2t[0][i] = d2[i];
    }
    forn(i,1,64) forn(j,1,64) {
        d2t[i][j] = multiply_powers_of_2(d2[i], d2[j]);
    }
    forn(l,0,8) forn(r,0,8) {
        forn(lv,0,256) forn(rv,0,256) {
            forn(b1,0,8) if(lv&d2[b1]) forn(b2,0,8) if(rv&d2[b2]) {
                mt[l][r][lv][rv] ^= d2t[b1+l*8][b2+r*8];
            }
        }
    }
    forn(l,0,8) forn(b,0,8) mask[l] |= d2[l*8+b];
    int t;
    read(t);
    forn(afaf,0,t) {
        ll ansmul = 1;
        ll a,b;
        cin>>a>>b;
        ll da = element_order(a);
        ll db = element_order(b);
        if(da%db != 0) {
            printf("-1\n");
            continue;
        }
        ansmul = da/db;
        a = smartpow(a, da/db);
        ll r = 0;
        ll m = 1;
        vi po;
        for(auto x : pr) if(db%x == 0) po.pb(x);
        srtrev(po);
        int can = 1;
        for(auto p : po) {
            ll an = smartpow(a, db/p);
            ll bn = smartpow(b, db/p);
            ll r2 = bsgs(an, bn, p);
            if(r2 == 0 && bn != 1) {
                can = 0;
                break;
            }
            r = update_res(r, m, p, r2);
            m *= p;
        }
        if(can == 0) printf("-1\n");
        else cout<<r*ansmul<<endl;
//        else printf("%lld\n", r*ansmul);
//        cout<<da<<' '<<db<<endl;
    }
    
    
}