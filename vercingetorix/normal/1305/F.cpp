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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // PRIMES
    const int N = 1000000;
    vi mindiv(N+1, 0);
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
    int n;
    read(n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    //    forn(i,0,n) {
    //        a.pb(gen()%(1000000ll*1000000) + 1);
    //    }
    srt(a);
    ll ans = n;
    ll l = max(1ll,a[0]-n+1);
    ll r = a[0] + n - 1;
    vll tp;
    vll d;
    for(ll i = l; i <= r; i++) d.pb(i);
    for(auto p : pr) {
        ll f = ((l+p-1)/p)*p;
        if(f<=r) tp.pb(p);
        int indf = int(f-l);
        for(int i = indf; i < d.size(); i += p) {
            while(d[i] % p == 0) d[i] /= p;
        }
    }
    for(auto x : d) if(x!=1) tp.pb(x);
    
    
    for(auto x : tp) {
        ll cand = 0;
        forn(i,0,n) {
            if(x>a[i]) {
                cand += x-a[i];
            }
            else {
                ll l = a[i]%x;
                cand += min(l, x-l);
            }
            if(cand >= ans) break;
        }
        ans = min(ans, cand);
    }
    cout<<ans;
    
}