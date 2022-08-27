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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    vector < vector<int> > g;
    scanf("%d %d", &n, &m);
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    vector<char> part (n, -1);
    bool ok = true;
    vector<int> q (n);
    for (int st=0; st<n; ++st)
        if (part[st] == -1) {
            int h=0, t=0;
            q[t++] = st;
            part[st] = 0;
            while (h<t) {
                int v = q[h++];
                for (size_t i=0; i<g[v].size(); ++i) {
                    int to = g[v][i];
                    if (part[to] == -1)
                        part[to] = !part[v],  q[t++] = to;
                    else
                        ok &= part[to] != part[v];
                }
            }
        }
    
    //puts (ok ? "YES" : "NO");
    if(!ok) {
        cout<<-1;
    }
    else {
        vi a,b;
        forn(i,0,n) {
            if(part[i]==0) a.pb(i+1);
            else b.pb(i+1);
        }
        printf("%d\n", a.size());
        for(auto u:a) printf("%d ", u);
        printf("\n");
        printf("%d\n", b.size());
        for(auto u:b) printf("%d ", u);
        printf("\n");
    }
    
}