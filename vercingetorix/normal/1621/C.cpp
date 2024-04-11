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

int ask(int i) {
    printf("? %d\n", i+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret-1;
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
        int shift = 0;
        vi vis(n,0);
        vi ans(n);
        forn(v,0,n) {
            if(vis[v] == 0) {
                vi ord;
                ord.pb(ask(v));
                shift++;
                while(1) {
                    int cur = ask(v);
                    shift++;
                    if(cur == ord[0]) break;
                    else {
                        ord.pb(cur);
                    }
                }
                for(auto x : ord) vis[x] = 1;
                forn(i,0,ord.size()) {
                    ans[ord[i]] = ord[(i+1)%ord.size()];
                }
            }
        }
        printf("!");
        forn(i,0,n) printf(" %d", ans[i]+1);
        printf("\n");
        fflush(stdout);
    }
    
    
}