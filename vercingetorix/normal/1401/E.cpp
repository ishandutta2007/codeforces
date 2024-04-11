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
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
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
    
    int getr(int v, int tl, int tr, int k) {
        if(t[v] < k) return tr+1;
        if(tl==tr) return tl;
        int tm = (tl+tr)/2;
        if(t[v*2] >= k) return getr(v*2, tl, tm, k);
        else return getr(v*2+1,tm+1,tr,k-t[v*2]);
    }
};
const int N = 1000000;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    stree st;
    st.build(vi(N+1,0), 1, 0, N);
    int n,m;
    scanf("%d %d", &n, &m);
    ll ans = 1;
    vpi ev;
    forn(i,0,n) {
        int y,lx,rx;
        scanf("%d %d %d", &y, &lx, &rx);
        if(lx == 0 && rx == N) ans++;
        ev.pb(mp(lx, y));
        ev.pb(mp(rx+1,-y));
    }
    vector<pair<int, pi>> q;
    forn(i,0,m) {
        int x,ly,ry;
        scanf("%d %d %d", &x, &ly, &ry);
        if(ly == 0 && ry == N) ans++;
        q.pb(mp(x, mp(ly,ry)));
    }
    srt(q);
    srt(ev);
    int pt = 0;
    for(auto a : q) {
        int x = a.first;
        while(pt<ev.size() && ev[pt].first <= x) {
            if(ev[pt].second > 0) st.update(1, 0, N, ev[pt].second, 1);
            else st.update(1, 0, N, -ev[pt].second, 0);
            pt++;
        }
        ans += st.get(1, 0, N, a.second.first, a.second.second);
    }
    cout<<ans;
    
    
}