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
    int n;
    read(n);
    vi x(n), y(n);
    forn(i,0,n) scanf("%d %d", &x[i], &y[i]);
    vpi q;
    forn(i,0,n) q.pb(mp(x[i]-y[i], i));
    srt(q);
    vi lx(n), lmn(n);
    forn(i,0,n) {
        lx[i] = x[q[i].second] + y[q[i].second];
        lmn[i] = x[q[i].second] + y[q[i].second];
        if(i>0) lx[i] = max(lx[i], lx[i-1]);
        if(i>0) lmn[i] = min(lmn[i], lmn[i-1]);
    }
    vi rx(n), rmn(n);
    for(int i = n-1; i>=0; i--) {
        rx[i] = x[q[i].second] + y[q[i].second];
        rmn[i] = x[q[i].second] + y[q[i].second];
        if(i<n-1) rx[i] = max(rx[i], rx[i+1]);
        if(i<n-1) rmn[i] = min(rmn[i], rmn[i+1]);
    }
    
    double al = 0;
    double ar = 1e9;
    const int INF = 2e9+5000;
    while(ar-al > 1e-7) {
        double m = (ar+al)/2;
        int l = 0;
        int r = 1;
        while(r < n && q[r].first - q[l].first < 2*m) r++;
        int can = 0;
        if(r==n) can = 1;
        else
        while(1) {
            int mx = -INF;
            int mn = INF;
            if(l>0) {
                mx = max(mx, lx[l-1]);
                mn = min(mn, lmn[l-1]);
            }
            if(r < n) {
                mx = max(mx, rx[r]);
                mn = min(mn, rmn[r]);
            }
            if(mx - mn < 2*m) {
                can = 1; break;
            }
            if(l == n-1) break;
            l++;
            while(r < n && q[r].first - q[l].first < 2*m) {
                r++;
            }
        }
        if(can) ar = m;
        else al = m;
        
    }
    printf("%.10lf", al);
    
    
}