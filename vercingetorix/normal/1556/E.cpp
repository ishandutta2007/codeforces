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
const ll INF = 1e18;
class stree {
public:
    vll t;
    void build (const vll & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INF;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  min(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
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
    readv(b,n);
    vll pref;
    ll cur = 0;
    vll ab;
    forn(i,0,n) {
        cur+=b[i]-a[i];
        pref.pb(cur);
        ab.pb(-cur);
    }
    stree st;
    stree st2;
    st.build(pref, 1, 0, n-1);
    st2.build(ab, 1, 0, n-1);
    forn(i,0,q) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        ll mn = st.get(1, 0, n-1, l, r);
        ll sum = pref[r];
        if(l>0) sum -= pref[l-1];
        if(l>0) mn -= pref[l-1];
        if(mn < 0 || sum != 0) {
            printf("-1\n");
        }
        else {
            ll res = st2.get(1, 0, n-1, l, r);
            if(l>0) res += pref[l-1];
            printf("%lld\n", -res);
        }
    }
    
    
}