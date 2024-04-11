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

class stree {
public:
    vll t;
    vll k;
    vll b;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            k = vll(n*4,1);
            b = vll(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
            if(t[v] >= mod) t[v] -= mod;
        }
    }
    
    void push(int v, int tl, int tr) {
        if(k[v] == 1 && b[v] == 0) return;
        if(tl != tr) {
            b[2*v+1] = (k[v]*b[2*v+1] + b[v])%mod;
            k[2*v+1] = k[2*v+1]*k[v]%mod;
            b[2*v] = (k[v]*b[2*v] + b[v])%mod;
            k[2*v] = k[v*2]*k[v]%mod;
        }
        t[v] = (t[v]*k[v] + b[v]*(tr-tl+1))%mod;
        k[v] = 1;
        b[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int kn, int bn) {
        if (l == tl && tr == r) {
            push(v,tl,tr);
            k[v] = kn;
            b[v] = bn;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), kn, bn);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, kn, bn);
            t[v] = t[v*2] + t[v*2+1];
            if(t[v] >= mod) t[v] -= mod;
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  (get(v*2, tl, tm, l, min(r,tm))+ get(v*2+1, tm+1, tr, max(l,tm+1), r));
        if(ret>=mod) ret-=mod;
        t[v] = t[v*2] + t[v*2+1];
        if(t[v] >= mod) t[v] -= mod;
        return ret;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    stree st;
    st.build(n, 1, 0, n-1);
    vector<set<pi>> vals(n);
    while(q--) {
        int tp;
        int l,r;
        scanf("%d %d %d", &tp, &l, &r);
        l--; r--;
        if(tp == 1) {
            int x;
            scanf("%d", &x);
            x--;
            auto it = vals[x].lower_bound(mp(l,l));
            auto it2 = vals[x].lower_bound(mp(r+2, r+2));
            int tl = l, tr = r;
            if(it != vals[x].begin()) {
                it--;
                if(it->second < l-1) it++;
                else tl = it->first;
            }
            if(it2 != vals[x].begin()) {
                it2--;
                tr = max(tr, it2->second);
                it2++;
            }
            vpi del;
            vpi ev;
            while(it != it2) {
                ev.pb(mp(it->first, 1));
                ev.pb(mp(it->second+1, -1));
                del.pb(*it);
                it++;
            }
            forn(i,0,ev.size()) ev[i].first = min(ev[i].first, r+1);
            ev.pb(mp(r+1,0));
            int cur = 0;
            int last = l;
            for(auto xx : del) vals[x].erase(xx);
            vals[x].insert(mp(tl, tr));
            for(auto xx : ev) {
                if(xx.first > last) {
                    if(cur == 0) {
                        st.update(1, 0, n-1, last, xx.first-1, 1, 1);
                    }
                    else {
                        st.update(1, 0, n-1, last, xx.first-1, 2, 0);
                    }
                    last = xx.first;
                }
                cur += xx.second;
            }
        }
        else {
            printf("%lld\n", st.get(1, 0, n-1, l, r));
        }
    }
    
    
}