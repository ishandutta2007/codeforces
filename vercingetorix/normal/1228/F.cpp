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
vvi g;
vi irr;
void die() {
    cout<<0;
    exit(0);
}
int dfs(int v, int p) {
    if(g[v].size() == 1) return 0;
    vi ch;
    for(auto u : g[v]) if(u!=p) {
        ch.pb(dfs(u, v));
    }
    srt(ch);
    if(ch.size() > 3) {
        cout<<0;
        exit(0);
    }
    else if(ch.size() == 1) {
        if(ch[0] != 0) die();
        irr.pb(v);
    }
    else if(ch.size() == 2) {
        if(ch[0] != ch[1]) die();
    }
    else {
        if(ch[0] != ch[1] || ch[0] + 1 != ch[2]) die();
        irr.pb(v);
    }
//    cout<<v<<' '<<ch[1]+1<<'\n';
    return ch.back() +  1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    g.resize((1<<n) - 2);
    forn(i,0,(1<<n) - 3) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int root = -1;
    int m = g.size();
//    forn(i,0,m) if(g[i].size() == 2) root = i;
    vi d2;
    forn(i,0,m) if(g[i].size() == 2) {
        int bad = 0;
        for(auto u : g[i]) if(g[u].size() == 1) bad = 1;
        if(bad == 0) d2.pb(i);
    }
    if(d2.size() == 1) root = d2[0];
    else if(d2.size() >= 2) die();
//    else if(d2.size() == 2) {
//        
//    }
    forn(i,0,m) if(g[i].size() > 4) {
        die();
    }
    if(root == -1) {
        const int INF = 1e9;
        vector<int> d (m, INF);
        priority_queue < pair<int,int> > q;
        forn(i,0,m) if(g[i].size() == 1) {
            d[i] = 0;
            q.push (make_pair (0, i));
        }
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j];
                if (d[v] + 1 < d[to]) {
                    d[to] = d[v] + 1;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
        vi roots(1,0);
        forn(i,1,m) {
            if(d[i] > d[roots[0]]) roots = vi(1, i);
            else if(d[i] == d[roots[0]]) roots.pb(i);
        }
        if(roots.size() == 1) {
            die();
            root = roots[0];
            dfs(root, root);
            if(irr.size() != 1) die();
            printf("1\n");
            printf("%d\n", irr[0]+1);
            exit(0);
        }
        if(roots.size() != 2) {
            cout<<0;
            exit(0);
        }
        dfs(roots[0], roots[1]);
        dfs(roots[1], roots[0]);
        if(irr.empty()) {
            printf("2\n");
            srt(roots);
            printf("%d %d\n", roots[0]+1, roots[1]+1);
        }
        else die();
    }
    else {
        dfs(root, root);
        if(irr.size() != 1) die();
        printf("1\n");
        printf("%d\n", irr[0]+1);
    }
    
    
}