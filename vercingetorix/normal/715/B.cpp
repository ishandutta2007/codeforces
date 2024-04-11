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

struct edge {
    int x,y;
    ll c;
    bool fr;
};

vll d, p;
vector < vector < pair<int,ll> > > g ;
int n,m,s,t;
vector<edge> e;
const ll INF = 1e18;

void dij() {
    d[s] = 0;
    vector<char> u (n);
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first;
            ll len = e[g[v][j].second].c;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = g[v][j].second;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    ll l;
    
    scanf("%d %d %lld %d %d", &n, &m, &l, &s, &t);
    e.resize(m);
    const ll UND = 1e13 + 10;
    g.resize(n);
    map<pi, int> mark;
    forn(i,0,m) {
        int x,y;
        ll c;
        scanf("%d %d %lld", &x, &y, &c);
        e[i].fr = false;
        if(c==0) {
            mark[mp(x,y)] = 1;
            mark[mp(y,x)] = 1;
            c= 1;
            e[i].fr = true;
        }
        e[i].x = x;
        e[i].y = y;
        e[i].c = c;
        g[x].pb(mp(y,i));
        g[y].pb(mp(x,i));
    }
    
    while(1) {
        d = vll(n, INF);
        p.resize(n);
        dij();
        if(d[t] > l) {
            cout<<"NO";
            return 0;
        }
        else if(d[t] == l) break;
        else {
            int v = t;
            int ind = -1;
            vi marked(m,0);
            while(v != s) {
                if(e[p[v]].fr) {
                    marked[p[v]] = 1;
                    ind = p[v];
                }
                v = e[p[v]].x + e[p[v]].y - v;
            }
            if(ind == -1) {
                cout<<"NO";
                return 0;
            }
            forn(i,0,m) {
                if(marked[i] == 0 && e[i].fr) e[i].c = UND;
            }
            e[ind].c += l-d[t];
        }
    }
    printf("YES\n");
    forn(i,0,m) {
        printf("%d %d %lld\n", e[i].x, e[i].y, e[i].c);
    }
    
    
    
}