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

vvpi e;
vvi comp;
vi used;
vpi par;
vi num;
vi cnt;
int tm = 0;

void dfs(int v, int p) {
    used[v] = 1;
    num[v] = tm;
    tm++;
    for(auto u : e[v]) {
        if(u.first == p) continue;
        if(used[u.first]) {
            if(num[u.first] > num[v]) continue;
            comp.pb(vi(1, u.second));
            int cur = v;
            while(cur != u.first) {
                comp.back().pb(par[cur].second);
                cur = par[cur].first;
            }
        }
        else {
            par[u.first] = mp(v, u.second);
            dfs(u.first, v);
        }
    }
}

int ans = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    par.resize(n);
    num.resize(n);
    used = vi(n,0);
    cnt.resize(m);
    e.resize(n);
    forn(i,0,m) {
        int x,y,c;
        scanf("%d %d %d", &x, &y, &c);
        x--;
        y--;
        c--;
        cnt[c]++;
        e[x].pb(mp(y,c));
        e[y].pb(mp(x,c));
    }
    forn(i,0,m) if(cnt[i]) ans++;
    dfs(0,-1);
    vi done(comp.size(), 0);
    vvi comp2;
    forn(i,0,comp.size()) {
        sort(all(comp[i]));
        bool f = false;
        vi a;
        forn(j,1,comp[i].size()) {
            if(comp[i][j] == comp[i][j-1]) f = true;
        }
        if(f) continue;
        for(auto x : comp[i]) {
            if(cnt[x] != 1) {
                a.pb(x);
            }
        }
        if(a.empty()) ans--;
        else comp2.pb(a);
    }
    while(1) {
        bool tt = false;
        vvi comp3;
        forn(i,0,comp2.size()) {
            if(comp2[i].size() == 1) {
                tt = true;
                int id = comp2[i][0];
                cnt[id]--;
                if(cnt[id]==0) ans--;
            }
            else {
                comp3.pb(comp2[i]);
            }
        }
        comp2.clear();
        forn(i,0,comp3.size()) {
            vi a;
            for(auto x : comp3[i]) {
                if(cnt[x] > 1) {
                    a.pb(x);
                }
            }
            if(a.empty()) ans--;
            else comp2.pb(a);
        }
        if(!tt) break;
    }
    cout<<ans;
}