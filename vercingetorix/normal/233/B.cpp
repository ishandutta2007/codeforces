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
    ll n;
    cin>>n;
    const ll INF = 1e18;
    ll ans = INF;
    auto check = [&](ll x) {
        if(x<0) return;
        ll sx = 0;
        ll m = x;
        while(m>0) {
            sx+=m%10;
            m/=10;
        }
        if(x*x+sx*x == n) {
            ans = min(ans, x);
        }
    };
    forn(sx,1,101) {
        ll d = 4*n+sx*sx;
        ll k = sqrt(d) - 2;
        if(k < 0) k = 0;
        forn(it,0,5) if(k*k != d) k++;
        if(k*k==d) {
            check((-sx+k)/2);
        }
    }
    if (ans == INF) ans= -1;
    cout<<ans;
    
}