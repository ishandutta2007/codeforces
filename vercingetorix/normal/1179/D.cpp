#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vvi g;
int n;
vi par;
vvi ch;
ll ans = 0;

void dfs0(int v,int p) {
    par[v] = p;
    for (auto u : g[v]) {
        if(u == p) continue;
        ch[v].pb(u);
        dfs0(u,v);
    }
}

pll dfs1(int v, int p) {
    vpll a;
    ll l = 0;
    for (auto u : g[v]) {
        if(u == p) continue;
        ch[v].pb(u);
        a.pb(dfs1(u,v));
        l += a.back().first;
    }
    l++;
    ll best = 0;
    sort(all(a));
    reverse(all(a));
    if(a.size() > 10) {
        forn(i,5,a.size()) swap(a[i].first, a[i].second);
        sort(a.begin() + 5, a.end());
        reverse(a.begin() + 5, a.end());
        forn(i,5,a.size()) swap(a[i].first, a[i].second);
        a.resize(10);
    }
//    if(a.size() > 7) {
//        a.resize(7);
//    }
    forn(i,0,a.size()) {
        ll l1 = a[i].first;
        best = max(best, a[i].second + (l-l1)*l1);
        forn(j,i+1,a.size()) {
            
            ll l2 = a[j].first;
            ans = max(ans, a[i].second + a[j].second + l1*l2+(n-l1-l2)*(l1+l2));
        }
    }
    ans = max(ans, best);
    return mp(l, best);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int n;
    read(n);
    g.resize(n);
    par.resize(n);
    ch.resize(n);
    forn(i,0,n-1) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--;r--;
        g[l].pb(r);
        g[r].pb(l);
    }
    dfs0(0,-1);
    dfs1(0,-1);
    cout<<ans + ll(n)*(n-1)/2;
}