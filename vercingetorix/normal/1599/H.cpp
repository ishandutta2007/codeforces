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

int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main()
{
#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
    const int A = 8;
#else
    const int A = 1000000000;
#endif
    
    ll dl = ask(1,1) + 2;
    ll ur = A*2 - ask(A, A);
    ll xpy = dl + ur;
    ll ul = A-1-ask(1, A);
    ll dr = ask(A,1) - A + 1;
    ll ymx = ul + dr;
    ll y2 = (xpy + ymx)/2;
    ll x2 = (xpy-ymx)/2;
    ll xl = 1 + ask(1, y2/2);
    ll xr = x2 - xl;
    ll yd = 1 + ask(x2/2, 1);
    ll yu = y2 - yd;
    printf("! %lld %lld %lld %lld", xl, yd, xr, yu);
    
    
}