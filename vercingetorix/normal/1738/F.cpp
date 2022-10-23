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

int ask(int v) {
    printf("? %d\n", v+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret- 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(d,n);
        set<pi> x;
        forn(i,0,n) x.insert(mp(d[i], i));
        vi ans(n+1, 0);
        int cur = 1;
        while(!x.empty()) {
            auto it =x.end();
            --it;
            int v = it->second;
            x.erase(it);
            vi comp;
            comp.pb(v);
            int done = 0;
            forn(i,0,d[v]) {
                auto u = ask(v);
                if(ans[u] != 0) {
                    for(auto x : comp) ans[x] = ans[u];
                    done = 1;
                    break;
                }
                else {
                    comp.pb(u);
                    x.erase(mp(d[u], u));
                }
            }
            if(done == 0) {
                for(auto u : comp) ans[u] = cur;
                cur++;
            }
        }
        printf("!");
        forn(i,0,n) printf(" %d", ans[i]);
        printf("\n");
        fflush(stdout);
    }
    
    
}