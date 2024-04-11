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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int A = 200000;
vi dv[A+1];
int cnt[A+1];
int lev = 0;
vi nb[A+1];
int val[A+1];
int ans[A+1];

void dfs(int v, int p) {
    lev++;
    int cur = val[v];
    for(auto x : dv[cur]) cnt[x]++;
    for(auto x : dv[cur]) {
        if (x > ans[v] && cnt[x] >= lev-1) ans[v] = x;
    }
    if(p >= 0) {
        for(auto x : dv[val[p]]) {
            if (x > ans[v] && cnt[x] >= lev-1) ans[v] = x;
        }
    }
    for(auto u : nb[v]) {
        if(u != p) dfs(u, v);
    }
    lev--;
    for(auto x : dv[cur]) cnt[x]--;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,1,200001) {
        int cur = i;
        while(cur <= A) {
            dv[cur].pb(i);
            cur += i;
        }
    }
    int n;
    scanf("%d", &n);
    forn(i,0,n) {
        scanf("%d", &val[i]);
    }
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v);
        nb[v].pb(u);
    }
    ans[0] = val[0];
    dfs(0,-1);
    forn(i,0,n) printf("%d ", ans[i]);
}