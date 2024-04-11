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

vvi nb;
vi used;
vi a;

vi comp;

void dfs(int v) {
    deque<int> q;
    q.pb(v);
    used[v] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        comp.pb(u);
        for(auto k : nb[u]) if(!used[k]) {
            used[k] = 1;
            q.pb(k);
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
    scanf("%d %d", &n,&m);
    nb.resize(n);
    a.resize(n);
    used = vi(n,0);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        nb[x].pb(y);
        nb[y].pb(x);
    }
    forn(i,0,n) {
        if(!used[i]) {
            comp.clear();
            dfs(i);
            sort(all(comp));
            vi res;
            for(auto u : comp) {
                res.pb(a[u]);
            }
            sort(all(res));
            reverse(all(res));
            forn(i,0,comp.size()) a[comp[i]] = res[i];
        }
    }
    forn(i,0,n) {
        printf("%d ", a[i]);
    }
    
}