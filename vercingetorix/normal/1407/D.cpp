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

const int A = 300500;
vi g[A];


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    set<pi> q;
    forn(i,0,n) {
        while(!q.empty() && q.begin()->first < a[i]) q.erase(q.begin());
        if(!q.empty()) g[q.begin()->second].pb(i);
        if(!q.empty() && q.begin()->first == a[i]) q.erase(q.begin());
        q.insert(mp(a[i], i));
    }
    forn(i,0,n) a[i] = -a[i];
    q.clear();
    forn(i,0,n) {
        while(!q.empty() && q.begin()->first < a[i]) q.erase(q.begin());
        if(!q.empty()) g[q.begin()->second].pb(i);
        if(!q.empty() && q.begin()->first == a[i]) q.erase(q.begin());
        q.insert(mp(a[i], i));
    }
    q.clear();
    for(int i = n-1; i>=0; i--) {
        while(!q.empty() && q.begin()->first < a[i]) q.erase(q.begin());
        if(!q.empty()) g[i].pb(q.begin()->second);
        if(!q.empty() && q.begin()->first == a[i]) q.erase(q.begin());
        q.insert(mp(a[i], i));
    }
    forn(i,0,n) a[i] = -a[i];
    q.clear();for(int i = n-1; i>=0; i--) {
        while(!q.empty() && q.begin()->first < a[i]) q.erase(q.begin());
        if(!q.empty()) g[i].pb(q.begin()->second);
        if(!q.empty() && q.begin()->first == a[i]) q.erase(q.begin());
        q.insert(mp(a[i], i));
    }
    vi dist(n, A);
    dist[n-1] = 0;
    for(int i = n-2; i>=0; i--) {
        for(auto j : g[i]) dist[i] = min(dist[i], dist[j] + 1);
    }
    cout<<dist[0];
}