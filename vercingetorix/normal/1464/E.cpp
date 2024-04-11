#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <queue>
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

const long long mod = 998244353;
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
vvi g;
vi gr;
vi has(100500, 0);
void dfs(int v) {
    if(gr[v] >= 0) return;
    for(auto u : g[v]) {
        dfs(u);
    }
    for(auto u : g[v]) has[gr[u]] = 1;
    int pt = 0;
    while(has[pt]) pt++;
    gr[v] = pt;
    for(auto u : g[v]) {
        has[gr[u]] = 0;
    }
}
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
vvll A;
vi ord;
vll B;
int mx = 0;
void gauss() {
    forn(j,0,mx) {
        int pt = j;
        while(A[pt][j] == 0) pt++;
        swap(A[j], A[pt]);
        swap(B[j], B[pt]);
        swap(ord[j], ord[pt]);
        ll c = invmod(A[j][j], mod);
        forn(i,j,mx) A[j][i] = A[j][i]*c%mod;
        B[j] = B[j]*c%mod;
        forn(i,0,mx) {
            if(i==j) continue;
            forn(k,j+1,mx) {
                A[i][k] = (A[i][k] + (mod - A[i][j]) * A[j][k]) % mod;
            }
            B[i] = (B[i] + (mod - A[i][j]) * B[j]) % mod;
            A[i][j] = 0;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    gr = vi(n, -1);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].pb(v);
    }
    forn(i,0,n) dfs(i);
    forn(i,0,n) mx= max(mx, gr[i]);
    int l = 1;
    while(mx>=l) l*=2;
    mx = l;
    vi cnt(mx, 0);
    forn(i,0,n) cnt[gr[i]]++;
    A = vvll(mx, vll(mx, 0));
    B = vll(mx, 0);
    forn(i,0,mx) ord.pb(i);
    
    ll in1 = invmod(n+1, mod);
    B[0] = in1;
    forn(i,0,mx) A[i][i] = 1;
    forn(st,0,mx) if(cnt[st] > 0) {
        ll c = (mod-cnt[st])*in1 % mod;
        forn(i,0,mx) A[i][i^st] += c;
    }
    forn(i,0,mx) forn(j,0,mx) A[i][j]%=mod;
    vvll wa = A;
    vll wb = B;
    gauss();
    cout<<(1+mod-B[0] * invmod(A[0][0], mod) % mod)%mod<<endl;
}