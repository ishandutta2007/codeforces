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
vpi q;
vll sx, py;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi x(n), y(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        q.pb(mp(y[i]-x[i], i));
    }
    srt(q);
    sx.resize(n);
    py.resize(n);
    ll sum = 0;
    forn(i,0,n) {
        sum += y[q[i].second];
        py[i] = sum;
    }
    sum = 0;
    for(int i = n-1; i>=0; i--) {
        sum += x[q[i].second];
        sx[i] = sum;
    }
    vll ans(n,0);
    forn(i,0,n) {
        int pt = lower_bound(all(q), mp(y[i]-x[i], 0)) - q.begin();
        if(pt < n) ans[i] += sx[pt] + ll(n-pt)* y[i];
        if(pt>0) ans[i] += py[pt-1] + ll(pt) * x[i];
        ans[i] -= x[i]+y[i];
    }
    forn(i,0,m) {
        int k,l;
        scanf("%d %d", &k, &l);
        k--; l--;
        ll points = min(x[k] + y[l], y[k] + x[l]);
        ans[k] -= points;
        ans[l] -= points;
    }
    forn(i,0,n) printf("%lld ", ans[i]);
    
}