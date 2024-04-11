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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
const int INF = 2e9;
class streemin {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = INF;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = INF;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = min(t[v], val);
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return min(t[v], get (v*2, tl, tm, pos));
        else
            return min(t[v], get (v*2+1, tm+1, tr, pos));
    }
};

class stree {
public:
    vll t;
    int s;
    void build (int n) {
        s = n;
        t = vll(4*n,0);
    }
    
    void update (int v, int tl, int tr, int l, int r, ll add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += add;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        }
    }
    
    ll get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    int m;
    read(m);
    scanf("%d", &n);
    vi l(n), r(n), t(n);
    set<int> pos;
    pos.insert(0);
    forn(i,0,n) {
        scanf("%d %d %d", &l[i], &r[i], &t[i]);
        pos.insert(l[i]);
        pos.insert(r[i]);
    }
    
    
    vi q(m);
    forn(i,0,m) {
        scanf("%d", &q[i]);
        q[i] = -q[i];
    }
    reverse(all(q));
    vi px;
    for(auto x : pos) px.pb(x);
    int k = px.size();
    streemin st;
    map<int, int> to;
    st.build(k, 1, 0, k-1);
    forn(i,0,k) to[px[i]] = i;
    forn(i,0,n) {
        int tl = to[l[i]];
        int tr = to[r[i]];
        st.update(1, 0, k-1, tl, tr-1, t[i]);
    }
    stree stc, stx;
    stc.build(m);
    stx.build(m);
    forn(i,0,k-1) {
        int tm = st.get(1, 0, k-1, i);
        if(tm==INF) continue;
        int tl = px[i];
        int tr = px[i+1];
        int ql = lower_bound(all(q), tl - tm) - q.begin();
        int qr = upper_bound(all(q), tr - tm) - q.begin();
        qr--;
        stc.update(1, 0, m-1, 0, ql-1, tr-tl);
        if(qr >= ql) {
            stx.update(1, 0, m-1, ql, qr, -1);
            stc.update(1, 0, m-1, ql, qr, tr-tm);
        }
    }
    for(int i = m-1; i>=0; i--) {
        ll c = stc.get(1, 0, m-1, i);
        ll x = stx.get(1, 0, m-1, i);
        printf("%lld\n", q[i]*x + c);
    }
    
    
}