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

class stree {
public:
    vi t;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -2e9;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                 get (v*2, tl, tm, l, min(r,tm)) ,
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  max(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,w;
    scanf("%d %d", &n, &w);
    vll ans(w,0);
    vvi a(n);
    ll smax = 0;
    vll sm(n);
    forn(i,0,n) {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        forn(j,0,k) scanf("%d", &a[i][j]);
        int cur = 0;
        forn(j,0,k) cur = max(cur, a[i][j]);
        smax += cur;
        sm[i] = cur;
    }
    forn(i,0,w) ans[i] = smax;
    forn(i,0,n) {
        int k = a[i].size();
        set<int> pos;
        stree st;
        st.build(a[i], 1, 0, k - 1);
        forn(j,0,k) pos.insert(j);
        forn(j,w-k,w) pos.insert(j);
        for(auto p : pos) {
            int b = -2e9;
            if(p<k && p >= w-k) {
                b = st.get(1, 0, k-1, p-w+k, p);
            }
            else if(p<k) {
                b = max(0, st.get(1, 0, k-1, 0, p));
            }
            else if(p>=w-k) {
                b = max(0, st.get(1, 0, k-1, p-w+k, k-1));
            }
            ans[p] += b-sm[i];
        }
//        for(auto p : pos) {
//            int b = 2e9;
//            if(p<k) b = min(b,l[p]);
//            if(p>=n-k) b = min(b, r[n-1-p]);
//            ans[p] -= sm[i];
//            ans[p] += b;
//        }
    }
    
    
    forn(i,0,w) printf("%lld ", ans[i]);
    
    
}