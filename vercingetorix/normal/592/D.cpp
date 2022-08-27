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


vvi ch, nb;
vi par, v_lvl;
vvi lvl;
vi at;
vi sat;
int lca = -1;
vll d,u;
int nat;

int dfs1(int v) {
    int cnt = at[v];
    for(auto u : ch[v]) {
        cnt += dfs1(u);
    }
    sat[v] = cnt;
    if(cnt == nat && lca == -1) lca = v;
//    cout<<"visited " << v << " got " << cnt<<endl;
    return cnt;
}
int bestlen = 0;
int bv;

int dfs2(int v) {
    vpi slen;
    for(auto u : ch[v]) {
        int x = dfs2(u);
        if(sat[u]) slen.pb(mp(v_lvl[v]-v_lvl[x], x));
    }
    sort(all(slen));
    if(slen.size()>1) {
        auto x = slen[0];
        auto y = slen[1];
        if (-x.first-y.first > bestlen) {
            bestlen = -x.first-y.first;
            bv = min(x.second, y.second);
        }
        else if(-x.first-y.first == bestlen) {
            bv = min(x.second, bv);
            bv = min(y.second, bv);
        }
    }
    if (slen.size()>0) {
        auto x = slen[0];
        if (-x.first > bestlen) {
            bestlen = -x.first;
            bv = min(x.second, v);
        }
        else if(-x.first == bestlen) {
            bv = min(x.second, bv);
            bv = min(v, bv);
        }
        return slen[0].second;
    }
    else return v;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d %d", &n, &nat);
    sat.resize(n);
   
    at = vi(n,0);
    v_lvl.resize(n);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    d=vll(n,0);
    u=vll(n,0);
    
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
    std::vector<long long> lsize(l+1);
    for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
    forn(i,0,nat) {
        int x;
        scanf("%d", &x);
        x--;
        at[x]=1;
        bv = x;
    }
    
    dfs1(0);
    int ans = 0;
    forn(i,0,n) if(sat[i] < nat && sat[i] > 0) ans+=2;
    dfs2(lca);
    cout<<bv+1<<endl;
    cout<<ans - bestlen;
    
    
}