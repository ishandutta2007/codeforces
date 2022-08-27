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
class stree {
public:
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = max(t[v], val);
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
            return max(t[v], get (v*2, tl, tm, pos));
        else
            return max(t[v], get (v*2+1, tm+1, tr, pos));
    }
};
const int A = 10500;
int bval[A];
int l[A];
int r[A];
double p[A];
vi ch[A];

pair<int, vd> d[A];

void dfs(int v) {
    d[v] = mp(bval[v], vd());
    for(auto u : ch[v]) {
        dfs(u);
        if(d[u].first > d[v].first) swap(d[u], d[v]);
        while(d[v].first + d[v].second.size() < d[u].first + d[u].second.size()) {
            d[v].second.pb(0);
        }
        for(int i = 0; d[v].first + i + 1 <= d[u].first + d[u].second.size(); i++) {
            int j = i + d[v].first - d[u].first;
            d[v].second[i] = 1- (1-d[v].second[i])*(1-d[u].second[j]);
        }
    }
    d[v].second.pb(0);
    for(int i = d[v].second.size() - 1; i>= 1; i--) {
        d[v].second[i] += (d[v].second[i-1]-d[v].second[i])*p[v];
    }
    d[v].second[0] = 1-(1-d[v].second[0])*(1-p[v]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    readv(a,n);
    int mx = 0;
    forn(i,0,n) mx = max(a[i], mx);
    forn(i,0,n) a[i] -= mx-q;
    int add = mx-q;
    forn(i,0,n) a[i] = max(a[i], 0);
    forn(i,1,q+1) scanf("%d %d %lf", &l[i], &r[i], &p[i]);
    stree st;
    st.build(vi(n,0), 1, 0, n-1);
    vector<pi> ev;
    ev.pb(mp(n+1, 0));
    forn(i,1,q+1) {
        l[i]--;
        r[i]--;
        ev.pb(mp(r[i]-l[i], i));
    }
    srtrev(ev);
    forn(i,1,q+1) {
        int ind = ev[i].second;
        int lpar = st.get(1, 0, n-1, l[ind]);
        int cpar = ev[lpar].second;
        ch[cpar].pb(ind);
        st.update(1, 0, n-1, l[ind], r[ind], i);
    }
    forn(i,0,n) {
        int loc = st.get(1, 0, n-1, i);
        int ind = ev[loc].second;
        bval[ind] = max(bval[ind], a[i]);
    }
//    cout<<1;
    dfs(0);
//    cout<<1;
    double ans = add+d[0].first;
    for(auto x : d[0].second) ans += x;
    printf("%.10lf", ans);
    
    
    
}