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

void no() {
    cout<<"NO";
    exit(0);
}
vvi g;
int vis[100];
vi ord;
void dfs(int v) {
    ord.pb(v);
    vis[v] = 1;
    for(auto u: g[v]) {
        if(!vis[u]) dfs(u);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g = vvi (n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i,0,n) if(g[i].size() > 2) no();
    vpi q;
    forn(i,0,n) {
        if(!vis[i] && g[i].size() == 1) {
            dfs(i);
            q.pb(mp(ord[0], ord.back()));
            ord.clear();
        }
        else if(g[i].empty()) {
            vis[i] = 1;
            q.pb(mp(i,i));
        }
    }
    vpi ans;
    if(q.empty()) {
        dfs(0);
        if(ord.size() == n)  {
            printf("YES\n");
            printf("0");
        }
        else no();
    }
    else {
        forn(i,0,n) if(!vis[i]) no();
        srtrev(q);
        while(!q.empty()) {
            if(q.size() == 1) {
                ans.pb(q[0]);
                q.pop_back();
            }
            else {
                pi l = q.back();
                q.pop_back();
                pi r = q.back();
                q.pop_back();
                ans.pb(mp(l.first, r.first));
                q.pb(mp(l.second, r.second));
                if(q.back().second < q.back().first) swap(q.back().second, q.back().first);
                srtrev(q);
            }
        }
        printf("YES\n");
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
    }
    
    
}