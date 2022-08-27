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
vvpi nb;
vd mom;

void pr(int u, int v, int ind, double mu) {
    while(mu >= 2) mu -= 2;
    while(mu < 0) mu+=2;
    printf("1 %d ", ind+1);
    if(mu < 1) printf("%d %d %.10lf\n", v+1, u+1, 1-mu);
    else printf("%d %d %.10lf\n", u+1, v+1, 2-mu);
    
}

void dfs(int v, int p) {
    if (v == 0) {
        int k = nb[v].size();
        forn(i,0,k) {
            auto u = nb[v][i];
            pr(0, u.first, u.second, (ld)i*(ld)2./(ld)k);
            mom[u.first] = 1+(ld)i*(ld)2./(ld)k;
            if(mom[u.first] >= 2) mom[u.first] -= 2;
        }
    }
    else {
        int k = nb[v].size();
        int ki=0;
        ld s = mom[v];
        forn(i,0,k) {
            auto u = nb[v][i];
            if(u.first == p) continue;
            ki++;
            pr(v, u.first, u.second, s+(ld)ki*(ld)2./(ld)k);
            mom[u.first] = 1+s+(ld)ki*(ld)2./(ld)k;
            while(mom[u.first] >= 2) mom[u.first] -= 2;
        }
    }
    for(auto u : nb[v]) {
        if(u.first != p)
        dfs(u.first, v);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    nb.resize(n);
    mom.resize(n);
    forn(i,0,n-1) {
        int u,v;
        cin>>u>>v;
        u--; v--;
        nb[u].pb(mp(v,i));
        nb[v].pb(mp(u,i));
    }
    printf("%d\n", n-1);
    dfs(0,-1);
    
}