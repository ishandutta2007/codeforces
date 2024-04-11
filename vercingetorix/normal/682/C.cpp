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
std::vector<int> par;
vi cost;
int ans;
std::vector<std::vector<int>> ch;
void rem(int v) {
    ans++;
    for(auto u : ch[v]) rem(u);
}
vi a;
void dfs(int v, ll del, ll mindel) {
    if(del - mindel > a[v]) {
        rem(v);
        return;
    }
    ll mdel = min(mindel, del);
    for(auto u : ch[v]) {
        dfs(u, del + cost[u], mdel);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ans = 0;
    int n;
    scanf("%d", &n);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    
    int m;
    ch.resize(n);
    par.resize(n);
    cost.resize(n);
    std::vector<std::vector<int>> nb(n);
    std::vector<std::vector<int>> lvl(n+1);
    std::vector<int> v_lvl(n+1,0);
    m=1;
    lvl[1].push_back(0);
    v_lvl[0]=1;
    map<pi, int> ed;
    for(int i=1;i<n;i++){
        int u,v;
        int c;
        scanf("%d %d", &u, &c);
        v = i;
        u--;
        ed[mp(v,u)] = c;
        ed[mp(u,v)] = c;
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
    std::vector<long long> lsize(l+1);
    for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
    
    forn(i,1,n) cost[i] = ed[mp(i,par[i])];
    dfs(0,0,9999999999);
    
    cout<<ans;
    
}