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
const ll INF = 1e18;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        readv(cost,n);
        vvi room(n);
        room[0].pb(0);
        room[n-1].pb(m-1);
        vi a(k), b(k), c(k), d(k), h(k);
        forn(i,0,k) {
            scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &h[i]);
            a[i] --;
            b[i]--;
            c[i]--;
            d[i]--;
            room[a[i]].pb(b[i]);
            room[c[i]].pb(d[i]);
        }
        vector<vvi> to(n);
        vvll ans(n);
        
        forn(i,0,n) {
            srt(room[i]);
            room[i].erase(unique(all(room[i])), room[i].end());
            to[i].resize(room[i].size());
            ans[i] = vll(room[i].size(), -INF);
        }
        ans[0][0] = 0;
        forn(i,0,k) {
            int pos = lower_bound(all(room[a[i]]), b[i]) - room[a[i]].begin();
            to[a[i]][pos].pb(i);
        }
        forn(lev,0,n) {
            int l = room[lev].size();
            forn(i,1,l) ans[lev][i] = max(ans[lev][i], ans[lev][i-1] - ll(room[lev][i] - room[lev][i-1]) * cost[lev]);
            for(int i = l-2; i>=0; i--) {
                ans[lev][i] = max(ans[lev][i], ans[lev][i+1] - ll(room[lev][i+1] - room[lev][i]) * cost[lev]);
            }
            forn(i,0,l) {
                if(ans[lev][i] == -INF) continue;
                for(auto ind : to[lev][i]) {
                    int npos = lower_bound(all(room[c[ind]]), d[ind]) - room[c[ind]].begin();
                    ans[c[ind]][npos] = max(ans[c[ind]][npos], ans[lev][i] + h[ind]);
                }
            }
        }
        if(ans[n-1].back() == -INF) printf("NO ESCAPE\n");
        else printf("%lld\n", -ans[n-1].back());
    }
    
    
}