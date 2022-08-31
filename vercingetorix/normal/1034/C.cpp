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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
vvi g;
vi a;

int can = 1;
vi divs;
const int N = 1000010;
//const int N = 100;
ll st[N];
int parts[N];
ll cnt[N];
ll s = 0;
void dfs(int v, int p) {
    st[v] = a[v];
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u,v);
        st[v] += st[u];
    }
    ll d = gcd(st[v], s);
    ll sd =  s/ d;
    if(sd < N) {
//        if(s%st[v] == 0) if(s/st[v] < N) parts[s/st[v]]++;
        parts[sd]++;
    }
    
}
vi mindiv(N+1, 0);
vector<ll> pr;

vi getalldivs(int m) {
    if(m==1) return vi(1,1);
    int p = mindiv[m];
    int deg = 1;
    m/=p;
    while(mindiv[m] == p) {
        deg++;
        m/=p;
    }
    vi ret = getalldivs(m);
    int dp = p;
    int k = ret.size();
    forn(f,0,deg) {
        forn(i,0,k) ret.pb(ret[i]*dp);
        dp*=p;
    }
    return std::move(ret);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
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
//    auto x  = getalldivs(60);
    int n;
    read(n);
    a.resize(n);
    g.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n-1) {
        int u;
        scanf("%d", &u);
        int v = i+1;
        u--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i,0,n) s+=a[i];
    dfs(0,0);
    ll ans = 1;
    cnt[1] = 1;
    forn(m,2,N) {
        int pt = 0;
//        for(int k = 1; k*k<=m; k++) {
        for(auto k : getalldivs(m)) {
//            if(m%k==0) {
                if(k<m) cnt[m] += cnt[k];
                pt += parts[k];
//                if(k*k<m) {
//                    cnt[m] += cnt[k];
//                    pt += parts[k];
//                }
//            }
        }
        if(pt < m) cnt[m] = 0;
        else {
//            cnt[m]++;
            cnt[m]%=mod;
            ans += cnt[m];
        }
    }
    cout<<ans%mod;
//    for(int k = 1; k )
    
    
}