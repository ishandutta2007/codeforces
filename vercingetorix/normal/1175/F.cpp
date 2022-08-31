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

pi combine(const pi & a, const pi & b) {
    if(a.first == b.first) return mp(a.first, a.second+b.second);
    else return min(a,b);
}
const int INF = 1e9;

class stree {
public:
    vpi t;
    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = mp(0,1);
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v].first += pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return mp(INF,0);
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        pi ret =  combine(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = combine(t[v*2], t[v*2+1]);
        return ret;
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
    forn(i,0,n) a[i]--;
    vi w(n+1, n);
    int r = n-1;
    ll ans = 0;
    stree st;
    st.build(n, 1, 0, n-1);
    for(int l = n-1; l>=0; l--) {
        while(w[a[l]] <= r) r--;
        if(w[a[l]+1] <= r) {
            if(w[a[l]] > w[a[l]+1]) st.update(1, 0, n-1, w[a[l]+1], w[a[l]]-1, -1);
        }
        w[a[l]] = l;
        if(a[l] > 0) st.update(1, 0, n-1, l, w[a[l]-1]-1, 1);
        auto cur = st.get(1, 0, n-1, l, r);
        if(cur.first == 0) ans += cur.second;
    }
    cout<<ans;
    
    
}