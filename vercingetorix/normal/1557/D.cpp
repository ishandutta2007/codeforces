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
pi nil = mp(0,0);
class stree {
public:
    vpi t;
    vpi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vpi(n*4,nil);
            s = n;
        }
        if (tl == tr)
            t[v] = nil;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = nil;
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == nil) return;
        t[v] = pp[v];
        if(tl != tr) {
            pp[2*v] = pp[v];
            pp[2*v+1] = pp[v];
        }
        pp[v] = nil;
    }
    
    void update (int v, int tl, int tr, int l, int r, pi val) {
        if (l == tl && tr == r) {
            pp[v] = val;
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
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return nil;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        pi ret =  max(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = max(t[v*2], t[v*2+1]);
        return ret;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    set<int> compress;
    vi ind(m), l(m), r(m);
    forn(i,0,m) {
        scanf("%d %d %d", &ind[i], &l[i], &r[i]);
        compress.insert(l[i]);
        compress.insert(r[i]);
    }
    map<int, int> to;
    int A = 0;
    for(auto x : compress) to[x] = A++;
    stree st;
    st.build(A, 1, 0, A-1);
    vvpi seg(n+1);
    forn(i,0,m) {
        l[i] = to[l[i]];
        r[i] = to[r[i]];
        seg[ind[i]].pb(mp(l[i], r[i]));
    }
    vi prev(n+1);
    forn(i,1,n+1) {
        pi best = nil;
        for(auto x : seg[i]) best = max(best, st.get(1, 0, A-1, x.first, x.second));
        prev[i] = best.second;
        pi nb = mp(best.first + 1, i);
        for(auto x : seg[i]) st.update(1, 0, A-1, x.first, x.second, nb);
    }
    vi del(n+1, 1);
    pi best = st.get(1, 0, A-1, 0, A-1);
    printf("%d\n", n- best.first);
    int cur = best.second;
    while(cur != 0) {
        del[cur] = 0;
        cur = prev[cur];
    }
    forn(i,1,n+1) if(del[i]) printf("%d ", i);
    printf("\n");
    
}