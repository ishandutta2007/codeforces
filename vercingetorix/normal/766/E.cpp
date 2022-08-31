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
typedef std::vector<vpll> vvpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vi d,a;
vvi ch, nb;
ll ans = 0;
vll tot;
struct stinfo {
    vpi cnt = vpi(20);
};
stinfo dfs(int v) {
    stinfo res;
//    vpi raw(20, pi(0,0));
    vvpll raw(20);
    for(auto u : ch[v]) {
        stinfo ur = dfs(u);
        forn(i,0,20)
        {
            raw[i].pb(ur.cnt[i]);
//            raw[i].first += ur.cnt[i].first;
//            raw[i].second += ur.cnt[i].second;
            if (a[v] & (1 << i)) {
                swap(ur.cnt[i].first, ur.cnt[i].second);
            }
            res.cnt[i].first += ur.cnt[i].first;
            res.cnt[i].second += ur.cnt[i].second;
        }
    }
    forn(i,0,20) {
        if (a[v] & (1 << i)) {
            res.cnt[i].second ++;
        }
        else {
            res.cnt[i].first ++;
        }
    }
    forn(i,0,20) {
        ll c0 = 0, c1 = 0;
        for(auto x : raw[i]) {
            c0 += x.first;
            c1 += x.second;
        }
//        ll c0 = raw[i].first + 1;
//        ll c1 = raw[i].second;
        if(a[v] & (1 << i)) {
            ans += (1ll << i) * c0;
            for(auto x : raw[i]) {
                c0 -= x.first;
                c1 -= x.second;
                ans += (1ll << i) * (x.first * c0 + x.second * c1);
            }
        }
        else {
            ans += (1ll << i) * c1;
            for(auto x : raw[i]) {
                ans += (1ll << i) * (ll)x.first * ll(c1 - x.second);
            }
        }
    }
    ans += a[v];
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    
    vi par, v_lvl;
    vvi lvl;
    scanf("%d", &n);
    a.resize(n);
    tot = vll(n,0);
    d=vi(n,0);
    forn(i,0,n) scanf("%d", &a[i]);
    v_lvl.resize(n);
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
    dfs(0);
    cout<<ans;
    
    
}