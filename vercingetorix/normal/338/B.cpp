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
int n;
vvi ch, nb;
vi par, v_lvl;
vi bad;
vvi lvl;
vi down;
vi up;

void dfsd(int v) {
    for(auto u : ch[v]) {
        dfsd(u);
        down[v] = max(down[v], down[u] + 1);
    }
}

void dfsu(int v) {
    vi ad(1,up[v]);
    for(auto u : ch[v]) {
        ad.pb(down[u] + 1);
    }
    sort(all(ad));
    reverse(all(ad));
    for(auto u : ch[v]) {
        if(down[u]+1 == ad[0]) {
            up[u] = max(up[u],ad[1] + 1);
        }
        else up[u] = max(up[u],ad[0] + 1);
        dfsu(u);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,d;
    scanf("%d %d %d", &n, &m, &d);
    vi a(m);
    bad=vi(n,0);
    down = vi(n,-1000000);
    up = vi(n,-1000000);
    forn(i,0,m) {
        scanf("%d", &a[i]);
        a[i]--;
        bad[a[i]] = 1;
        down[a[i]] = 0;
        up[a[i]] = 0;
    }
    
    v_lvl.resize(n);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    
    int mm=1;
    lvl[1].push_back(0);
    v_lvl[0]=1;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    int l=2;
    
    while(mm<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    mm++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    dfsd(0);
    dfsu(0);
    int ans = 0;
    forn(i,0,n) {
        if(down[i] <= d && up[i] <= d) ans++;
    }
    cout<<ans;
    
}