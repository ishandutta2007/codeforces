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
struct len{
    len() {forn(i,0,5) a[i] = 0; forn(i,0,5) b[i] = 0;};
    ll a[5];
    ll b[5];
};

int n,k;
vvi nb;
ll ans = 0;

len dfs(int v, int p) {
    vector<len> q;
    len sum;
    for (auto u : nb[v]) {
        if (u == p) continue;
        q.pb(dfs(u, v));
        forn(j,0,k) sum.a[j] += q.back().a[j];
        forn(j,0,k) sum.b[j] += q.back().b[j];
    }
//    cout<<endl;
    for (auto x : q) {
        forn(i,0,k) forn(j,0,k) {
            ans += (sum.b[i] - x.b[i]) * x.a[j] +  (sum.a[i] - x.a[i]) * x.b[j];
            if (i+j > 0) ans += (sum.a[i] - x.a[i]) * x.a[j];
            if (i+j > k) ans += (sum.a[i] - x.a[i]) * x.a[j];
        }
    }
    forn(i,0,k) {
        ans += 2*sum.b[i];
        if(i>0) ans += 2*sum.a[i];
    }
    len res;
    forn(j,0,k) {
        res.a[(j+1)%k] = sum.a[j];
        res.b[(j+1)%k] = sum.b[j];
        res.b[0] += res.a[0];
    }
    res.a[1%k]++;
    if(k==1) res.b[0]++;
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &k);
    nb.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v); nb[v].pb(u);
    }
    dfs(0,-1);
    cout<<ans/2;
    
}