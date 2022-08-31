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

int n,u,r;
const int A = 31;
ll a[A+1][A];
int op[A];
ll b[A];
ll p[A];
ll k[A];
ll ans = -1e18;

void go(int pos) {
    if(pos%2 == u%2) {
        ll cand = 0;
        forn(i,0,n) cand += a[pos][i]*ll(k[i]);
        ans = max(ans, cand);
    }
    if(pos<u) {
        forn(i,0,n) {
            a[pos+1][i] = a[pos][p[i]] + r;
        }
        op[pos] = 0;
        go(pos+1);
        if(pos == 0 || op[pos-1] != 1) {
            op[pos] = 1;
            forn(i,0,n) a[pos+1][i] = a[pos][i]^b[i];
            go(pos+1);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>n>>u>>r;
    forn(i,0,n) cin>>a[0][i];
    forn(i,0,n) cin>>b[i];
    forn(i,0,n) cin>>k[i];
    forn(i,0,n) cin>>p[i];
    forn(i,0,n) p[i]--;
    go(0);
    cout<<ans;
    
}