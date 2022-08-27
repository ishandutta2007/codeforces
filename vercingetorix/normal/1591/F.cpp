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
    vi t;
    vi len;
    vi pp;
    vi kill;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            int n = a.size();
            t.resize(n * 4);
            len.resize(n * 4);
            kill = vi(n*4,0);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr) {
            t[v] = 0;
            len[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = 0;
            len[v] = len[v*2] + len[v*2+1];
        }
    }
    
    void push(int v, int tl, int tr) {
        if(kill[v]) {
            if(tl != tr) {
                kill[v*2] = 1;
                kill[v*2 + 1] = 1;
                pp[v*2] = 0;
                pp[v*2 + 1] = 0;
            }
            t[v] = 0;
            kill[v] = 0;
        }
        if(pp[v]) {
            t[v] = (t[v] + ll(pp[v])*len[v])%mod;
            if(tl!=tr) {
                pp[v*2] += pp[v];
                pp[v*2+1] += pp[v];
                if(pp[v*2] >= mod) pp[v*2]-=mod;
                if(pp[v*2+1] >= mod) pp[v*2+1]-=mod;
            }
            pp[v] = 0;
        }
    }
    
    void destroy (int v, int tl, int tr, int l, int r) {
        if (l == tl && tr == r) {
            pp[v] = 0;
            kill[v] = 1;
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
            destroy (v*2, tl, tm, l, min(r,tm));
            destroy (v*2+1, tm+1, tr, max(l,tm+1), r);
            t[v] = t[v*2] + t[v*2+1];
            if(t[v] >= mod) t[v] -= mod;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] += val;
            if(pp[v] >= mod) pp[v] -= mod;
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
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = t[v*2] + t[v*2+1];
            if(t[v] >= mod) t[v] -= mod;
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
        if(ret >= mod) ret -= mod;
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
    int n;
    read(n);
    readv(a,n);
    set<int> b;
    for(auto x : a) b.insert(x);
    vi l;
    int last = 0;
    vi p;
    l.pb(1);
    p.pb(0);
    for(auto x : b) {
        l.pb(x-last);
        p.pb(x);
        last = x;
    }
    stree st;
    int A = p.size();
    st.build(l, 1, 0, A-1);
    st.update(1, 0, A-1, 0, 0, 1);
    int sg = 1;
    for(auto xn : a) {
        int x = lower_bound(all(p), xn) - p.begin();
        int sum = st.get(1, 0, A-1, 0, A-1);
        st.destroy(1, 0, A-1, 0, 0);
        st.destroy(1, 0, A-1, x+1, A-1);
        sum = (mod-sum)%mod;
        st.update(1, 0, A-1, 1, x, sum);
        sg = -sg;
    }
    cout<<(mod+sg*st.get(1, 0, A-1, 0, A-1))%mod;
    
}