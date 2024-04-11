#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

int d,n;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d\n", &d, &n);
    vi a;
    vpi b;
    char c[20];
    forn(i,0,n) {
        scanf("%s", c);
        int cur =0 ;
        int cnt = 0;
        forn(j,0,d) {
            if(c[j] == '1') {
                cur|= 1<<j;
                cnt++;
            }
        }
        b.pb(mp(cnt+1, cur));
    }
    srtrev(b);
    for(auto x : b) a.pb(x.second);
    g.resize(n);
    forn(i,0,n) forn(j,0,n) {
        if(i!=j && (a[i]&a[j])==a[i]) g[i].pb(j);
    }
    mt.assign (n, -1);
    for (int v=0; v<n; ++v) {
        used.assign (n, false);
        try_kuhn (v);
    }
    vi to(n,-1);
    vi beg(n, 1);
    for (int i=0; i<n; ++i)
        if (mt[i] != -1) {
            to[mt[i]] = i;
            beg[i] = 0;
        }
    vector<char> ans;
    forn(i,0,n) {
        if(beg[i]) {
            if(!ans.empty()) ans.pb('R');
            int was = 0;
            int cur = i;
            while(cur != -1) {
                int tk = a[cur]^was;
                forn(j,0,d) if(tk &(1<<j)) ans.pb('0'+j);
                was = a[cur];
                cur = to[cur];
            }
        }
    }
    printf("%d\n", ans.size());
    for(auto cc : ans) printf("%c ", cc);
    
    
}