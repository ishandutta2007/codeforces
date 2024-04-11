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
const int INF = 1e9;
class streemax {
public:
    vpi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = mp(a[tl], tl);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return mp(-INF, 0);
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
            t[v] = mp(new_val, tl);
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

class streemin {
public:
    vpi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = mp(a[tl], tl);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return mp(INF, 0);
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  min(
                    get (v*2, tl, tm, l, min(r,tm)),
                    get (v*2+1, tm+1, tr, max(l,tm+1), r)
                    );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = mp(new_val, tl);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  min(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,a,b;
        scanf("%d %d %d", &n, &a, &b);
        readv(p,n);
        --a; --b;
        vi d(n, INF);
        vi tol;
        forn(i,0,n) tol.pb(i-p[i]);
        tol[a] = INF;
        d[a] = 0;
        streemin stl;
        stl.build(tol, 1, 0, n-1);
        
        vi tor;
        forn(i,0,n) tor.pb(i+p[i]);
        tor[a] = -INF;
        streemax str;
        str.build(tor, 1, 0, n-1);
        vi q(1, a);
        int pt = 0;
        while(pt < q.size()) {
            int v = q[pt++];
            int l = v+1;
            int r = min(v + p[v], n-1);
            while(1) {
                auto cur = stl.get(1, 0, n-1, l, r);
                if(cur.first > v) break;
                int u = cur.second;
                stl.update(1, 0, n-1, u, INF);
                str.update(1, 0, n-1, u, -INF);
                d[u] = d[v] + 1;
                q.pb(u);
            }
            l = max(0, v-p[v]);
            r = v-1;
            while(1) {
                auto cur = str.get(1, 0, n-1, l, r);
                if(cur.first < v) break;
                int u = cur.second;
                stl.update(1, 0, n-1, u, INF);
                str.update(1, 0, n-1, u, -INF);
                d[u] = d[v] + 1;
                q.pb(u);
            }
        }
        printf("%d\n", d[b]);
    }
    
    
    
    
}