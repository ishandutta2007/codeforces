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
vvi lvl;

vvi ch2;
vi par2, v_lvl2;
vvi lvl2;

vi a;
vi used;
vi cnt;
int dfs(int v) {
    int cont = used[v];
    for(auto u : ch[v]) {
        cont+=dfs(u);
    }
    cnt[v] = cont;
    return cont;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k;
    scanf("%d %d", &n, &k);
    a.resize(2*k);
    forn(i,0,2*k) scanf("%d", &a[i]);
    forn(i,0,2*k) a[i]--;
    
    used = vi(n,0);
    forn(i,0,2*k) used[a[i]] = 1;
    v_lvl.resize(n);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    cnt.resize(n);
    
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
    dfs(0);
    int cur = 0;
    while(1) {
        int f = -1;
        for(auto v : ch[cur]) if(cnt[v] >= k) f = v;
        if(f>=0) cur = f;
        else break;
    }
    
    v_lvl2.resize(n);
    par2.resize(n);
    ch2.resize(n);
    lvl2.resize(n+1);
    
    m=1;
    lvl2[1].push_back(cur);
    v_lvl2[cur]=1;
    
    l=2;
    
    while(m<n){
        for(int k=0; k<lvl2[l-1].size(); k++){
            int v=lvl2[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl2[nb[v][h]]==0){
                    v_lvl2[nb[v][h]]=l;
                    lvl2[l].push_back(nb[v][h]);
                    m++;
                    ch2[v].push_back(nb[v][h]);
                    par2[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    
    ll ans = 0;
    forn(i,0,2*k) ans+=(ll)(v_lvl2[a[i]] - 1);
    cout<<ans;
    
}