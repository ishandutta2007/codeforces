#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int MAXN = 500;
int n;
vvi g;
vb used;
vvi comp;

void dfs (int v) {
    used[v] = true;
    comp.back().push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (! used[to])
            dfs (to);
    }
}

int ans = 0;

void find_comps() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (! used[i]) {
            comp.push_back(vi());
            dfs (i);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n,&m);
    g.resize(n);
    used.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u,&v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    find_comps();
    for(auto c:comp) {
        int l = c.size();
        int ans2 = 0;
        for(auto s:c) {
            vi us(n,0);
            vi u2(n,0);
            int cnt = 1;
            vi lev(1,s);
            us[s] = 1;
            int anscand =0;
            bool f =false;
            while(cnt<l) {
                anscand++;
                vi lev2;
                for( auto v:lev) {
                    u2[v] = 1;
                }
                for(auto v : lev) {
                    for(auto u : g[v]) {
                        if(u2[u]) {
                            cout<<-1;
                            return 0;
                        }
                        if(!us[u]) {
                            us[u] = 1;
                            lev2.pb(u);
                            cnt++;
                        }
                    }
                }
                

                for( auto v:lev) {
                    u2[v] = 0;
                }
                lev = lev2;
                
            }
            for( auto v:lev) {
                u2[v] = 1;
            }
            for(auto v : lev) {
                for(auto u : g[v]) {
                    if(u2[u]) {
                        cout<<-1;
                        return 0;
                    }
                }
            }
            for( auto v:lev) {
                u2[v] = 0;
            }
            ans2= max(ans2, anscand);
        }
        ans+=ans2;
    }
    cout<<ans;
    
}