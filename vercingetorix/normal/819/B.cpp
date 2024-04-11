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

class stree {
public:
    vll t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
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
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += val;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
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

stree m, k;
int n;
void upd(int l, int r, int kk, int mm) {
    m.update(1, 0, n-1, l, r, mm);
    k.update(1, 0, n-1, l, r, kk);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    readv(p,n);
    forn(i,0,n) p[i] --;
    m.build(vi(n,0), 1, 0, n-1);
    k.build(vi(n,0), 1, 0, n-1);
    forn(i,0,n) {
        if(p[i] >= i) {
            upd(0,p[i]-i,-1,p[i]-i);
            upd(p[i]-i+1,n-1-i, 1, -(p[i]-i));
            upd(n-i,n-1, -1, p[i]+n-i);
        }
        else {
            upd(0,n-i-1,1,i-p[i]);
            upd(n-i,n-i+p[i], -1, n-i+p[i]);
            upd(n-i+p[i]+1,n-1, 1,-n+i-p[i]);
        }
    }
    pll ans(ll(n)*n, 0);
    forn(i,0,n) {
        pll cand = mp(m.get(1, 0, n-1, i)+k.get(1, 0, n-1, i)*ll(i),(ll) i);
        ans = min(ans,cand);
    }
    cout<<ans.first<<' '<<ans.second;
    
}