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
const ll INF = 2e18;
#ifdef LOCAL
ll d[1<<5];
#else
ll d[1<<20];
#endif
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d[0] = 0;
    int n,m,b;
    scanf("%d %d %d", &m, &n, &b);
    vector<pair<int, pi>> f;
    forn(i,0,m) {
        int x,k,num;
        int skill = 0;
        scanf("%d %d %d", &x, &k, &num);
        while(num--) {
            int task;
            scanf("%d", &task);
            skill |= 1<<(task-1);
        }
        f.pb(mp(k, mp(x, skill)));
    }
    srt(f);
    forn(i,0,1<<n) d[i] = INF;
    d[0] = 0;
    int curk = 0;
    ll ans = INF;
    for(auto fr : f) {
        int x = fr.second.first;
        int mplus = fr.second.second;
        curk = fr.first;
        forn(mask,0,1<<n) d[mask|mplus] = min(d[mask|mplus], d[mask] + x);
        ans = min(ans, d[(1<<n)-1] + ll(b)*curk);
    }
    if(ans == INF) ans = -1;
    cout<<ans;
    
    
}