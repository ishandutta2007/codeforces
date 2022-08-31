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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

class stree {
public:
    vll t;
    int s;
    void build (int n) {
        t = vll(4*n, 0);
        s= n;
    }
    
    void update (int v, int tl, int tr, int l, int r, ll add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += add;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        }
    }
    
    ll get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    readv(a, n);
    vi l(m), r(m), d(m);
    forn(i,0,m) {
        scanf("%d %d %d", &l[i], &r[i], &d[i]);
        l[i]--;
        r[i]--;
    }
    stree sto;
    sto.build(m);
    forn(i,0,k) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--; y--;
        sto.update(1, 0, m-1, x, y, 1);
    }
    stree fin;
    fin.build(n);
    forn(i,0,m) {
        ll num = sto.get(1, 0, m-1, i);
        num *= d[i];
        fin.update(1, 0, n-1, l[i], r[i], num);
    }
    forn(i,0,n) printf("%lld ", fin.get(1, 0, n-1, i) + a[i]);
    
}