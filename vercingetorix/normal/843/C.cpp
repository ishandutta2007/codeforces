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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vvi nb;
vvi ch;
int n;
vi st;
vi par;
int root = -1;
int root2 = -1;
void dfs(int v, int p) {
    st[v] = 1;
    for(auto u : nb[v]) {
        if(u==p) continue;
        dfs(u,v);
        par[u] = v;
        st[v] += st[u];
        ch[v].pb(u);
    }
    if(root == -1 && 2*st[v] >= n) root = v;
}

vector<deque<int>> her;
vi ax, ay, ay2;

void straighten(int v, int p) {
    for(auto u : ch[v]) straighten(u, v);
    if(ch[v].empty()) her[v] = deque<int>(1,v);
    else {
        int mind = -1;
        int best = 0;
        for(auto u : ch[v]) if(her[u].size() > best) {
            best = her[u].size();
            mind = u;
        }
        int mu = mind;
        
        
        int curp = p;
        int curtop = v;
        vi indi;
        for(auto u : ch[v]) {
            if(u==mu) continue;
            ax.pb(curp);
            ay.pb(curtop);
            ay2.pb(her[u].back());
            curp = her[u].front();
            indi.pb(u);
        }
        her[v] = std::move(her[mu]);
        her[mu].clear();
        her[v].push_front(v);
        reverse(all(indi));
        for(auto ind : indi) {
            for(auto x : her[ind]) her[v].push_front(x);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    nb.resize(n);
    st.resize(n);
    par = vi(n,-1);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v);
        nb[v].pb(u);
    }
    ch.clear();
    ch.resize(n);
    her.resize(n);
    dfs(0, -1);
    ch.clear();
    ch.resize(n);
    dfs(root,-1);
    forn(i,0,n) {
        if(i != root && 2*st[i] >= n) root2 = i;
    }
    for(auto x : ch[root]) if(x != root2) straighten(x, root);
    if(root2 != -1) for(auto x : ch[root2]) if(x != root) straighten(x,root2);
    for(auto x : ch[root]) if(x!=root2) {
        if(her[x].size() > 2) {
            her[x].push_front(root);
            int k = her[x].size();
            for(int i = k-4; i>=0; i--) {
                ax.pb(her[x][i]);
                ay.pb(her[x][i+1]);
                ay2.pb(her[x][k-2]);
            }
        }
    }
    if(root2 != -1) for(auto x : ch[root2]) if(x != root) {
        if(her[x].size() > 2) {
            her[x].push_front(root2);
            int k = her[x].size();
            for(int i = k-4; i>=0; i--) {
                ax.pb(her[x][i]);
                ay.pb(her[x][i+1]);
                ay2.pb(her[x][k-2]);
            }
        }
    }
    printf("%d\n", ax.size());
    forn(i,0,ax.size()) printf("%d %d %d\n", ax[i]+1, ay[i]+1, ay2[i]+1);
    
}