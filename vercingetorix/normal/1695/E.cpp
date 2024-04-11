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
vector<set<pi>> g;

vi cur;

void dfs(int v) {
    while(!g[v].empty()) {
        auto e = *g[v].begin();
        g[v].erase(g[v].begin());
        g[e.first].erase(mp(v, e.second));
        cur.pb(e.first);
        if(e.first == v) cur.pb(e.first);
        else {
            dfs(e.first);
            cur.pb(v);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    g.resize(2*n);
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        --x; --y;
        g[x].insert(mp(y, i));
        g[y].insert(mp(x, i));
    }
    vi top, bot;
    string t1, b1, t2, b2;
    forn(i,0,2*n) {
        if(!g[i].empty()) {
            dfs(i);
            if(cur.size() == 2) {
                cout<<-1;
                exit(0);
            }
            int len = cur.size() / 2;
            forn(i,0,len) top.pb(cur[i] + 1);
            forn(i,0,len) bot.pb(cur[2*len-1-i] + 1);
            forn(i,0,len/2) {
                t1 += "LR";
                b1 += "LR";
            }
            if(len % 2) {
                t1 += "U";
                b1 += "D";
            }
            t2 += "U";
            b2 += "D";
            forn(i,0,(len-1)/2) {
                t2 += "LR";
                b2 += "LR";
            }
            if(len % 2 == 0) {
                t2 += "U";
                b2 += "D";
            }
            cur.clear();
        }
    }
    printf("2 %d\n", n);
    forn(i,0,n) printf("%d ", top[i]); printf("\n");
    forn(i,0,n) printf("%d ", bot[i]); printf("\n");
    printf("%s\n", t1.c_str());
    printf("%s\n", b1.c_str());
    printf("%s\n", t2.c_str());
    printf("%s\n", b2.c_str());
}