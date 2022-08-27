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

const long long mod = 998244353 ;
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
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
//            t.resize(n * 4);
            t = vi(n*4,-1);
            s = n;
        }
        if (tl == tr)
            t[v] = -1;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = -2;
        }
    }
    
    void push(int v) {
        if (t[v] != -2) {
            t[2*v] = t[v];
            t[2*v+1] = t[v];
            t[v] = -2;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
//        if(v==1) printf("set %d %d to %d\n", l, r, val);
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = val;
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return get (v*2, tl, tm, pos);
        else
            return get (v*2+1, tm+1, tr, pos);
    }
    
};

vvi chb, cha;
int ans;
int cur;
vi ordb;
vi rb;
vi to;
stree st;
int n;

void fp() {
    forn(i,0,n) printf("%d ", st.get(1, 0, n-1, i));
    printf("\n");
}

void dfsb(int v) {
    ordb.pb(v);
    for(auto u : chb[v]) dfsb(u);
    rb[v] = ordb.back();
}

int getcol(int v) {
//    fp();
    return st.get(1, 0, n-1, to[v]);
}

void unbid(int v) {
    st.update(1, 0, n-1, to[v], to[rb[v]], -1);
//    fp();
//    printf("unbid %d\n", v);
}

void bid(int v) {
    st.update(1, 0, n-1, to[v], to[rb[v]], v);
//    fp();
//    printf("bid %d\n", v);
}

void dfsa(int v) {
    int del = getcol(v);
//    printf("got %d from %d\n", del, v);
    if (del != -1) {
        cur--;
        unbid(del);
    }
    bid(v);
    cur++;
    ans = max(ans, cur);
    for(auto u : cha[v]) {
        dfsa(u);
    }
    cur--;
    unbid(v);
    if(del != -1) {
        cur++;
        bid(del);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        read(n);
        cha = vvi(n);
        chb = vvi(n);
        readv(a,n-1);
        readv(b,n-1);
        forn(i,0,n-1) {
            a[i]--;
            b[i]--;
            cha[a[i]].pb(i+1);
            chb[b[i]].pb(i+1);
        }
        ordb.clear();
        rb= vi(n,0);
        dfsb(0);
        st.build(n, 1, 0, n-1);
        to = vi(n);
        forn(i,0,n) to[ordb[i]] = i;
        ans = 0;
        cur = 0;
        dfsa(0);
        printf("%d\n", ans);
    }
    
}