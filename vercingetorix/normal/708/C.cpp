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

vi st;
int n;
vi ans;
vvi ch, nb;
vi par, v_lvl;
vvi lvl;
multiset<int> s;

void dfs(int v) {
    int left = n - st[v];
    if(s.empty()) ans[v] = 0;
    else {
        int y = *(--s.end());
        int cool = left - y;
        if(cool+cool > n) ans[v] = 0;
        else ans[v] = 1;
        
    }
    for(auto u:ch[v]) dfs(u);
}

void dfsdel(int v) {
    s.erase(s.find(st[v]));
    for(auto u : ch[v]) dfsdel(u);
}

void dfsadd(int v) {
    s.insert(st[v]);
    for(auto u : ch[v]) dfsadd(u);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    ans.resize(n);



    
    v_lvl = vi(n, 0);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    
    int m=1;
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
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    m++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;

    st =vi(n,1);
    for(int lev = l; lev>=1; lev--) {
        for(auto v : lvl[lev]) {
            for(auto u : ch[v]) st[v] +=st[u];
        }
    }
    int cur = 0;
    while(1) {
        int nx = -1;
        for(auto u : ch[cur]) {
            if(2*st[u] > n) nx = u;
        }
        if(nx==-1) break;
        else cur = nx;
    }
    
    int root = cur;
    forn(i,1, l+1) lvl[i].clear();
    forn(i,0,n) ch[i].clear();
    v_lvl = vi(n, 0);
    l=2;
    lvl[1].push_back(root);
    v_lvl[root]=1;
    m=1;
    par[root] = -1;
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    m++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    
    st = vi(n,1);
    for(int lev = l; lev>=1; lev--) {
        for(auto v : lvl[lev]) {
            for(auto u : ch[v]) st[v] +=st[u];
        }
    }
    for(auto u : ch[root]) if(2*st[u] == n) {
        forn(i,0,n) printf("1 ");
        return 0;
    }
    ans[root] = 1;
    forn(i,0,n) if(i!=root) s.insert(st[i]);
    for(auto v : ch[root]) {
        dfsdel(v);
        dfs(v);
        dfsadd(v);
    }
    forn(i,0,n) printf("%d ", ans[i]);
    
}