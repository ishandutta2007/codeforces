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

int rev2(int x) {
    int ret = ll(x)*3/2+3;
    while(ret-1-(ret-1)/3 >= x) ret--;
    return ret;
}

int grd(int a, int b) {
    if(a > 0 && b > 0) return 0;
    else if(a != 1 && b != 1) return 1;
    else return 2;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,p;
    cin>>n>>p;
    vpi q;
    q.pb(mp(1,0));
    q.pb(mp(3,1));
    int rn = 3;
    int cur = 1;
    int p1 = 0;
    int p2 = 0;
    while(rn < p) {
        int nx1 = q[p1+1].first*3;
        int nx2 = rev2(q[p2+1].first);
        int nx = min(nx1,nx2);
        if(nx == nx1) p1++;
        if(nx == nx2) p2++;
        int ng = grd(q[p1].second, q[p2].second);
        rn  = nx;
        if(ng != cur) {
            cur = ng;
            q.pb(mp(rn, cur));
        }
    }
    if(q.back().first >= p) q.back().first = p;
    else q.pb(mp(p,0));
    vll cnt(3,0);
    forn(i,0,q.size() - 1) {
        int l =  q[i].first;
        int r = q[i+1].first-1;
        ll w = ll(2*p-l-r)*(r-l+1)/2 % mod;
        cnt[q[i].second] += w;
    }
//    for(auto x : cnt) cout<<x<<' ';
    forn(i,0,3) cnt[i]%=mod;
    vll d(4,0);
    d[0] = 1;
    forn(i,0,n) {
        vll nd(4,0);
        forn(was,0,4) forn(tk,0,3) {
            nd[was^tk] = (nd[was^tk] + d[was]*cnt[tk])%mod;
        }
        d= nd;
    }
    cout<<(d[1]+d[2]+d[3])%mod;
    exit(0);

    
    
    
}