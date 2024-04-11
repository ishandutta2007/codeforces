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

ll dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vi x(n);
    vi y(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    vi ax,ay;
    for(auto xx : x) ax.pb(xx);
    for(auto yy : y) ay.pb(yy);
    srt(ax);
    srt(ay);
    vi xm, ym;
    forn(i,0,n) {
        if(x[i] == ax[0] || x[i] == ax.back() || y[i] == ay[0] || y[i] == ay.back()) {
            xm.pb(x[i]);
            ym.pb(y[i]);
        }
    }
    ll a3 = 0;
    ll a4 = 0;
    forn(i,0,n) a4 += dist(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    forn(i,0,n) {
        forn(j1,0,xm.size()) {
            forn(j2,j1+1,xm.size()) {
                a3 = max(a3, dist(x[i],y[i],xm[j1],ym[j1]) + dist(x[i],y[i],xm[j2],ym[j2]) + dist(xm[j1],ym[j1],xm[j2],ym[j2]));
            }
        }
    }
    printf("%lld", a3);
    forn(i,4,n+1) printf(" %lld", a4);
    
    
}