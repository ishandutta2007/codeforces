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
vector<map<int, ll>> tp;
int n,k;

int comb(int a, int b) {
    if(a+b>=1) return max(a,b);
    else return min(a,b);
}

map<int, ll> merge(map<int,ll> a, map<int,ll> b) {
    map<int, ll> c;
    forn(i,-k,k+1) {
        forn(j,-k,k+1) {
            int m = comb(i, j);
            c[m] = (c[m] + a[i] * b[j]) % mod;
        }
    }
    return c;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cin>>n>>k;
    
    v_lvl.resize(n);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    tp.resize(n);
    
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
    
    for(int lev = l; lev>0; lev--) {
        for(auto v : lvl[lev]) {
            tp[v][0] = 1;
            for(auto u : ch[v]) {
                tp[v] = merge(tp[v], tp[u]);
            }
            forn(i,-k-1,k+1) tp[v][i] = tp[v][i+1];
            forn(i,-k-1,k) tp[v][k] += tp[v][i];
            tp[v][k] %= mod;
            tp[v][-k-1] = 0;
        }
    }
    ll ans = 0;
    forn(i,0,k+1) {
        ans = ans + tp[0][i];
    }
    cout<<ans%mod;
    
    
    
}