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
int n,l;
vll a;
template <typename T>
vector<double> solve(T shift) {
    forn(i,0,n) a.pb(a[i] + 2*l);
    vector<pair<T, int>> ev;
    forn(i,0,2*n) {
        if(a[i]-shift <= 2*l) ev.pb(mp(max(T(0), T(a[i] -shift)), 1));
        if(a[i] <= 2*l) ev.pb(mp(T(a[i]), -1));
    }
    ev.pb(mp(2*l, 0));
    T last = 0;
    vd ans(n+1,0);
    srt(ev);
    int sum = 0;
    for(auto x : ev) {
        ans[sum] += x.first - last;
        sum += x.second;
        last = x.first;
    }
    forn(i,0,n+1) ans[i]/=2*l;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int v1,v2;
    scanf("%d %d %d %d", &n, &l, &v1, &v2);
    a.resize(n);
    readv(b,n);
    forn(i,0,n) a[i] = b[i];
    ll p = ll(l)*v2;
    vd ans;
    if(p%(v1+v2) == 0) ans = solve<int> (p/(v1+v2));
    else ans = solve<double>(double(p)/(v1+v2));
    forn(i,0,n+1) printf("%.12lf\n", ans[i]);
    
    
}