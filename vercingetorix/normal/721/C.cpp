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

vector<vpi> e;

vector<int> g[10001]; // 
bool used[10001];
vector<int> ans;
int n,m,k;
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}

pi best[5000][5001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll T;
    cin>>n>>m>>T;
    forn(i,0,5000) forn(j,0,5001) best[i][j] = mp((T+1), 10000);
    e.resize(n);
    forn(i,0,m) {
        int x,y,t;
        cin>>x>>y>>t;
        x--;
        y--;
        g[x].pb(y);
        e[x].pb(mp(y,t));
    }
    topological_sort();
    best[0][1] = mp(0, 0);
    for(auto v : ans) {
        for(auto u : e[v]) {
            forn(i,1,5000) {
                best[u.first][i+1] = min(best[u.first][i+1], mp(best[v][i].first + u.second, v));
            }
        }
    }
    int cur = 0;
    forn(i,1,5001) if(best[n-1][i].first <= T) cur = i;
    ans.clear();
    ans.pb(n-1);
    int v = n-1;
    do {
        v = best[v][cur].second;
        cur--;
        ans.pb(v);
    } while(v!=0);
    reverse(all(ans));
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x+1<<' ';
    
    
    
    
}