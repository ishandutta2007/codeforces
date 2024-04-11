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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
class stree {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void push(int v) {
        if (t[v] != 0) {
            t[2*v]  += t[v];
            t[2*v+1] += t[v];
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += val;
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return get (v*2, tl, tm, pos);
        else
            return get (v*2+1, tm+1, tr, pos);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(q,m);
    if (n==1) {
        cout<<0;
        exit(0);
    }
    vi a;
    forn(i,0,n) a.pb(i);
    stree r,l;
    r.build(a, 1, 0, n-1);
    l.build(a, 1, 0, n-1);
    forn(i,0,m) {
        q[i]--;
        r.update(1, 0, n-1, 0, n-1, 1);
        if(q[i]>0) {
            int bl = -1;
            int br = q[i] - 1;
            while(br-bl > 1) {
                int bm = (bl+br)/2;
                if (r.get(1, 0, n-1, bm) < q[i]) bl = bm;
                else br = bm;
            }
            int bls = br;
            if (r.get(1, 0, n-1, bls) == q[i]) {
                bl = bls;
                br = q[i];
                while(br - bl > 1) {
                    int bm = (bl+br)/2;
                    if (r.get(1, 0, n-1, bm) == q[i]) bl = bm;
                    else br = bm;
                }
                int brs = bl;
                r.update(1, 0, n-1, bls, brs, -1);
            }
        }
        l.update(1, 0, n-1, 0, n-1, -1);
        if(q[i]<n-1) {
            int bl = q[i] + 1;
            int br = n;
            while(br-bl > 1) {
                int bm = (bl+br)/2;
                if (l.get(1, 0, n-1, bm) > q[i]) br = bm;
                else bl = bm;
            }
            int brs = bl;
            if (l.get(1, 0, n-1, brs) == q[i]) {
                br = brs;
                bl = q[i];
                while(br - bl > 1) {
                    int bm = (bl+br)/2;
                    if (l.get(1, 0, n-1, bm) == q[i]) br = bm;
                    else bl = bm;
                }
                int bls = br;
                l.update(1, 0, n-1, bls, brs, 1);
            }
        }
    }
    ll ans = 0;
    forn(i,0,n) {
        int pl = l.get(1, 0, n-1, i);
        int pr = r.get(1, 0, n-1, i);
        pl--;
        pr++;
        pl = max(pl,0);
        pr = min(pr,n-1);
        ans += pr-pl+1;
    }
    cout<<ans;
}