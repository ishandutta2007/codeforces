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
class streemin {
public:
    vi t;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, INF);
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = min(t[v], val);
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return min(t[v], get (v*2, tl, tm, pos));
        else
            return min(t[v], get (v*2+1, tm+1, tr, pos));
    }
};

class streemax {
public:
    vi t;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, -INF);
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = max(t[v], val);
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return max(t[v], get (v*2, tl, tm, pos));
        else
            return max(t[v], get (v*2+1, tm+1, tr, pos));
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    readv(b,n);
    forn(i,0,n) a[i]--, b[i]--;
    swap(a,b);
    vi w(n);
    forn(i,0,n) w[a[i]] = i;
    streemax l;
    streemin r;
    l.build(n, 1, 0, n-1);
    r.build(n, 1, 0, n-1);
    forn(bp,0,n) {
        int i = w[b[bp]];
        int j = bp;
        if(i >= j) {
            r.update(1, 0, n-1, 0, i-j, i-j);
            l.update(1, 0, n-1, i-j, i, i-j);
            r.update(1, 0, n-1, i+1, n-1, n+i-j);
        }
        else {
            l.update(1, 0, n-1, 0, i, i-j);
            r.update(1, 0, n-1, i+1, n-(j-i), n-(j-i));
            l.update(1, 0, n-1, n-(j-i), n-1, n-(j-i));
        }
    }
    forn(i,0,n) {
        int cur = min(i-l.get(1, 0, n-1, i), r.get(1, 0, n-1, i) - i);
        printf("%d\n", cur);
    }
    
    
}