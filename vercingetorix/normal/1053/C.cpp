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
    vll t;
    vll ti;
    vll ta;
    vi ass;
    void build (const vi & a, const vi & x, int v, int tl, int tr) {
        if(v==1) {
            ass = x;
            t.resize(a.size() * 4);
            ti.resize(a.size() * 4);
            ta.resize(a.size() * 4);
        }
        if (tl == tr) {
            t[v] = a[tl];
            ti[v] = (ll(tl)*a[tl])%mod;
            ta[v] = (ll(x[tl])*a[tl]) % mod;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, x, v*2, tl, tm);
            build (a, x, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
            ti[v] = ti[v*2] + ti[v*2+1];
            if(ti[v] >= mod) ti[v] -= mod;
            ta[v] = ta[v*2] + ta[v*2+1];
            if(ta[v] >= mod) ta[v] -= mod;
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
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
    
    ll geti (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return ti[v];
        int tm = (tl + tr) / 2;
        return  (
                 geti (v*2, tl, tm, l, min(r,tm)) +
                 geti (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    ll geta (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return ta[v];
        int tm = (tl + tr) / 2;
        return  (
                 geta (v*2, tl, tm, l, min(r,tm)) +
                 geta (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    ll getami(int v, int tl, int tr, int l, int r, int k) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return (ta[v] - ti[v] - t[v]%mod*k)%mod;
        }
        int tm = (tl + tr) / 2;
        return  (
                 getami (v*2, tl, tm, l, min(r,tm), k) +
                 getami (v*2+1, tm+1, tr, max(l,tm+1), r, k)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
            ti[v] = ll(new_val)*tl%mod;
            ta[v] = ll(ass[tl])*new_val%mod;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
            ti[v] = ti[v*2] + ti[v*2+1];
            if(ti[v] >= mod) ti[v] -= mod;
            ta[v] = ta[v*2] + ta[v*2+1];
            if(ta[v] >= mod) ta[v] -= mod;
        }
    }
    
    int getr(int v, int tl, int tr, ll k) {
        if(t[v] < k) return tr+1;
        if(tl==tr) return tl;
        int tm = (tl+tr)/2;
        if(t[v*2] >= k) return getr(v*2, tl, tm, k);
        else return getr(v*2+1,tm+1,tr,k-t[v*2]);
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
    readv(a,n);
    readv(w,n);
    stree st;
    st.build(w, a, 1, 0, n-1);
    while(q--) {
        int x,y;
        scanf("%d %d", &x, &y);
        if(x < 0) {
            x = -x - 1;
            st.update(1, 0, n-1, x, y);
        }
        else {
            x--; y--;
            ll sum = st.get(1, 0, n-1, x, y);
            ll pref = st.get(1, 0, n-1, 0, x-1);
            int to = st.getr(1, 0, n-1, pref + (sum+1)/2);
//            cout<<to<<endl;
            ll ans = 0;
            if(y > to) {
                ans += st.getami(1, 0, n-1, to+1, y, a[to]-to);
            }
            if(x<to) {
                ans -= st.getami(1, 0, n-1, x, to-1, a[to]-to);
            }
            ans = (ans%mod+mod)%mod;
            printf("%lld\n", ans);
        }
    }
    
    
}