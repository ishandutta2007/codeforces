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

int par[20][300500];
int a[300500];
int c[300500];
int lev[300500];

int geth(int v) {
    for(int l = 19; l>=0; l--) if(a[par[l][v]] > 0) v = par[l][v];
    return v;
}

int getnext(int v, int p) {
    for(int l = 19; l>=0; l--) if(lev[par[l][v]] > lev[p]) v = par[l][v];
    return v;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d %d %d", &q, &a[0], &c[0]);
    lev[0] = 0;
    par[0][0] = 0;
    forn(i,1,q+1) {
        int tp;
        scanf("%d", &tp);
        if(tp == 1) {
            scanf("%d %d %d", &par[0][i], &a[i], &c[i]);
            forn(l,1,20) par[l][i] = par[l-1][par[l-1][i]];
            lev[i] = lev[par[0][i]] + 1;
        }
        else {
            int v,w;
            scanf("%d %d", &v, &w);
            int p = geth(v);
            int bought = 0;
            ll cost = 0;
            while(w > 0) {
                ll tk = min(w, a[p]);
                cost += tk*c[p];
                bought += tk;
                a[p] -= tk;
                w-=tk;
                if(p==v) break;
                p = getnext(v, p);
            }
            printf("%d %lld\n", bought, cost);
            fflush(stdout);
        }
    }
    
    
    
    
}