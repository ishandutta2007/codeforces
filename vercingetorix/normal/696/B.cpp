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

vi par;
vvi ch;
vd ans;
vi cnt;

int c(int v) {
    int cn = 1;
    for(auto u : ch[v]) cn += c(u);
    cnt[v] = cn;
    return cn;
}


void dfs(int v, double cur) {
    double mo = cur + 1.;
    ans[v] = mo;
    for(auto u : ch[v]) {
        mo += (double)cnt[u] / 2.;
    }
    for(auto u : ch[v]) {
        dfs(u, mo - (double)cnt[u] / 2.);
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
    cnt.resize(n);
    ans.resize(n);
    ch.resize(n);
    par.resize(n);
    forn(i,1,n) {
        scanf("%d", &par[i]);
        par[i]--;
        ch[par[i]].pb(i);
    }
    c(0);
    dfs(0,0);
    forn(i,0,n) printf("%.10lf ", ans[i]);
    
}