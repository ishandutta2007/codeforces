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

const long long mod = 1000000000;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vll f(101);
    f[0] = 1;
    f[1] = 1;
    forn(i,2,101) f[i] = (f[i-1]+f[i-2])%mod;
    int n,m;
    scanf("%d %d", &n, &m);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,m) {
        int t,x,y;
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1) a[x-1] = y;
        else if(t==2) {
            x--; y--;
            ll ans = 0;
            forn(j,0,y-x+1) ans += (f[j]*ll(a[x+j]))%mod;
            printf("%lld\n", ans%mod);
        }
    }
}