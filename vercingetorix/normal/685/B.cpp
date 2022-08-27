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
std::vector<std::vector<int>> ch;
std::vector<int> par;
std::vector<int> lvl;
std::vector<int> st;

int dfs(int v, int lev) {
    lvl[v] = lev;
    st[v] = 1;
    for(auto u : ch[v]) {
        st[v] += dfs(u,lev+1);
    }
    return st[v];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    par.resize(n);
    ch.resize(n);
    lvl.resize(n);
    st.resize(n);
    for(int i=1;i<n;i++){
        scanf("%d", &par[i]);
        par[i]--;
        ch[par[i]].pb(i);
    }
    dfs(0,0);
    vvi son(20, vi(n, -1));
    forn(i,0,n) {
        int mx = 0;
        int s = -1;
        for(auto u : ch[i]) {
            if(st[u] > mx) {
                mx = st[u];
                s = u;
            }
        }
        son[0][i] = s;
    }
    forn(lev, 1, 20) {
        forn(i,0,n) {
            if(son[lev-1][i] != -1) {
                son[lev][i] = son[lev-1][son[lev-1][i]];
            }
        }
    }
    forn(i,0,q) {
        int v;
        scanf("%d", &v);
        v--;
        int s = st[v];
        int cur = v;
        for(int lev= 19; lev>=0; lev--) {
            int u = son[lev][cur];
            if(u >= 0 && st[u] > s/2) cur = u;
        }
        printf("%d\n", cur+1);
    }
}