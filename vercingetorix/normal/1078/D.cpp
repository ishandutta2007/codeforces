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
pi combine(pi a, pi b) {
    return mp(min(a.first, b.first), max(a.second, b.second));
}
const int INF = 1e9;
const pi zero = mp(INF, -INF);
class stree {
public:
    vpi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
        }
        if (tl == tr) {
            t[v] = mp(tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return zero;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  combine(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, pi new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  combine(t[v*2], t[v*2+1]);
        }
    }
};

const int M = 18;
stree st[M];
int need;
bool bad(const pi & x) {
    return x.second - x.first < need;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    if(n==1) {
        cout<<0;
        exit(0);
    }
    forn(i,0,n) a.pb(a[i]);
    n*=2;
    forn(l,0,M) st[l].build(n, 1, 0, n - 1);
    forn(i,0,n) {
        st[0].update(1, 0, n-1, i, mp(max(0,i-a[i]), min(n-1, i+a[i])));
    }
    forn(lev,1,M) {
        forn(i,0,n) {
            auto lr = st[lev-1].get(1, 0, n-1, i, i);
            int l = lr.first;
            int r = lr.second;
            st[lev].update(1, 0, n-1, i, st[lev-1].get(1, 0, n-1, l, r));
        }
    }
    need = n/2 - 1;
    vi ans(n, n);
    forn(i,0,n) {
        int l = i;
        int r = i;
        int op = 0;
        for(int lev = M-1; lev >= 0; lev--) {
            auto to = st[lev].get(1, 0, n-1, l, r);
            if(bad(to)) {
                l = to.first;
                r = to.second;
                op += 1<<lev;
            }
        }
        ans[i] = op+1;
    }
    n/=2;
    forn(i,0,n) ans[i] = min(ans[i], ans[i+n]);
    forn(i,0,n) printf("%d ", ans[i]);
    
    
}