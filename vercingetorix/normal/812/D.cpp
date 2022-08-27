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
vvi ch;
vi vis;
vi lev;
vi home;
vi st;
int curt = 0;
int tin[100010], tout[100010];
void dfs(int v) {
    st[v] = 1;
    tin[v] = curt++;
    for(auto u : ch[v]) {
        lev[u] = lev[v]+1;
        home[u] = home[v];
        dfs(u);
        st[v]+=st[u];
    }
    tout[v] = curt++;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vi a(k), b(k);
    
    forn(i,0,k) scanf("%d %d", &a[i], &b[i]);
    vi visa(n+1,0);
    vi visb(m+1,0);
    vi valid(k,0);
    for(int i = k-1; i>=0; i--) {
        if(visa[a[i]] == 0) valid[i] ++;
//        if(visb[b[i]] == 0) valid[i] ++;
        visa[a[i]] = 1;
        visb[b[i]] = 1;
    }
    vi last(m+1,-1);
    ch.resize(n+1);
    vis = vi(n+1,0);
    vi par(n+1,0);
    forn(i,0,k) {
        if(valid[i] && last[b[i]] != -1) {
            ch[last[b[i]]].pb(a[i]);
            par[a[i]] = last[b[i]];
        }
        last[b[i]] = a[i];
    }
    
//    forn(i,1,n+1) if(ch[i] != -1) par[ch[i]] = i;
    lev = vi(n+1,0);
    
    home = vi(n+1,0);
    st.resize(n+1);
    forn(i,1,n+1) {
        if(par[i] == 0) {
            home[i] = i;
            dfs(i);
        }
    }
    forn(i,0,q) {
        int x,y;
        scanf("%d %d", &x, &y);
        if(last[y] == -1) {
            printf("0\n");
            continue;
        }
        int to = last[y];
        if(home[to] != home[x]) printf("0\n");
        else {
            if(tin[to] < tin[x] || tout[to] > tout[x]) printf("0\n");
            else printf("%d\n", st[x]);
        }
    }
    
    
}