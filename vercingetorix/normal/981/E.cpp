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
const int A = 10001;
bitset<A> bs;
bitset<A> cur;
class stree {
public:
    vvi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        t.resize(4*n);
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v].pb(val);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    void go(int v, int tl, int tr) {
        bitset<A> was = cur;
        for(auto x : t[v]) cur |= cur<<x;
        if(tl == tr) bs |= cur;
        else {
            int tm = (tl + tr) / 2;
            go(v*2, tl, tm);
            go(v*2+1,tm+1,tr);
        }
//        cur = was;
        swap(cur, was);
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cur.set(0);
    int n,m;
    scanf("%d %d", &n, &m);
    stree st;
    st.build(n, 1, 0, n-1);
    forn(i,0,m) {
        int l,r,v;
        scanf("%d %d %d", &l, &r, &v);
        st.update(1, 0, n-1, l-1, r-1, v);
    }
    st.go(1,0,n-1);
    vi ans;
    forn(i,1,n+1) if(bs[i]) ans.pb(i);
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d ", x);
    
    
}