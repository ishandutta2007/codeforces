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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vvi to(n);
    forn(i,0,m) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--; b--;
//        if(b < a) b+=n;
        to[a].pb(b);
        to[a].pb(b+n);
    }
    int mx =0;
    forn(i,0,n) {
        srt(to[i]);
        mx = max(mx, (int)to[i].size()/2);
    }
    vll ans(n, ll(n)*(mx-1));
//    int xt = 0;
    vi xt(n,0);
    forn(i,0,n) {
        if(to[i].size() == 2*mx) {
//            xt = max(xt, to[i][0]);
            int pt = 0;
            while(to[i][pt] < i) pt++;
            int ito = to[i][pt];
            forn(s,0,n) {
//                xt[s] = max(xt[s], to[i][pt] - s);
                if(s<=i) xt[s] = max(xt[s], ito - s);
                else xt[s] = max(xt[s], ito+n-s);
            }
        }
        else if(to[i].size() == 2*mx-2 && mx > 1) {
            int pt = 0;
            while(to[i][pt] < i) pt++;
            int ito = to[i][pt];
            forn(s,0,n) {
                if(s > i) xt[s] = max(xt[s], ito - s);
                xt[s] = max(xt[s], ito - s -n);
            }
        }
    }
    forn(i,0,n) printf("%lld ", ans[i] + xt[i]);
    
    
}