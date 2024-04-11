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
    int n;
    read(n);
    vvi g(2*n);
    forn(i,0,2*n) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi vis(2*n, 0);
    ll ans = 0;
    forn(sta,0,2*n) if(vis[sta] == 0) {
        vis[sta] = 1;
        vi c;
        c.pb(sta);
        int cur = g[sta][0];
        while(1) {
            vis[cur] = 1;
            c.pb(cur);
            int pt = 0;
            if(vis[g[cur][pt]]) pt++;
            if(vis[g[cur][pt]]) break;
            cur = g[cur][pt];
        }
//        for(auto x : c) cout<<x<<' '; cout<<'\n';
        int l = c.size();
        forn(s,0,l) {
            int t = s;
            int nl = n-1;
            int xl = 0;
            int nr = 2*n-1;
            int xr = n;
            int vb1 = c[(s+l-1)%l];
            forn(len,1,l+(s==0)) {
                int v = c[t];
                if(v<n) {
                    nl = min(nl, v);
                    xl = max(xl, v);
                }
                else {
                    nr = min(nr, v);
                    xr = max(xr, v);
                }
                t++;
                if(t == l) t = 0;
                int vb2 = c[t];
                int bad = 0;
                int lu = n;
                int ld = -1;
                int ru = 2*n;
                int rd = n-1;
                if(len!=l) for(auto ban : {vb1, vb2}) {
                    if(ban < n) {
                        if(ban < nl) ld = max(ld, ban);
                        else if(ban > xl) lu = min(lu, ban);
                        else bad = 1;
                    }
                    else {
                        if(ban < nr) rd = max(rd, ban);
                        else if(ban > xr) ru = min(ru, ban);
                        else bad = 1;
                    }
                }
                if(bad) continue;
                ans += ll(len/2)*(lu-xl)*(nl-ld)*(ru-xr)*(nr-rd);
            }
        }
    }
    cout<<ans;
    
    
}