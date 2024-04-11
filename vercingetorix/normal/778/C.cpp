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

struct vertex {
    int sz = 0;
    int next[26];
    void clear() {
        forn(i,0,26) next[i] = -1;
        sz = 0;
    }
};

const int NMAX = 1000000;
int n;
vector<vertex> t(NMAX);

void dfs(int v) {
    t[v].sz = 1;
    forn(i,0,26) {
        if(t[v].next[i] != -1) {
            dfs(t[v].next[i]);
            t[v].sz += t[t[v].next[i]].sz;
        }
    }
}


vi get_child(int x) {
    vi ret;
    forn(i,0,26) if(t[x].next[i] != -1) ret.pb(t[x].next[i]);
    return ret;
}

vpi nch;
int pt;
int decr;
void dfs_add(int to, int fr) {
    forn(i,0,26) {
        int v = t[fr].next[i];
        if(v != -1) {
            if(t[to].next[i] != -1) {
                dfs_add(t[to].next[i], v);
                decr++;
            }
            else {
                nch.pb(mp(to, i));
                t[to].next[i] = pt++;
                dfs_add(t[to].next[i], v);
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
    int n;
    scanf("%d", &n);
    forn(i,0,NMAX) t[i].clear();
    forn(i,0,n-1) {
        int u,v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        u--; v--;
        t[u].next[c-'a'] = v;
    }
    dfs(0);
    int best = n;
    int del = 0;
    vi cl;
    cl.pb(0);
    int l = 1;
    while(!cl.empty()) {
        vi ncl;
        for(auto x : cl) for(auto y : get_child(x)) ncl.pb(y);
        if(ncl.empty()) break;
        decr = 0;
        nch.clear();
        pt = n;
        for(auto par : cl) {
            vi ch = get_child(par);
            if(ch.empty()) continue;
            int mx = ch[0];
            for(auto u : ch) {
                if(t[u].sz > t[mx].sz) mx = u;
                decr += 1;
            }
            for(auto u : ch) {
                if(u == mx) continue;
                dfs_add(mx, u);
            }
        }
        if(best > n-decr) {
            best = n-decr;
            del = l;
        }
        for(auto x : nch) {
            t[x.first].next[x.second] = -1;
        }
        forn(i,n,pt) t[i].clear();
        l++;
        cl = ncl;
    }
    cout<<best<<endl<<del;
    
    
    
}