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
#include <array>
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
const int INF = 5e7;
struct sega {
    array<array<int, 21>, 4> d;
    sega(int x = 0) {
        forn(i,0,4) {
            forn(j,0,21) d[i][j] = 0;
            d[i][1] = x;
        }
        if(x < 0) d[0][1] = 0;
    }
};

sega combine(const sega & a, const sega & b) {
    sega ret;
    forn(i,0,4) forn(j,1,21) ret.d[i][j] = -INF;
    for(auto tl : {0,1}) for(auto tr : {0,2}) {
        forn(tm,0,2) {
            int kl = tl|(tm*2);
            int kr = tr|(tm);
            int pl = 1;
            int pr = 1;
            int cur = 0;
            int pm = 0;
            if(kl) {
                pm++;
                cur += a.d[kl][pl++];
            }
            if(kr) {
                pm++;
                cur += b.d[kr][pr++];
            }
            if(tm) pm--;
            ret.d[tl|tr][pm] = max(ret.d[tl|tr][pm], cur);
            while(pm < 20) {
                pm++;
                if(a.d[kl][pl] > b.d[kr][pr] && a.d[kl][pl] >= 0) {
                    cur += a.d[kl][pl++];
                }
                else if(a.d[kl][pl] <= b.d[kr][pr] && b.d[kr][pr] >= 0) {
                    cur += b.d[kr][pr++];
                }
                ret.d[tl|tr][pm] = max(ret.d[tl|tr][pm], cur);
            }
        }
    }
    ret.d[0][1] = max(ret.d[0][1], ret.d[0][0]);
    forn(i,0,4) {
        forn(j,1,20) {
            ret.d[i][j+1] = max(ret.d[i][j+1], ret.d[i][j]);
        }
    }
    forn(i,0,4) {
        for(int j = 20; j>=1; j--) ret.d[i][j] -= ret.d[i][j-1];
    }
    return ret;
};

class stree {
public:
    vector<sega> t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = sega(a[tl]);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    sega get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return sega();
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  combine(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = sega(new_val);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
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
    stree st;
    st.build(a, 1, 0, n-1);
    int m;
    read(m);
    while(m--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 0) {
            int pos, val;
            scanf("%d %d", &pos, &val);
            pos--;
            st.update(1, 0, n-1, pos, val);
        }
        else {
            int l,r,k;
            scanf("%d %d %d", &l, &r, &k);
            l--; r--;
            auto ret = st.get(1, 0, n-1, l, r);
            int ans = 0;
            forn(i,1,k+1) {
                if(ret.d[0][i] > 0) ans += ret.d[0][i];
            }
            printf("%d\n", ans);
        }
    }
    
    
}