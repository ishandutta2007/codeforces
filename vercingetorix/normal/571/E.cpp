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

vpi fac(int n) {
    vpi ret;
    for(int k = 2; k*k <=n;k++) {
        if(n%k == 0) {
            ret.pb(mp(k,1));
            n/=k;
            while(n%k==0) {
                n/=k;
                ret.back().second++;
            }
        }
    }
    if(n != 1) ret.pb(mp(n,1));
    srt(ret);
    return ret;
}

vvpi a, b;
int n;
void no() {
    printf("-1");
    exit(0);
}
vpi simp(vpi x) {
    int d=  0;
    for(auto y : x) d = gcd(d, y.second);
    vpi ret;
    for(auto y : x) ret.pb(mp(y.first, y.second / d));
    srt(ret);
    return ret;
}

int sumd(vpi x) {
    int ret = 0;
    for(auto y : x) ret += y.second;
    return ret;
}

vpi comb(vpi & a, vpi & b, int lam) {
    map<int, int> ret;
    for(auto x : a) ret[x.first] += x.second;
    for(auto x : b) ret[x.first] += x.second*lam;
    vpi reta;
    for(auto x : ret) if(x.second > 0) reta.pb(x);
    srt(reta);
    return reta;
}

vpll combll(vpi & a, vpi & b, ll lam) {
    map<ll, ll> ret;
    for(auto x : a) ret[x.first] += x.second;
    for(auto x : b) ret[x.first] += x.second*lam;
    vpll reta;
    for(auto x : ret) if(x.second > 0) reta.pb(x);
    srt(reta);
    return reta;
}

bool check(int ind, vpi to) {
    map<int, int> f;
    for(auto x : to) f[x.first] = x.second;
    for(auto x : a[ind]) f[x.first] -= x.second;
    vpi cur;
    for(auto x : f) {
        if(x.second < 0) return false;
        if(x.second > 0) cur.pb(x);
    }
    if(cur.empty()) return true;
    if(simp(b[ind]) != simp(cur)) return false;
    int sb = sumd(b[ind]);
    int sc = sumd(cur);
    if(sc != 0 && sb == 0) return false;
    if(sc % sb != 0) return false;
    return true;
}

void check(vpi to) {
    forn(i,0,n) if(!check(i, to)) no();
    ll ans = 1;
    for(auto x : to) forn(it,0,x.second) ans = ans*x.first%mod;
    printf("%lld\n", ans);
    exit(0);
}

ll kpow(ll a, ll d, ll modulo) {
    if (d==0) return 1;
    ll x = kpow(a,d/2,modulo);
    x = x*x%modulo;
    if (d%2==1) x*=a;
    return x%modulo;
}

void goans(vpll to) {
    ll ans = 1;
    for(auto x : to) ans = ans*kpow(x.first,x.second,mod)%mod;
    printf("%lld\n", ans);
    exit(0);
}

void softcheck(vpi to) {
    forn(i,0,n) if(!check(i, to)) return;
    ll ans = 1;
    for(auto x : to) forn(it,0,x.second) ans = ans*x.first%mod;
    printf("%lld\n", ans);
    exit(0);
}

vpi smod(vpi a, vpi m) {
    map<int, int> ret;
    for(auto x : a) ret[x.first] = x.second;
    for(auto x : m) ret[x.first] %= x.second;
    vpi ge;
    for(auto x : ret) if(x.second != 0) ge.pb(x);
    srt(ge);
    return ge;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        a.pb(fac(x));
        scanf("%d", &x);
        b.pb(fac(x));
    }
    if(n==1) check(a[0]);
    set<int> prs;
    for(auto x : a) for(auto y : x) prs.insert(y.first);
    for(auto x : b) for(auto y : x) prs.insert(y.first);
    vvpi bs;
    forn(i,0,n) bs.pb(simp(b[i]));
    forn(i,1,n) {
        if(bs[i] != bs[i-1]) {
            forn(lam,0,1000) if(check(i-1, comb(a[i], b[i], lam))) {
                check(comb(a[i], b[i], lam));
            }
            no();
        }
    }
    forn(lam,0,10000) {
        softcheck(comb(a[0], bs[0], lam));
    }
    if(bs[0].empty()) no();
    vi sumo;
    vvpi mm;
    forn(i,0,n) mm.pb(smod(a[i], bs[0]));
    forn(i,1,n) if(mm[i] != mm[i-1]) no();
    forn(i,0,n) sumo.pb(sumd(b[i]));
    ll st = sumd(a[0]);
    ll d = sumd(bs[0]);
//    ll per = sumo[0]/d;
    ll per = sumo[0];
    forn(i,1,n) {
        ll pernow = sumo[i];
        ll snow = sumd(a[i]);
        ll perwas = per;
        if(abs(st-snow) % gcd(per,pernow) != 0) no();
        while(st < snow || (st - snow)%pernow != 0) st += per;
        while(per%pernow!=0) per+=perwas;
    }
    goans(combll(a[0], bs[0], (st-sumd(a[0]))/d));
    no();
//    for(auto p : prs) {
//        vpi bd;
//        forn(i,0,n) {
//            int deg = 0;
//            for(auto x : b[i]) if(x.first == p) deg = x.second;
//            bd.pb(mp(deg, i));
//        }
//        vpi ad;
//        forn(i,0,n) {
//            int deg = 0;
//            for(auto x : a[i]) if(x.first == p) deg = x.second;
//            ad.pb(mp(deg, i));
//        }
//        srt(bd);
//        if(bd[0].first != bd.back().first) {
//            int i = bd[0].second;
//            int j = bd.back().second;
//            int def = ad[j].first-ad[i].first;
//        }
//
//        srt(ad);
//        if(ad[0].first != ad.back().first) {
//            cout<<-1;
//            exit(0);
//        }
//    }
    
    
}