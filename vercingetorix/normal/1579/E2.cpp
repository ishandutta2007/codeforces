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
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
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
            t[v] += new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
    }
    
    int getr(int v, int tl, int tr, int k) {
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
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d", &n);
        stree st;
        
        readv(a,n);
        set<int> vals;
        for(auto x : a) vals.insert(x);
        map<int, int> to;
        int m = 0;
        for(auto x : vals) to[x] = m++;
        st.build(n, 1, 0, m-1);
//        deque<int> ans;
        ll ans = 0;
        forn(i,0,n) {
            int v = to[a[i]];
            ans += min(st.get(1, 0, m-1, 0, v-1), st.get(1, 0, m-1, v+1, m-1));
//            if(st.get(1, 0, m-1, 0, v) < st.get(1, 0, m-1, v, m-1)) {
//                ans.push_front(a[i]);
//            }
//            else ans.pb(a[i]);
            st.update(1, 0, m-1, v, 1);
        }
//        forn(i,0,n) printf("%d ", ans[i]);
        printf("%lld\n", ans);
        
    }
    
    
}