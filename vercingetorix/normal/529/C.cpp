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
            return -1;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                 get (v*2, tl, tm, l, min(r,tm)),
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
const int INF = 200500;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vvi rows(n);
    vvi cols(m);
    forn(i,0,k) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--; y--;
        rows[x].pb(y);
        cols[y].pb(x);
    }
    vi x1(q),y1(q),x2(q),y2(q);
    forn(i,0,q) scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    forn(i,0,q) {
        x1[i]--;
        y1[i]--;
        x2[i]--;
        y2[i]--;
    }
    vi can(q, 0);
    forn(i,0,n) {
        srt(rows[i]);
        rows[i].pb(m);
    }
    forn(i,0,m) {
        srt(cols[i]);
        cols[i].pb(n);
    }
    vi init;
    stree st;
    vi pt;
    vvi ev;
    vvi evq;
    
    forn(i,0,n) init.pb(rows[i][0]);
    
    st.build(init, 1, 0, n-1);
    pt = vi(n, 0);
    ev = vvi(m);
    evq = vvi(m);
    forn(i,0,q) evq[y1[i]].pb(i);
    forn(i,0,n) forn(j,0,rows[i].size() - 1) ev[rows[i][j]].pb(i);
    
    forn(s,0,m) {
        for(auto ind : evq[s]) {
            if(st.get(1, 0, n-1, x1[ind], x2[ind]) <= y2[ind]) can[ind] = 1;
        }
        for(auto i : ev[s]) {
            pt[i]++;
            st.update(1, 0, n-1, i, rows[i][pt[i]]);
        }
    }
    
    swap(n,m);
    forn(i,0,q) {
        swap(x1[i], y1[i]);
        swap(x2[i], y2[i]);
    }
    swap(rows, cols);
    
    init.clear();
    forn(i,0,n) init.pb(rows[i][0]);

    st.build(init, 1, 0, n-1);
    pt = vi(n, 0);
    ev = vvi(m);
    evq = vvi(m);
    forn(i,0,q) evq[y1[i]].pb(i);
    forn(i,0,n) forn(j,0,rows[i].size() - 1) ev[rows[i][j]].pb(i);
    
    forn(s,0,m) {
        for(auto ind : evq[s]) {
            if(st.get(1, 0, n-1, x1[ind], x2[ind]) <= y2[ind]) can[ind] = 1;
        }
        for(auto i : ev[s]) {
            pt[i]++;
            st.update(1, 0, n-1, i, rows[i][pt[i]]);
        }
    }
    forn(i,0,q) {
        if(can[i]) printf("YES\n");
        else printf("NO\n");
    }
    
    
}