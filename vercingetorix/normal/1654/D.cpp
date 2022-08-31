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
const int A = 200500;
int touch[A];
vi touched;
int vis[A];

vector<vector<pair<int, pi>>> g;
int md[A];
int cur[A];
ll nfac[A];
ll ifac[A];
ll in[A];
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
void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

ll ans = 0;
ll cand = 1;
ll qdiv = 1;

void rem(int p) {
    cand = cand*in[p]%mod;
    cur[p]++;
    if(touch[p] == 0) {
        touch[p] = 1;
        touched.pb(p);
    }
    if(cur[p] > md[p]) {
        qdiv = qdiv*p%mod;
        md[p] = cur[p];
    }
}

void add(int p) {
    cand = cand*p%mod;
    cur[p]--;
    if(touch[p] == 0) {
        touch[p] = 1;
        touched.pb(p);
    }
}

const int N = 200100;
int mindiv[A];

void dfs(int v) {
    vis[v] = 1;
    ans = (ans + cand)%mod;
    for(auto u : g[v]) {
        if(vis[u.first] == 0) {
            int p,q;
            p = u.second.first;
            q = u.second.second;
            while(q>1) {
                add(mindiv[q]);
                q/=mindiv[q];
            }
            while(p>1) {
                rem(mindiv[p]);
                p/=mindiv[p];
            }
            dfs(u.first);
            p = u.second.first;
            q = u.second.second;
            while(p>1) {
                add(mindiv[p]);
                p/=mindiv[p];
            }
            while(q>1) {
                rem(mindiv[q]);
                q/=mindiv[q];
            }
        }
    }
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        g.resize(n);
        forn(i,0,n-1) {
            int u,v,p,q;
            scanf("%d %d %d %d", &u, &v, &p, &q);
            u--; v--;
            g[u].pb(mp(v, mp(p,q)));
            g[v].pb(mp(u, mp(q,p)));
        }
        forn(i,0,n) vis[i] = 0;
        ans = 0;
        cand = 1;
        qdiv = 1;
        dfs(0);
        printf("%lld\n", ans*qdiv%mod);
        
        g.clear();
        for(auto x : touched) {
            touch[x] = 0;
            cur[x] = 0;
            md[x] = 0;
        }
        touched.clear();
    }
    
    
}