#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
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
const int N = 200100;
int remxor[N];
int xorcount[1<<14];
int good = 0;
int n,k,q,m;
int x[N];
int y[N];
const int A = 450;
const int B = N/A+1;
int cnt[2*B][1<<14];
int pref[2*B];

int curroffset = 0;
int totz = 0;

class seq_handler {
public:
    int len = 0;
    int znum = 0;
    bool simple = false;
    vi sv;
    int off = 0;
    int bnum = 0;
    seq_handler(const vi & a) {
        len = a.size();
        int cur = 0;
        for(auto x : a) {
            cur ^= x;
            if(cur == 0) znum++;
        }
        sv = a;
        if(len <= A) simple = true;
        else {
            off = curroffset;
            int fullpref = 0;
            int buckpref = 0;
            forn(i,0,a.size()) {
                if(i%A == 0) {
                    pref[curroffset] = fullpref;
                    curroffset++;
                    bnum++;
                    buckpref = 0;
                }
                buckpref ^= a[i];
                fullpref ^= a[i];
                cnt[curroffset-1][buckpref]++;
            }
        }
        totz += znum;
    }
    
    void shift(int p, int val) {
        if(len == 0) return;
        totz -= znum;
        if(simple) {
            sv[p] ^= val;
            znum = 0;
            int cur = 0;
            for(auto x : sv) {
                cur ^= x;
                if(cur == 0) znum++;
            }
        }
        else {
            int sb = p/A;
            forn(aft,sb+1,bnum) {
                znum -= cnt[off + aft][pref[off + aft]];
                pref[off + aft] ^= val;
                znum += cnt[off + aft][pref[off + aft]];
            }
            znum -= cnt[off + sb][pref[off + sb]];
            int cur = 0;
            forn(i,sb*A,min(len, sb*A+A)) {
                cur ^= sv[i];
                cnt[off + sb][cur] = 0;
            }
            sv[p] ^= val;
            cur = 0;
            forn(i,sb*A,min(len, sb*A+A)) {
                cur ^= sv[i];
                cnt[off + sb][cur]++;
            }
            znum += cnt[off + sb][pref[off + sb]];
        }
        totz += znum;
    }
};

void print_status() {
    if(good == 0) printf("-1\n");
    else printf("%d\n", m - totz);
}

vector<seq_handler> handlers;

void shiftx(int p, int v) {
    xorcount[remxor[p%k]]--;
    good = 0;
    remxor[p%k]^=v;
    xorcount[remxor[p%k]]++;
    if(xorcount[remxor[p%k]] == k) good = 1;
    if(p >= m) return;
    if(k==1) handlers[p].shift(0, v);
    else {
        y[p] ^= v;
        handlers[p%k].shift(p/k, v);
        if(p+1<m) {
            y[p+1] ^= v;
            handlers[(p+1)%k].shift((p+1)/k, v);
        }
    }
    
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %d", &n, &k, &q);
    m = n-k+1;
    readv(a,n);
    readv(b,n);
    forn(i,0,n) x[i] = a[i] ^ b[i];
    forn(i,0,n) {
        y[i] = x[i];
        if(i > 0) y[i] ^= x[i-1];
    }
    forn(r,0,k) {
        for(int i = r; i < n; i+=k) remxor[r] ^= x[i];
        xorcount[remxor[r]]++;
        if(xorcount[remxor[r]] == k) good = 1;
    }
    if(k==1) forn(i,0,m) handlers.emplace_back(vi(1, x[i]));
    else {
        forn(r,0,k) {
            vi ry;
            for(int i = r; i < m; i+=k) ry.pb(y[i]);
            handlers.emplace_back(ry);
        }
    }
    print_status();
    while(q--) {
        char c;
        while(1) {
            scanf("%c", &c);
            if(c=='a'||c=='b') break;
        }
        int p,v;
        scanf("%d %d", &p, &v);
        p--;
        if(c=='a') {
            shiftx(p, a[p]^v);
            a[p] = v;
        }
        else if(c=='b') {
            shiftx(p, b[p]^v);
            b[p] = v;
        }
        print_status();
    }
    
}