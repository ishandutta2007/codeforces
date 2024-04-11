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
    void build (int n) {
        t = vi(4*n, 0);
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                 get (v*2, tl, tm, l, min(r,tm)) +
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
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
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
    vvi pos(n+1);
    forn(i,0,n) pos[a[i]].pb(i);
    int hl = 0;
    int hr = n-1;
    stree st;
    st.build(n);
    ll ans = 0;
    for(int val = n; val >0; val--) {
        if(pos[val].empty()) continue;
        int l = pos[val][0];
        int r = pos[val].back();
//        int l2 = max(l, hl);
//        int r2 = min(r, hr);
//        hl = min(l, hr);
        if(hl > r) {
            r = hl-1;
//            r2 = hl-1;
        }
        else if(hr < l) {
            l = hr+1;
//            l2 = hr+1;
        }
        else {
            hl = l;
            hr = r;
        }
        ans += st.get(1, 0, n-1, l, r);
        hl = l;
        hr = r;
        ans += pos[val].size();
        for(auto i : pos[val]) st.update(1, 0, n-1, i, 1);
    }
    cout<<ans;
//    vi l(n, 0);
//    vi r(n, 0);
//    stree st;
//    st.build(n+1);
//    forn(i,0,n) {
//        if(a[i]>0) {
//            st.update(1, 0, n, a[i], 1);
//            l[i] = st.get(1, 0, n, 0, a[i]);
//        }
//    }
//    st.build(n+1);
//    for(int i = n-1; i>=0; i--) {
//        if(a[i]>0) {
//            st.update(1, 0, n, a[i], 1);
//            r[i] = st.get(1, 0, n, 0, a[i]);
//        }
//    }
//    ll ans = 0;
//    forn(i,0,n) if(a[i] > 0) ans += min(l[i], r[i]);
    
    
}