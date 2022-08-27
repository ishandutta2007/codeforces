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
int n;
vi par;
vvi ch;
vi lev;

void dfs(int v) {
    for(auto u : ch[v]) {
        lev[u] = lev[v] + 1;
        dfs(u);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    vi a(n);
    ch.resize(n);
    par.resize(n);
    lev.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,1,n) scanf("%d", &par[i]);
    forn(i,1,n) par[i]--;
    forn(i,1,n) ch[par[i]].pb(i);
    lev[0] = 0;
    dfs(0);
    int lst=0;
    forn(i,0,n) if(ch[i].empty()) lst= i;
    
    vi nim;
    vi oth;
    map<int, ll> cnt;
    forn(i,0,n) {
        if(lev[i]%2 == lev[lst]%2) nim.pb(a[i]);
        else oth.pb(a[i]);
    }
    for(auto x : oth) cnt[x]++;
    int state = 0;
    for(auto x : nim) state^=x;
    ll ans = 0;
    for(auto x : nim) ans += cnt[x^state];
    if(state == 0) {
        ll k = nim.size();
        ll l = oth.size();
        ans += (k*(k-1)+l*(l-1))/2;
    }
    cout<<ans;
}