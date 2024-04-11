#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vvi nb;
set<int> ch[200000];
int par[200000];

int root = -1;

void dfs(int v, int p) {
    for(auto u : nb[v]) {
        if (u == p) continue;
        ch[v].insert(u);
        par[u] = v;
        dfs(u, v);
    }
    if(ch[v].size() == 0) {
        ch[par[v]].erase(v);
        ch[par[v]].insert(-1);
    }
    else if(ch[v].size() == 1 && *ch[v].begin() < 0 && v != root) {
        ch[par[v]].erase(v);
        ch[par[v]].insert(*ch[v].begin()-1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    nb.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v); nb[v].pb(u);
    }
    
    forn(i,0,n) {
        if(nb[i].size() > 2) root = i;
    }
    if(root == -1) {
        int ans = n-1;
        while(ans%2==0) ans/=2;
        cout<<ans;
        return 0;
    }
    par[root] = -1;
    dfs(root, -1);
    while(1) {
        if(ch[root].size() > 2) {
            cout<<-1;
            return 0;
        }
        else if(ch[root].size() == 1) {
            int ans = -*ch[root].begin();
            while(ans%2==0) ans/=2;
            cout<<ans;
            return 0;
        }
        else {
            auto it = ch[root].begin();
            int l = -*it;
            it++;
            int nroot = *it;
            if(nroot < 0) {
                int ans = l - nroot;
                while(ans%2==0) ans/=2;
                cout<<ans;
                return 0;
            }
            ch[nroot].insert(-l-1);
            root = nroot;
        }
    }
    
}