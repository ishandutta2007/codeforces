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

const long long mod = 998244353;
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
};
const int N = 2001;
ll nfac[N];
ll d[N][N];
stree a,b,c;
int ina[N];
int inb[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    nfac[0] = 1;
    forn(i,1,N) nfac[i] = nfac[i-1]*i%mod;
    d[0][0] = 1;
    forn(n,1,N) {
        d[n][0] = nfac[n];
        forn(k,1,n+1) {
            d[n][k] = (n-k)*d[n-1][k-1] % mod;
            if(k >= 2) d[n][k] = (d[n][k]+(k-1)*d[n-1][k-2])%mod;
        }
    }
    int n;
    scanf("%d", &n);
    vvi x(n, vi(n));
    forn(i,0,n) forn(j,0,n) {
        scanf("%d", &x[i][j]);
        x[i][j]--;
    }
    ll ans = 0;
    a.build(vi(n,1), 1, 0, n-1);
    forn(j,0,n) {
        ans = ans * (n-j) % mod;
        ans += a.get(1, 0, n-1, 0, x[0][j] - 1);
        a.update(1, 0, n-1, x[0][j], 0);
    }
    forn(i,1,n) {
        forn(j,0,n) {
            ina[j] = 1;
            inb[j] = 1;
        }
        ans = ans * d[n][n] % mod;
        ll cur = 0;
//        a.build(vi(n,1), 1, 0, n-1);
        b.build(vi(n,1), 1, 0, n-1);
        c.build(vi(n,1), 1, 0, n-1);
        int cn = n;
        int ck = n;
        forn(j,0,n) {
            int u = x[i-1][j];
            int v = x[i][j];
            int k = b.get(1, 0, n-1, 0, v-1);
            int f = c.get(1, 0, n-1, 0, v-1);
            if(inb[u]) {
                if(u<=v) {
                    k--;
                    f--;
                }
                if(f>0) cur = (cur + f*d[cn-1][ck-2])%mod;
                cur = (cur+(k-f)*d[cn-1][ck-1]) % mod;
            }
            else {
                if(f>0) cur = (cur + f*d[cn-1][ck-1])%mod;
                cur = (cur+(k-f)*d[cn-1][ck]) % mod;
            }
            cn--;
            ina[u] = 0;
            if(inb[u]) {
                c.update(1, 0, n-1, u, 0);
                ck--;
            }
            inb[v] = 0;
            b.update(1, 0, n-1, v, 0);
            if(ina[v]) {
                c.update(1, 0, n-1, v, 0);
                ck--;
            }
            
        }
        ans = (ans+cur)%mod;
    }
    cout<<ans;
    
    
}