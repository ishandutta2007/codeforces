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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int r,g;
    cin>>r>>g;
    int tot = r+g;
    int w = 0;
    while((w+1)*(w+2)/2 <= tot) w++;
    vector<vector<ll>> d(2, vector<ll>(r+1,0));
    d[0][r] = 1;
    forn(l, 0, w) {
        int l1 = (l+1)%2;
        int l0 = l%2;
        int t = (l+1)*(l+2)/2;
        forn(u, 0, max(r-l,0)) {
            d[l1][u] = d[l0][u+l+1];
        }
        forn(u,max(r-l,0),r+1) d[l1][u]=0;
        forn(u,0, min(r+g-t+1,r+1)) {
            d[l1][u] += d[l0][u];
            d[l1][u] = (d[l1][u])%mod;
        }
    }
    ll ans = 0;
    forn(i,0,r+1) ans=(ans+d[w%2][i]) % mod;
    
    
     cout<<ans;
}