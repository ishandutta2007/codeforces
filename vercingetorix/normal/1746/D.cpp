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
const int A =200500;
vi ch[A];
vi s;

pll dfs(int v, ll k) {
    pll ret = mp(s[v]*k, s[v]*(k+1));
    int l = ch[v].size();
    if(l == 0) return ret;
    ll mk = k/l;
    vll up;
    ll add = 0;
    for(auto u : ch[v]) {
        auto cur = dfs(u, mk);
        add += cur.first;
        up.pb(cur.second - cur.first);
    }
    srtrev(up);
    forn(i,0,k%l) add += up[i];
    ret.first += add;
    ret.second += add + up[k%l];
    return  ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n, k;
        scanf("%d %d", &n, &k);
        forn(i,1,n) {
            int par;
            read(par);
            ch[par-1].pb(i);
        }
        readv(ss,n);
        s = ss;
        printf("%lld\n", dfs(0, k).first);
        forn(i,0,n) ch[i].clear();
    }
    
    
}