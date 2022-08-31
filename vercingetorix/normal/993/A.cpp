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
    vi x(8);
    vi y(8);
    forn(i,0,8) scanf("%d %d", &x[i], &y[i]);
    int bad = 0;
    int cur = 1;
    forn(i,4,8) {
        if(x[i] <= max(x[0],x[2])) cur = 0;
    }
    bad |= cur;
    cur = 1;
    forn(i,4,8) {
        if(y[i] <= max(y[0],y[2])) cur = 0;
    }
    bad |= cur;
    cur = 1;
    forn(i,4,8) {
//        int cur = 1;
        if(x[i] >= min(x[0],x[2])) cur = 0;
//        bad |= cur;
    }
    bad |= cur;
    cur = 1;
    forn(i,4,8) {
//        int cur = 1;
        if(y[i] >= min(y[0],y[2])) cur = 0;
//        bad |= cur;
    }
    bad |= cur;
    cur = 1;
    forn(i,0,4) {
//        int cur = 1;
        if(x[i] + y[i] >= min(x[4] + y[4], x[6] + y[6])) cur = 0;
//        bad |= cur;
    }
    bad |= cur;
    cur = 1;
    forn(i,0,4) {
//        int cur = 1;
        if(x[i] + y[i] <= max(x[4] + y[4], x[6] + y[6])) cur = 0;
//        bad |= cur;
    }
    bad |= cur;
    cur = 1;
    forn(i,0,4) {
//        int cur = 1;
        if(x[i] - y[i] >= min(x[4] - y[4], x[6] - y[6])) cur = 0;
//        bad |= cur;
    }
    bad |= cur;
    cur = 1;
    forn(i,0,4) {
//        int cur = 1;
        if(x[i] - y[i] <= max(x[4] - y[4], x[6] - y[6])) cur = 0;
//        bad |= cur;
    }
    bad |= cur;
    cur = 1;
    if(bad) printf("NO\n");
    else printf("YES\n");
    
}