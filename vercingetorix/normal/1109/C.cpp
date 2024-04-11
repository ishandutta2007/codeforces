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

struct sega {
    sega(int l = 0, ll s = 0) : l(l), s(s) {
        if(s >= 0) dm = mp(0, 0);
        else dm = mp(s, l);
    }
    
    void fixs(ll ns) {
        s = ns * l;
        dm = min(mp(0ll,0ll), mp(s,ll(l)));
    }
    
    sega(int l, ll s, pll dm) : l(l), s(s), dm(dm) {};
    int l;
    ll s;
    pll dm;
};

sega combine(sega & l, sega & r) {
    return sega(l.l + r.l, l.s + r.s, min(l.dm, mp(l.s + r.dm.first, l.l + r.dm.second)));
}

pll plp(const pll & a, const pll & b) {
    return mp(a.first+b.first, a.second + b.second);
}

sega z(0,0);
const int ban = -2e9;

class stree {
public:
    vector<sega> t;
    vi pp;
    void build (vi & l, int v, int tl, int tr) {
        if(v==1) {
            t.resize(l.size() * 4);
            pp = vi(l.size()*4,ban);
        }
        if (tl == tr) {
            t[v] = sega(l[tl], 0);
        }
        else {
            int tm = (tl + tr) / 2;
            build (l, v*2, tl, tm);
            build (l, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2 + 1]);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == ban) return;
        t[v].fixs(pp[v]);
        if(tl != tr) {
            pp[2*v] = pp[v];
            pp[2*v+1] = pp[v];
        }
        pp[v] = ban;
    }
    
    void update (int v, int tl, int tr, int l, int r, int s) {
        if (l == tl && tr == r) {
            pp[v] = s;
            push(v,tl,tr);
            return;
        }
        else if(tl==tr) {
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v,tl,tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), s);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, s);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    pll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return mp(0,0);
        if (tl ==l && r== tr)
            return mp(t[v].s, t[v].l);
        int tm = (tl + tr) / 2;
        pll ret =  plp(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = combine(t[v*2], t[v*2+1]);
        return ret;
    }
    
    pll getr(int v, int tl, int tr, ll ter) {
        push(v, tl, tr);
        if(t[v].dm.first + ter > 0) return mp(tr + 1, t[v].s);
        if (tl == tr) return mp(tl, t[v].s);
        int tm = (tl + tr) / 2;
        push(v*2, tl, tm);
        push(v*2+1, tm+1, tr);
        if(t[v*2].dm.first + ter <= 0) {
            auto ret =  getr(v*2, tl, tm, ter);
            t[v] = combine(t[v*2], t[v*2+1]);
            return ret;
        }
        else {
            auto ret = getr(v*2+1,tm+1,tr, ter + t[v*2].s);
            t[v] = combine(t[v*2], t[v*2+1]);
            return ret;
        }
    }
    
    pll getfr (int v, int tl, int tr, int l, int r, ll ter) {
        push(v, tl, tr);
        if (l>r) return mp(tr + 1, 0);
        if (tl ==l && r== tr) {
            return getr(v, tl, tr, ter);
//            if(t[v].s + ter <= 0) return mp(tl, t[v].s);
//            else return mp(tr+1, t[v].s);
        }
        int tm = (tl + tr) / 2;
        auto gol = getfr(v*2, tl, tm, l, min(r, tm), ter);
        if(gol.first <= tm) {
            push(v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
            return gol;
        }
        else {
            auto gol2 = getfr(v*2+1, tm+1, tr, max(l, tm+1), r, ter + gol.second);
            gol2.second += gol.second;
            t[v] = combine(t[v*2], t[v*2+1]);
            return gol2;
        }
    }
    
    
};
stree st;
set<pi> cur;
int m = 0;
void ac(int t, int s) {
    auto it = cur.lower_bound(mp(t, -2e9));
    auto x = *it;
    st.update(1, 0, m-1, t, it->first - 1, s);
    cur.insert(mp(t,s));
}

void dc(int t) {
    auto it = cur.lower_bound(mp(t, -2e9));
    auto del = *it;
    it++;
    int r = it->first - 1;
    it--;
    it--;
    st.update(1, 0, m-1, it->first, r, it->second);
    cur.erase(del);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int taf;
    read(taf);
    set<int> pos;
    pos.insert(0);
    vvi q;
    while(taf --) {
        int tp;
        read(tp);
        if(tp == 1) {
            int t,s;
            scanf("%d %d", &t, &s);
            q.pb(vi({1,t,s}));
            pos.insert(t);
        }
        else if(tp == 2) {
            int t;
            scanf("%d", &t);
            q.pb(vi({2,t}));
        }
        else if(tp == 3) {
            int l,r,v;
            scanf("%d %d %d", &l, &r, &v);
            q.pb(vi({3,l,r,v}));
            pos.insert(l);
            pos.insert(r);
        }
    }
    map<int, int> to;
    
    for(auto x : pos) to[x] = m++;
    
    vi ps;
    for(auto x : pos) {
        ps.pb(x);
    }
    vi len;
    forn(i,1,ps.size()) len.pb(ps[i] - ps[i-1]);
    len.pb(0);
    st.build(len, 1, 0, m-1);
    
    cur.insert(mp(0,0));
    cur.insert(mp(m,0));
    forn(i,0,q.size()) {
        if(q[i][0] == 1) {
            int t = q[i][1];
            int s = q[i][2];
            t = to[t];
            ac(t,s);
        }
        else if(q[i][0] == 2) {
            int t = q[i][1];
            t = to[t];
            dc(t);
        }
        else if(q[i][0] == 3) {
            int l = q[i][1];
            int r = q[i][2];
            ll v = q[i][3];
            if(v==0) {
                printf("%d\n", l);
                continue;
            }
            int wl = l;
            l = to[l];
            r = to[r] - 1;
            bool nr = false;
            auto it = cur.lower_bound(mp(l, -2e9));
            if(it->first != l) {
                nr = true;
                ac(l,0);
            }
            pll dr = st.getfr(1, 0, m-1, l, r, v);
            if(dr.first > r) {
                printf("-1\n");
            }
            else {
                int k = dr.first;
                auto hap = st.get(1,0,m-1,l,k-1);
                v += hap.first;
                wl+=hap.second;
                auto it = cur.lower_bound(mp(k+1,-2e9));
                it--;
                ll s = it->second;
                double ans = double(wl) - double(v)/s;
                printf("%.10lf\n", ans);
            }
            if(nr) dc(l);
        }
    }
    
    
    
    
}