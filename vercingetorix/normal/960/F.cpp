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

const int A= 100500;
set<pi> best[A];
int ans = 0;

void add(int v, int to, int w) {
    auto it = best[v].lower_bound(mp(w,0));
    it--;
    pi cand = mp(w, it->second + 1);
    ans = max(ans, cand.second);
    it = best[to].lower_bound(mp(w, 0));
    it--;
    if(it->second >= cand.second) return;
    it++;
    vpi todel;
    while(it!=best[to].end() && it->second <= cand.second) {
        todel.pb(*it);
        it++;
    }
    for(auto x : todel) best[to].erase(x);
    best[to].insert(cand);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) best[i].insert(mp(-1, 0));
    
    forn(i,0,m) {
        int a,b,w;
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        add(a,b,w);
    }
    cout<<ans;
    
    
}