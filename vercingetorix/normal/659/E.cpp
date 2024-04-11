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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int MAXN = 100001;
int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;
int ans=0;
void dfs (int v) {
    used[v] = true;
    comp.push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (! used[to])
            dfs (to);
    }
}

void find_comps() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (! used[i]) {
            comp.clear();
            dfs (i);
            
            int edges=0;
            //cout << "Component:";
            for (size_t j=0; j<comp.size(); ++j)
                edges+=g[comp[j]].size();
            edges/=2;
            if(edges<comp.size()) ans++;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,k;
    //string s;

    scanf("%d %d",&n,&m);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d",&x,&y);
        x--;y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    find_comps();
    cout<<ans;
    // cout<<ans;
}