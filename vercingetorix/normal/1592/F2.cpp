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

int nn, k;
vvi g;

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
vvi a;
int n,m;
int acount() {
    int ret = 0;
    forn(i,0,n) forn(j,0,m) {
        int cur = a[i][j];
        if(i<n-1) cur^=a[i+1][j];
        if(j<m-1) cur^=a[i][j+1];
        if(i<n-1&&j<m-1) cur^=a[i+1][j+1];
        if(cur) ret++;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    a.resize(n);
    char c[1000];
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,m) {
            if(c[j] == 'W') a[i].pb(0);
            else a[i].pb(1);
        }
    }
    int did = 0;
    int ans = 0;
    vi bi, bj;
    forn(i,1,n) if((a[i-1][m-1] ^ a[i][m-1]) == 1) bi.pb(i);
    forn(j,1,m) if((a[n-1][j-1] ^ a[n-1][j]) == 1) bj.pb(j);
    nn = bi.size();
    k = bj.size();
    g.resize(nn);
    forn(i1,0,nn) forn(j1,0,k) {
        int i = bi[i1];
        int j = bj[j1];
        if((a[i-1][j-1]^a[i-1][j]^a[i][j-1] ^a[i][j]) == 1) g[i1].pb(j1);
    }
    
    mt.assign (k, -1);
    for (int v=0; v<nn; ++v) {
        used.assign (nn, false);
        try_kuhn (v);
    }
    
    for (int j1=0; j1<k; ++j1)
        if (mt[j1] != -1) {
            int j = bj[j1];
            int i = bi[mt[j1]];
            ans += 2;
//            printf("a was %d\n", acount());
            forn(p,i,n) forn(q,j,m) a[p][q] ^= 1;
//            printf("a now %d\n", acount());
//            printf ("%d %d\n", mt[i]+1, i+1);
        }
    did = 0;
//    cout<<ans<<endl;
    forn(i,1,n) forn(j,1,m) {
        if(did) break;
        if(a[n-1][m-1] + (a[i-1][m-1] ^ a[i][m-1]) + (a[n-1][j] ^ a[n-1][j-1]) + (a[i-1][j-1]^a[i-1][j]^a[i][j-1] ^a[i][j]) >= 3) {
            did = 1;
            ans+=2;
//            printf("a was %d\n", acount());
            forn(p,i,n) forn(q,j,m) a[p][q] ^= 1;
//            printf("a now %d\n", acount());
        }
    }
//    cout<<ans<<endl;
    forn(i,0,n) forn(j,0,m) {
        int cur = a[i][j];
        if(i<n-1) cur^=a[i+1][j];
        if(j<m-1) cur^=a[i][j+1];
        if(i<n-1&&j<m-1) cur^=a[i+1][j+1];
        if(cur) ans++;
    }
    cout<<ans;
    
    
    
}