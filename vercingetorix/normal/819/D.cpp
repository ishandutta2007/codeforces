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
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t,n;
    scanf("%d %d", &t, &n);
    readv(a,n);
    ll sum = 0;
    vll st(n+1,0);
    forn(i,0,n) {
        sum += a[(i+1)%n];
        st[i+1] = sum;
    }
    int d = gcd(sum, t);
    ll istep = invmod(sum/d, t/d);
    map<int, vi> c;
    forn(i,0,n) c[st[i]%d].pb(i);
    vi ans(n, 0);
    for(auto u : c) {
        vpi cur;
        for(auto i : u.second) {
            cur.pb(mp(((st[i]%t)/d)*istep%(t/d), -i));
        }
        srt(cur);
        forn(i,0,cur.size()) {
            int len = cur[(i+1)%cur.size()].first - cur[i].first;
            if(len < 0) len += t/d;
            ans[-cur[i].second] = len;
        }
        if(cur.back().first == cur[0].first) ans[-cur.back().second] = t/d;
    }
    forn(i,0,n) printf("%d ", ans[i]);
    
    
}