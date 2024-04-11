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

class stree {
public:
    vll t;
    vll pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vll(n*4,1);
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
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 1) return;
        t[v] = t[v]*pp[v] % mod;
        if(tl != tr) {
            pp[2*v] = pp[2*v]*pp[v] %mod;
            pp[2*v+1] = pp[2*v+1]*pp[v] %mod;
        }
        pp[v] = 1;
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l == tl && tr == r) {
            pp[v] = pp[v]*val%mod;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        //            t[v] = max(t[v],val);
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = (t[v*2]+ t[v*2+1])%mod;
        }
    }
    
    void set (int v, int tl, int tr, int pos, ll val) {
        if(pos > tr || pos < tl) {
            push(v, tl, tr);
            return;
        }
        else if (tl == tr) {
            pp[v] = 1;
            t[v] = val;
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            set (v*2, tl, tm, pos, val);
            set (v*2+1, tm+1, tr, pos, val);
            t[v] = (t[v*2]+ t[v*2+1])%mod;
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  (get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r)) % mod;
        t[v] = (t[v*2] + t[v*2+1]) % mod;
        return ret;
    }
};

bool comp(const pair<pll, int> & a, const pair<pll, int> & b) {
    if(a.first.first*b.first.second < a.first.second*b.first.first || (a.first.first*b.first.second == a.first.second*b.first.first && a.second < b.second)) return true;
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    set<pi> s;
    vll l(n);
    vll r(n);
    vll bi(n,0);
    vll v(n);
    vll x(n);
    ll curp = 1;
    ll i100 = invmod(100, mod);
    forn(i,0,n) {
        ll p;
        scanf("%lld %lld %lld", &x[i], &v[i], &p);
        s.insert(mp(i,i));
        l[i] = i100*(100-p)%mod;
        r[i] = i100*p%mod;
    }
    vector<pair<pll, int>> ev;
    forn(i,0,n-1) {
        ev.pb(mp(mp(x[i+1]-x[i], v[i]+v[i+1]), i+1));
        if(v[i] != v[i+1])
            ev.pb(mp(mp(x[i+1]-x[i], abs(v[i]-v[i+1])), -i-1));
    }
    sort(ev.begin(), ev.end(), comp);
    stree st;
    st.build(n, 1, 0, n-1);
    ll ans = 0;
    for(auto x : ev) {
        if(x.second > 0) {
            auto it = s.lower_bound(mp(x.second, x.second));
            int l2 = it->first;
            int r2 = it->second;
            it--;
            int l1 = it->first;
            int r1 = it->second;
            s.erase(mp(l1,r1));
            s.erase(mp(l2,r2));
            ll in1 = st.get(1, 0, n-1, l1, r1-1);
            ll in2 = st.get(1, 0, n-1, l2, r2-1);
            ll pin = (l[l1] + r[l1] + in1)%mod * (l[l2] + r[l2] + in2)%mod;
            if(pin == 0) break;
            ll pout = curp * invmod(pin, mod) % mod;
            ll pend = (r[l1] + in1) * (l[l2] + in2)%mod;
            ll pendglobal = pend * pout % mod;
            ans = (ans + x.first.first * invmod(x.first.second, mod) % mod * pendglobal) % mod;
            s.insert(mp(l1,r2));
            st.update(1, 0, n-1, l1, r1, r[l2]);
            st.update(1, 0, n-1, r1, r2-1, l[l1]);
            l[l1] = l[l1] * l[l2] % mod;
            r[l1] = r[l1] * r[l2] % mod;
            ll pcont = (pin + mod - pend)%mod;
            curp = pout*pcont % mod;
        }
        else {
            int k = -1-x.second;
            auto it = s.lower_bound(mp(k+1, 0));
            it --;
            int l1 = it->first;
            int r1 = it->second;
            ll in1 = st.get(1, 0, n-1, l1, r1-1);
            ll pin = (l[l1] + r[l1] + in1)%mod;
            if(pin == 0) break;
            ll pout = curp * invmod(pin, mod) % mod;
            ll pend = 0;
            if(v[k] > v[k+1]) {
                pend = (st.get(1, 0, n-1, l1, k-1) + r[l1])%mod;
                st.update(1, 0, n-1, l1, k-1, 0);
                r[l1] = 0;
            }
            else if(v[k+1] > v[k]) {
                pend = (st.get(1, 0, n-1, k+1, r1-1) + l[l1])%mod;
                st.update(1, 0, n-1, k+1, r1-1, 0);
                l[l1] = 0;
            }
            ll pendglobal = pend * pout % mod;
            ans = (ans + x.first.first * invmod(x.first.second, mod) % mod * pendglobal) % mod;
            ll pcont = (pin + mod - pend)%mod;
            curp = pout*pcont % mod;
        }
    }
    cout<<ans;
}