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
class stree {
public:
    vll t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t = vll(4*n, 0);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void push(int v) {
        if (t[v] != 0) {
            t[2*v] += t[v];
            t[2*v+1] += t[v];
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += val;
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    ll get (int v, int tl, int tr, int pos) {
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
const int A = 300100;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
vvpi g;

vi lev, par, val;
vi tin;
vi tout;
int curt = 0;

void dfs(int v, int p, int l, int xval) {
    par[v] = p;
    tin[v] = curt++;
    lev[v] = l;
    val[v] = xval;
    for(auto x : g[v]) {
        if(x.first != p) {
            dfs(x.first, v, l+1, xval^x.second);
        }
    }
    tout[v] = curt-1;
}
stree st;
int un = 1;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d\n", &n, &q);
    vi u(q), v(q), x(q);
    g = vvpi (n);
    forn(i,0,n) make_set(i);
    vi ans(q,0);
    forn(i,0,q) {
        scanf("%d %d %d", &u[i], &v[i], &x[i]);
        u[i]--; v[i]--;
        if(find_set(u[i]) != find_set(v[i])) {
            g[u[i]].pb(mp(v[i], x[i]));
            g[v[i]].pb(mp(u[i], x[i]));
            union_sets(u[i], v[i]);
            ans[i] = 1;
        }
    }
    lev.resize(n);
    tin.resize(n);
    tout.resize(n);
    par = vi(n, -1);
    val.resize(n);
    forn(i,0,n) if(par[i] == -1) {
        dfs(i, i, 0, 0);
    }
    st.build(n, 1, 0, n-1);
    forn(i,0,q) {
//        forn(j,0,n) printf("%d ", st.get(1, 0, n-1, tin[j])); printf("\n");
        if(ans[i] == 1) {
            printf("YES\n");
            continue;
        }
        if(st.get(1, 0, n-1, tin[u[i]]) != st.get(1, 0, n-1, tin[v[i]])) {
            printf("NO\n");
            continue;
        }
        if(val[u[i]]^val[v[i]]^x[i] != 1) {
            printf("NO\n");
            continue;
        }
        int a = u[i];
        int b = v[i];
        vi atc;
        vi btc;
        while(lev[a] > lev[b]) {
            atc.pb(a);
            a = par[a];
        }
        while(lev[a] < lev[b]) {
            btc.pb(b);
            b = par[b];
        }
        while(a != b) {
            btc.pb(b);
            b = par[b];
            atc.pb(a);
            a = par[a];
        }
        reverse(all(btc));
        reverse(all(atc));
        for(auto ver : atc) st.update(1, 0, n-1, tin[ver], tout[ver], gen()%(mod*100310));
        for(auto ver : btc) st.update(1, 0, n-1, tin[ver], tout[ver], gen()%(mod*100310));
        printf("YES\n");
        
    }
    
    
    
}