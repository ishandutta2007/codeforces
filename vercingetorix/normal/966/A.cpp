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
vi l, e;

int n,m,v;
const int INF = 1e9;

int ladder(int x1, int y1, int x2, int y2) {
    if(x1 == x2) return abs(y1-y2);
    if(l.empty()) return INF;
    auto it = lower_bound(all(l), min(y1,y2));
    int ret = INF;
    if(it!=l.end()) {
        ret = min(ret, abs(x1-x2) + abs(y1-*it) + abs(y2-*it));
    }
    if(it!=l.begin()) {
        it--;
        ret = min(ret, abs(x1-x2) + abs(y1-*it) + abs(y2-*it));
    }
    return ret;
}

int elev(int x1, int y1, int x2, int y2) {
    if(x1 == x2) return abs(y1-y2);
    if(e.empty()) return INF;
    auto it = lower_bound(all(e), min(y1,y2));
    int ret = INF;
    if(it!=e.end()) {
        ret = min(ret, (abs(x1-x2)+v-1)/v + abs(y1-*it) + abs(y2-*it));
    }
    if(it!=e.begin()) {
        it--;
        ret = min(ret, (abs(x1-x2)+v-1)/v + abs(y1-*it) + abs(y2-*it));
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int nl, ne;
    scanf("%d %d %d %d %d", &n, &m, &nl, &ne, &v);
    l.resize(nl);
    e.resize(ne);
    forn(i,0,nl) scanf("%d", &l[i]);
    forn(i,0,ne) scanf("%d", &e[i]);
    forn(i,0,nl) l[i]--;
    forn(i,0,ne) e[i]--;
    int q;
    scanf("%d", &q);
    int x1,y1,x2,y2;
    while(q--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--;y1--;x2--;y2--;
        printf("%d\n", min(elev(x1,y1,x2,y2),ladder(x1,y1,x2,y2)));
    }
    
    
}