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

const int MAXN = 200000;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
    vvi g(n);
    
    forn(i,0,m) {
        int x,y;
        scanf("%d %d\n", &x, &y);
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    int s,t,ds,dt;
    scanf("%d %d %d %d", &s, &t, &ds, &dt);
    s--;
    t--;
    forn(i,0,n) if(i!=s && i!=t) make_set(i);
    vpi ans;
    forn(i,0,n) {
        if(i==s) continue;
        if(i==t) continue;
        for(auto j : g[i]) {
            if(j==s || j==t) continue;
            if(find_set(i)==find_set(j)) continue;
            ans.pb(mp(i+1,j+1));
            union_sets(i, j);
        }
    }
    vi comps;
    forn(i,0,n) {
        if(i==s || i==t) continue;
        if(!lst[i].empty()) comps.pb(i);
    }
    vi ns(n,-1);
    vi nt(n,-1);
    for(auto v : g[s]) if(v!=t) ns[find_set(v)] = v;
    int st = 0;
    for(auto v : g[s]) if(v == t) st = 1;
    for(auto v : g[t]) if(v!=s) nt[find_set(v)] = v;
    vi cs,ct,c2;
    for(auto x:comps) {
        if(ns[x] >= 0 && nt[x] >= 0) c2.pb(x);
        else if(ns[x] >= 0) cs.pb(x);
        else ct.pb(x);
    }
    for(auto x : cs) {
        ans.pb(mp(s+1, ns[x]+1));
        ds--;
    }
    for(auto x : ct) {
        ans.pb(mp(t+1, nt[x]+1));
        dt--;
    }
    if(ds<0 || dt<0) {
        cout<<"No";
        return 0;
    }
    if(c2.empty()) {
        if(st==0) {
            cout<<"No";
            return 0;
        }
        if(ds<=0 || dt <=0) {
            cout<<"No";
            return 0;
        }
        ans.pb(mp(s+1,t+1));
    }
    else {
        if(ds<=0 || dt <=0) {
            cout<<"No";
            return 0;
        }
        if(ds+dt <= c2.size()) {
            cout<<"No";
            return 0;
        }
        int lasts = min(ds-1,(int)c2.size()-1);
        forn(i,0,lasts+1) {
            ans.pb(mp(s+1, ns[c2[i]] +1));
        }
        forn(i,lasts,c2.size()) {
            ans.pb(mp(t+1, nt[c2[i]] +1));
        }
    }
    printf("Yes\n");
    for(auto e : ans) {
        printf("%d %d\n", e.first, e.second);
    }
    
}