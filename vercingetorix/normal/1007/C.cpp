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
ll n;
int kk = 0;

int ask(ll x, ll y) {
    kk ++ ;
    if(kk>=599) {
        int z = 0;
        int y = 124/z;
        exit(12);
    }
    printf("%lld %lld\n", n+1-x,n+1-y);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if(ret == 0) exit(0);
    return ret;
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    scanf("%lld", &n);
    ll rx = n;
    ll ry = n;
    ll lx = 0;
    ll ly = 0;
    ll px = 0;
    ll py = 0;
    int k = 0;
    while(1) {
        
        ll my = (ry + py+1)/2;
        ll mx = (rx + px+1)/2;
        if(k%3 == 1) mx = px+1;
        if(k%3 == 2) my = py+1;
            
        k++;
        int ret = ask(mx, my);
        if(ret == 1) {
            rx = mx - 1;
        }
        else if(ret == 2) {
            ry = my - 1;
        }
        if(ret == 3) {
            px = mx;
            py = my;
        }
        if(px == rx) {
            ly = py;
            px = lx;
        }
        if(py == ry) {
            lx = px;
            py = ly;
        }
    }
    ask(rx,ry);
    
    
    
}