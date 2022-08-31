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
vi vmin;
void dfs(int v, int p, int curmin) {
    vmin[v] = min(v, curmin);
    for(auto u : nb[v]) {
        if(u != p) dfs(u, v, vmin[v]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    int last = 0;
    nb.resize(n);
    vmin.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v); nb[v].pb(u);
    }
    int root;
    int tp;
    scanf("%d %d", &tp, &root);
    root=root%n;
    int mans = root;
    dfs(root, -1, root);
    forn(i,0,q-1) {
        int z;
        scanf("%d %d", &tp, &z);
        int x = (z+last)%n;
        if (tp == 1) {
            mans = min(mans, vmin[x]);
        }
        else {
            int res = 1 + min(vmin[x], mans);
            last = res;
            printf("%d\n", res);
        }
    }
    
    
}