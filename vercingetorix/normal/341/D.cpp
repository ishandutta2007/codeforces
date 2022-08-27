#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <array>
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
struct FT {
    vector<ll> s;
    FT(int n) : s(n, 0) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < s.size(); pos |= pos + 1) s[pos] ^= dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res ^= s[pos-1];
        return res;
    }
};

struct FT2 {
    vector<vi> ys; vector<FT> ft;
    FT2(int limx) : ys(limx) {}
    void fakeUpdate(int x, int y) {
        for (; x < ys.size(); x |= x + 1) ys[x].push_back(y);
    }
    void init() {
        for (vi& v : ys) sort(all(v)), ft.emplace_back(v.size());
    }
    int ind(int x, int y) {
        return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
    void update(int x, int y, ll dif) {
        for (; x < ys.size(); x |= x + 1)
            ft[x].update(ind(x, y), dif);
    }
    ll query(int x, int y) {
        ll sum = 0;
        for (; x; x &= x - 1)
            sum ^= ft[x-1].query(ind(x-1, y));
        return sum;
    }
};
const int N = 502;
struct BIT2 {
    ll BIT[N+1][N+1];
    void update(int x, int y, ll val)
    {
        for (; x <= N; x += (x & -x))
        {
            for (; y <= N; y += (y & -y))
                BIT[x][y] ^= val;
        }
        return;
    }
    
    int query(int x, int y)
    {
        int sum = 0;
        
        for(; x > 0; x -= x&-x)
        {
            for(; y > 0; y -= y&-y)
            {
                sum ^= BIT[x][y];
            }
        }
        return sum;
    }
};

int lowbit(int i) {
    return i&-i;
}

struct BIT3 {
//    ll B[N][N];
    vvll B= vvll(N, vll(N,0));
    void update(int x, int y, ll v) {
        for(int i = x ; i <= N ; i += lowbit(i)) {
            for(int j = y ; j <= N ; j += lowbit(j)) {
                B[i][j] ^= v;
            }
        }
    }
    ll query(int x, int y) {
        ll ans = 0;
        for(int i = x ; i > 0 ; i -= lowbit(i)) {
            for(int j = y ; j > 0 ; j -= lowbit(j)) {
                ans ^= B[i][j];
            }
        }
        return ans;
    }
};

struct FT24 {
    FT2 f[2][2];
    FT24(int limx) : f{{(limx+1)/2, (limx+1)/2}, {(limx+1)/2,(limx+1)/2}} {};
    void fakeUpdate(int x, int y) {
        f[x&1][y&1].fakeUpdate(x/2, y/2);
    }
    void init() {
        forn(i,0,2) forn(j,0,2) f[i][j].init();
    }
    
    void update(int x, int y, ll dif) {
        f[x&1][y&1].update(x/2, y/2, dif);
    }
    ll query(int x, int y) {
        return f[x&1][y&1].query(x/2, y/2);
    }
};

struct BIT24 {
    BIT3 f[2][2];
//    FT24(int limx) : f{{(limx+1)/2, (limx+1)/2}, {(limx+1)/2,(limx+1)/2}} {};
//    void fakeUpdate(int x, int y) {
//        f[x&1][y&1].fakeUpdate(x/2, y/2);
//    }
//    void init() {
//        forn(i,0,2) forn(j,0,2) f[i][j].init();
//    }
    
    void update(int x, int y, ll dif) {
//        cout<<"U "<<x<<' '<<y<<' '<<dif<<endl;
        f[x&1][y&1].update(x/2+1, y/2+1, dif);
    }
    ll query(int x, int y) {
//        cout<<"Q "<<x<<' '<<y<<'\n';
//        cout<< f[x&1][y&1].query(x/2+1, y/2+1)<<'\n';
        return f[x&1][y&1].query(x/2+1, y/2+1);
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi tp(m), x0(m), x1(m), y0(m), y1(m);
    vll v(m,0);
    forn(i,0,m) {
        scanf("%d %d %d %d %d", &tp[i], &x0[i], &y0[i], &x1[i], &y1[i]);
        x0[i]--;
        x1[i]--;
        y0[i]--;
        y1[i]--;
        if(tp[i] == 2) scanf("%lld", &v[i]);
    }
    BIT24 fen;
//    FT24 fen(n);
//    forn(i,0,m) if(tp[i] ){
//        fen.fakeUpdate(x1[i], y1[i]);
//        if(x0[i] > 0) {
//            fen.fakeUpdate(x0[i] - 1, y1[i]);
//        }
//        if(y0[i] > 0) {
//            fen.fakeUpdate(x1[i], y0[i] - 1);
//        }
//        if(x0[i] > 0 && y0[i] > 0) {
//            fen.fakeUpdate(x0[i] - 1, y0[i] - 1);
//        }
//    }
//    fen.init();
    forn(i,0,m) {
        if(tp[i] == 2) {
            fen.update(x0[i], y0[i], v[i]);
            if(x1[i] < n-1) {
                fen.update(x1[i] + 1, y0[i], v[i]);
            }
            if(y1[i] < n-1) {
                fen.update(x0[i], y1[i] + 1, v[i]);
            }
            if(x1[i] < n-1 && y1[i] < n-1) {
                fen.update(x1[i] + 1, y1[i] + 1, v[i]);
            }
        }
        else {
            ll ans = fen.query(x1[i], y1[i]);
            if(x0[i] > 0) {
                ans ^= fen.query(x0[i] - 1, y1[i]);
            }
            if(y0[i] > 0) {
                ans ^= fen.query(x1[i], y0[i] - 1);
            }
            if(x0[i] > 0 && y0[i] > 0) {
                ans ^= fen.query(x0[i] - 1, y0[i] - 1);
            }
            printf("%lld\n", ans);
        }
    }
    
    
    
}