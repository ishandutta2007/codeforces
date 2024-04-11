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
const int N = 1000002;
pi q[N];
int pt = 0;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    vi sq(N+1,0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    sq[1] = 1;
    forn(i,2,N+1) {
        int m = i;
        int p = mindiv[m];
        int deg =1 ;
        m/=p;
        if(m%p == 0) sq[i] = sq[m/p];
        else sq[i] = sq[m]*p;
    }
    int n;
    read(n);
    readv(a,n);
    vi f;
    vpi e;
    for(auto x : a) {
        int y = sq[x];
        if(y == 1) {
            cout<<1;
            exit(0);
        }
        if(isp[y]) f.pb(y);
        else e.pb(mp(mindiv[y], y/mindiv[y]));
    }
    srt(f);
    srt(e);
    forn(i,1,f.size()) if(f[i] == f[i-1]) {
        cout<<2;
        exit(0);
    }
    forn(i,1,e.size()) if(e[i] == e[i-1]) {
        cout<<2;
        exit(0);
    }
    
    vvi g(N);
    for(auto x : e) {
        g[x.first].pb(x.second);
        g[x.second].pb(x.first);
    }
    const int INF = 1e9;
    int ans = INF;
    vi d(N, INF);
    for(auto s : pr) {
        if(s > 1000) break;
        for(auto x : pr) d[x] = INF;
        d[s] = 0;
        q[0] = mp(s,s);
        int pt = 1;
        forn(i,0,pt) {
            int v = q[i].first;
            for(auto u : g[v]) {
                if(u == q[i].second) continue;
                if(d[u] == INF) {
                    d[u] = d[v] + 1;
                    q[pt++] = mp(u, v);
                }
                else {
                    ans = min(ans, d[u] + d[v] + 1);
                }
            }
        }
        vi r(2, INF);
        for(auto x : f) {
            if(d[x] <= r[0]) {
                r[1] = r[0];
                r[0] = d[x];
            }
            else if(d[x] <= r[1]) r[1] = d[x];
        }
        ans = min(ans, r[0]+r[1] + 2);
    }
    if(ans == INF) ans = -1;
    cout<<ans;
    
    
    
}