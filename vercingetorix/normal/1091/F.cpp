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
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
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
    scanf("%d", &n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    forn(i,0,n) a[i] *= 2;
    char c[100500];
    scanf("\n%s", c);
//    vi wtl(n,0);
//    int cur =0;
//    if(c[0] == 'W') cur=1;
//    forn(i,1,n) {
//        wtl[i] = cur;
//        if(c[i] == 'W') cur = 1;
//    }
//    ll el = 0;
//    for(int i = n-1; i >= 0; i--) {
//
//    }
    ll fow = 0;
    ll w = 0;
    ll fog = 0;
    ll s = 0;
    ll fol = 0;
    int water = 0;
    ll nrg = 0;
    forn(i,0,n) {
        if(c[i] == 'L') fol+=a[i];
        else if(c[i] =='W') fow+=a[i];
        else if(c[i] == 'G') fog+=a[i];
        if(c[i] == 'W') water = 1;
        nrg -= a[i];
        if(nrg < 0) {
            ll decfow = min(fow, -nrg/2);
            nrg += 2*decfow;
            fow -= decfow;
            s += decfow;
            ll decfog = min(fog, -nrg/2);
            nrg += 2*decfog;
            fog -= decfog;
            w += decfog;
            if(water) {
                s -= nrg;
                nrg = 0;
            }
            else {
                w -= nrg;
                nrg = 0;
            }
        }
    }
    
    ll ans = w*5 + s*3 + fow+fol+fog;
    cout<<ans/2;
}