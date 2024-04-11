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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(x,m);
    forn(i,0,m) x[i]--;
    vi pl(n,0);
    vi pr(n,0);
    vvi g(n);
    ll def = 0;
    int tot = m-1;
    forn(i,1,m) {
        int l = x[i-1];
        int r = x[i];
        if(l==r) {
            tot--;
            continue;
        }
        def += abs(l-r);
        if(l>r) swap(l,r);
        pl[l]++;
        pr[r]++;
        if(l!=r) {
            g[l].pb(r);
            g[r].pb(l);
        }
    }
    forn(i,1,n) pr[i] += pr[i-1];
    for(int i =n-2;i>=0;i--) pl[i]+=pl[i+1];
    forn(i,0,n) {
        int off = 0;
        if(i<n-1) off+=pl[i+1];
        if(i>0) off+=pr[i-1];
        ll ans = def - (tot-off-g[i].size());
        for(auto j : g[i]) {
            ans -= abs(i-j);
            if(j < i) ans += j+1;
            else ans += j;
        }
        printf("%lld ", ans);
        
    }
    
    
}