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

const long long mod = 998244353 ;
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
int d[1<<10][50500];
int rot[10];

void ap(int & x, int y) {
    x+=y;
    if(x >= mod) x-= mod;
}
int sm[10];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n;
    cin>>m;
    forn(i,0,m) {
        int u,v;
        cin>>u>>v;
        rot[u] |= (1<<v);
        rot[v] |= (1<<u);
    }
    forn(i,0,10) sm[i] = (1<<i)-1;
    d[0][0] = 1;
    forn(pos,0,n) {
        forn(mask,0,1<<10) {
            forn(nx,0,10) {
                int nmask = (1<<nx)|(mask&rot[nx]);
                if((nmask&sm[nx]) == 0) ap(d[nmask][pos+1], d[mask][pos]);
            }
        }
    }
    ll ans = 0;
    forn(mask,0,1<<10) ans += d[mask][n];
    cout<<ans%mod;
    
    
    
}