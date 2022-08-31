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

vector<int> g[100001];

bool used[100001];
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi in(n,0);
    set<pi> q;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &v, &u);
        u--; v--;
        g[u].pb(v);
        in[v]++;
    }
    vi ans(n);
    forn(i,0,n) q.insert(mp(in[i], -i));
    forn(i,0,n) {
        auto x = *q.begin();
        q.erase(q.begin());
        ans[-x.second] = i+1;
        for(auto u : g[-x.second]) {
            q.erase(mp(in[u], -u));
            in[u]--;
            q.insert(mp(in[u], -u));
        }
    }

    forn(i,0,n) printf("%d ", n+1-ans[i]);
    
}