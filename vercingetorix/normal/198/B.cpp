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
    int n,k;
    scanf("%d %d\n", &n, &k);
    char c[100500];
    vs a;
    forn(fa,0,2) {
        scanf("%s",c);
        a.pb(string(c));
    }
    int l = n;
    n = 2*n+1;
    vvi g(n);
    forn(sd,0,2) {
        forn(i,0,l) if(a[sd][i] == '-') {
            if(i+k >= l) {
                g[2*i+sd].pb(n-1);
            }
            else {
                if(a[sd^1][i+k] == '-') g[2*i+sd].pb(2*(i+k)+1-sd);
                if(a[sd][i+1] == '-') g[2*i+sd].pb(2*i+2+sd);
                if(i>0 && a[sd][i-1] == '-') g[2*i+sd].pb(2*i-2+sd);
            }
        }
    }
    int s = 0;
    const int INF = 1e9;
    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    priority_queue < pair<int,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second,  cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        if(v/2 < cur_d) continue;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j];
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push (make_pair (-d[to], to));
            }
        }
    }
    if(d[n-1] == INF) printf("NO\n");
    else printf("YES\n");
    
    
}