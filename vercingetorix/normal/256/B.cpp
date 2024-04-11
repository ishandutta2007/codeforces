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


ll c,n,x,y;
vll side;
vll corn;

ll get(ll m) {
    ll ret = 1 + 2*m*(m+1);
    for(auto l : side) {
        if(m > l) {
            ret -= (m-l)*(m-l);
        }
    }
    for(auto d : corn) {
        if(m > d + 1) {
            ll l = m-d-1;
            ret+=l*(l+1)/2;
        }
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>n>>x>>y>>c;
    x--; y--;
    side.pb(x);
    side.pb(y);
    side.pb(n-1-x);
    side.pb(n-1-y);
    for(auto i : {0,(int)n-1}) for(auto j: {0,(int)n-1}) corn.pb(abs(x-i)+abs(y-j));
    ll l = -1;
    ll r = 2e9+100;
    while(r-l > 1) {
        int m = (r+l)/2;
        if(get(m) >= c) r = m;
        else l = m;
    }
    cout<<r;
    
    
}