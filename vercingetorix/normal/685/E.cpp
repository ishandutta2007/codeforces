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

const int A = 1000;
int d[A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    vpi e(m);
    forn(i,0,m) {
        scanf("%d %d", &e[i].first, &e[i].second);
        e[i].first--;
        e[i].second--;
    }
    vi l(q), r(q), s(q), t(q);
    vvi qn(m);
    forn(i,0,q) {
        scanf("%d %d %d %d", &l[i], &r[i], &s[i], &t[i]);
        l[i]--;
        r[i]--;
        s[i]--;
        t[i]--;
        qn[l[i]].pb(i);
    }
    forn(i,0,n) forn(j,0,n) d[i][j] = m+1;
    vi ans(q,0);
    for(int ts = m-1; ts>=0; ts--) {
        int u = e[ts].first;
        int v = e[ts].second;
        d[u][v] = ts;
        d[v][u] = ts;
        forn(i,0,n) {
            d[v][i] = d[u][i] = min(d[u][i], d[v][i]);
        }
        for(auto ind : qn[ts]) if(d[s[ind]][t[ind]] <= r[ind]) ans[ind] = 1;
    }
    forn(i,0,q) {
        if(ans[i]) printf("Yes\n");
        else printf("No\n");
    }
    
    
    
}