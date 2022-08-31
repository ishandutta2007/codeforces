#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
typedef vector<vvll> vvvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const ll INF = 1e18;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vvll a(n, vll(m));
        forn(i,0,n) forn(j,0,m) scanf("%lld", &a[i][j]);
        forn(i,0,n) forn(j,0,m) a[i][j] -= i+j;
        vll to;
        forn(i,0,n) forn(j,0,m) to.pb(a[i][j]);
        int A = n*m;
        ll ans = INF;
        forn(pt,0,A) {
            vvll d(n, vll(m, INF));
            if(a[0][0] >= to[pt]) d[0][0] = a[0][0] - to[pt];
            forn(i,0,n) forn(j,0,m) {
                if(a[i][j] < to[pt]) continue;
                ll cur = a[i][j] - to[pt];
                if(i>0) d[i][j] = min(d[i][j], d[i-1][j] + cur);
                if(j>0) d[i][j] = min(d[i][j], d[i][j-1] + cur);
            }
            ans = min(ans, d[n-1][m-1]);
        }
        cout<<ans<<endl;
        
        
        
    }
    
}