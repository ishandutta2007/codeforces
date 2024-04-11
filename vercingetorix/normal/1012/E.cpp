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
vvpi g;
const int N = 200500;
int ato[N];
int bto[N];

vpi st;
vpi cyc;
vvi ss;

void cpr(vi & x) {
    printf("%d\n", x.size());
    for(auto y : x) printf("%d ", y+1);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,s;
    scanf("%d %d", &n, &s);
    readv(a,n);
    vi b = a;
    srt(b);
    g.resize(n);
    vpi nx(n);
    forn(i,0,n) nx[i] = mp(i,-1);
    forn(i,0,n) {
        int v = lower_bound(all(b), b[i])-b.begin();
        int u = lower_bound(all(b), a[i])-b.begin();
        ato[i] = u;
        bto[i] = v;
        if(u!=v)
        g[v].pb(mp(u,i));
    }
    int need = 0;
    forn(i,0,n) {
        if(g[i].size() > 0) {
            st.pb(g[i].back());
            g[i].pop_back();
            while(!st.empty()) {
                int v = st.back().first;
                if(g[v].empty()) {
                    cyc.pb(st.back());
                    st.pop_back();
                }
                else {
                    st.pb(g[v].back());
                    g[v].pop_back();
                }
            }
//            cout<<cyc.size();
            ss.pb(vi());
            for(auto x : cyc) ss.back().pb(x.second);
            reverse(all(ss.back()));
            need += cyc.size();
            cyc.clear();
        }
    }
    if(need>s) {
        printf("-1\n");
        exit(0);
    }
    if(ss.size() <= 1 || s - need < 2) {
        printf("%d\n", ss.size());
        for(auto x : ss) {
            cpr(x);
        }
        exit(0);
    }
    int un = min((int)ss.size(), s - need);
    printf("%d\n", (int)ss.size() - un + 2);
    while(ss.size() > un) {
        cpr(ss.back());
        ss.pop_back();
    }
    vi big, rev;
    for(auto x : ss) {
        for(auto y : x) big.pb(y);
        rev.pb(x[0]);
    }
    cpr(big);
    reverse(all(rev));
    cpr(rev);
    
}