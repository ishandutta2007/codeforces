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
int flip[20], d2[20];
int vdep[1<<20];
int n;
class stree {
public:
    vll t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            vdep[v] = n-1;
        }
        else vdep[v] = vdep[v/2] - 1;
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int vf = 0;
        if(flip[vdep[v]]) vf = 1;
        ll ret = 0;
        if(l <= tm) ret += get (v*2+vf, flip[vdep[v]]^tl, flip[vdep[v]]^tm, flip[vdep[v]]^l, flip[vdep[v]]^min(r,tm));
        if(r>tm) ret+= get (v*2+1-vf, flip[vdep[v]]^(tm+1), flip[vdep[v]]^tr, flip[vdep[v]]^max(l,tm+1), flip[vdep[v]]^r);
        return  ret;
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
    int q;
    scanf("%d %d", &n, &q);
    readv(a, 1<<n);
    stree st;
    int N = 1<<n;
    st.build(a, 1, 0, N-1);
    while(q--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 1) {
            int x,k;
            scanf("%d %d", &x, &k);
            x--;
            forn(i,0,n) x^=flip[i];
            st.update(1, 0, N-1, x, k);
        }
        else if(tp == 2) {
            int k;
            scanf("%d", &k);
            forn(i,0,k) flip[i] ^= (1<<i);
        }
        else if(tp == 3) {
            int k;
            scanf("%d", &k);
            flip[k] ^= (1<<k);
        }
        else if(tp == 4) {
            int l,r;
            scanf("%d %d", &l, &r);
            l--; r--;
            printf("%lld\n", st.get(1, 0, N-1, l, r));
        }
    }
    
    
    
}