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

const long long mod = 998244353 ;
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
    vll k;
    vll b;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            k = vll(n*4,1);
            b = vll(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
            if(t[v] >= mod) t[v] -= mod;
        }
    }
    
    void push(int v, int tl, int tr) {
        if(k[v] == 1 && b[v] == 0) return;
        if(tl != tr) {
            b[2*v+1] = (k[v]*b[2*v+1] + b[v])%mod;
            k[2*v+1] = k[2*v+1]*k[v]%mod;
            b[2*v] = (k[v]*b[2*v] + b[v])%mod;
            k[2*v] = k[v*2]*k[v]%mod;
        }
        t[v] = (t[v]*k[v] + b[v]*(tr-tl+1))%mod;
        k[v] = 1;
        b[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int kn, int bn) {
        if (l == tl && tr == r) {
            push(v,tl,tr);
            k[v] = kn;
            b[v] = bn;
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
            update (v*2, tl, tm, l, min(r,tm), kn, bn);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, kn, bn);
            t[v] = t[v*2] + t[v*2+1];
            if(t[v] >= mod) t[v] -= mod;
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  (get(v*2, tl, tm, l, min(r,tm))+ get(v*2+1, tm+1, tr, max(l,tm+1), r));
        if(ret>=mod) ret-=mod;
        t[v] = t[v*2] + t[v*2+1];
        if(t[v] >= mod) t[v] -= mod;
        return ret;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d", &m);
    const int n = 300500;
    stree st;
    st.build(n, 1, 0, n-1);
    ll d3 = 1;
    forn(i,0,m) {
        int  l, r;
        scanf("%d %d", &l, &r);
        if(i == 0) {
            st.update(1, 0, n-1, l, r, 0, 1);
            continue;
        }
        st.update(1, 0, n-1, 0, l-1, 2, 0);
        st.update(1, 0, n-1, r+1, n-1, 2, 0);
        st.update(1, 0, n-1, l, r, 0, 2*d3%mod);
        d3 = d3*3%mod;
    }
    cout<<st.get(1, 0, n-1, 0, n-1);
    
    
}