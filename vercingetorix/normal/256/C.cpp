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
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair
const int A = 1e6;
class stree {
public:
    vi t;
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
            t[v] = t[v*2] ^ t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                 get (v*2, tl, tm, l, min(r,tm)) ^
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
            t[v] =  (t[v*2] ^ t[v*2+1]);
        }
    }
};

ll sq(ll x) {
    ll y = sqrt(x)-2;
    if(y<0) y = 0;
    while((y+1)*(y+1) <= x) y++;
    return y;
}

pi get(ll x) {
    int r = sq(x);
    ll l = sq(r);
    while(l*l*l*l < x) l++;
    if(r == x) r--;
    return mp((int)l, r);
}

vi gr(A);
const int B = 1010;
int mex[B][B];
int have[B][B];
int pt[B];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(m,1,A) {
        auto e = get(m);
        int l = e.first;
        int r = e.second;
        if(r>=l) gr[m] = mex[l][r];
        if(m < B) {
            forn(s,1,m+1) {
                have[s][gr[m]] = 1;
                while(have[s][pt[s]]) pt[s]++;
                mex[s][m] = pt[s];
            }
        }
    }
    int last = 0;
    int cnt = 0;
    vector<pair<pi, int>> simp;
    forn(i,0,A) {
        if(gr[i] == last) cnt++;
        else {
            simp.pb(mp(mp(i-cnt, i-1), last));
            last = gr[i];
            cnt = 1;
        }
    }
    simp.pb(mp(mp(A-cnt, A-1), last));
//    for(auto x: simp) cout<<x.first.first<<' '<<x.first.second<<' '<<x.second<<'\n';
//    forn(i,0,100000) if(gr[i]) cout<<i<<' '<<gr[i]<<'\n';
    stree st;
    st.build(gr, 1, 0, A-1);
    int n;
    read(n);
    readv(a,n);
    int ans = 0;
    for(auto x : a) {
        auto e = get(x);
        int l = e.first;
        int r = e.second;
        vi can(5,0);
        if(r>=l) {
            for(auto e2 : simp) {
                int l2 = e2.first.first;
                int r2 = e2.first.second;
                if(l2 > r || l > r2) continue;
                can[e2.second] = 1;
            }
        }
        int pt = 0;
        while(can[pt]) pt++;
        ans ^= pt;
    }
    if(ans == 0) cout<<"Rublo\n";
    else cout<<"Furlo\n";
    
}