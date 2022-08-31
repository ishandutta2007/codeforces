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
vll a;
int n,r;
//ll ans = 0;
vll s;
//set<pi> ans;
vvi ans;

void check(int l, int r) {
    if(l<0 || r>=n) return;
    if(r-l < 2) return;
    ll sum = s[r-1];
    sum-=s[l];
//    cout<<l<<' '<<r<<' '<<sum<<' '<<(a[l]^a[r]) <<endl;
//    if (sum == (a[l]^a[r])) ans++;
    if (sum == (a[l]^a[r])) ans[l].pb(r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n); a.resize(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    ans.resize(n);
    ll cur = 0;
    vll d2(1,1);
    forn(i,0,30) d2.pb(d2.back()*2);
    vvi maxd(30);
    vi md(n);
    forn(i,0,n) {
        cur += a[i];
        s.pb(cur);
        int u = 30;
        while(d2[u] > a[i]) u--;
        maxd[u].pb(i);
        md[i] = u;
    }
    forn(u,0,30) {
        vi dp;
        dp.pb(-2);
        dp.pb(-1);
        forn(i,0,n) if(md[i] == u) dp.pb(i);
        dp.pb(n);
        dp.pb(n+1);
        int nn = dp.size() - 4;
        forn(pt,1,dp.size()-2) {
            forn(i,dp[pt],dp[pt+1]+1) {
                check(dp[pt-1], i);
                check(dp[pt], i);
                check(i,dp[pt+1]);
                check(i,dp[pt+2]);
            }
        }
    }
//    forn(i,0,n) {
//        set<int> p;
//        forn(u,0,30) {
//            int ind = lower_bound(all(maxd[u]), i) - maxd[u].begin();
//            int l = maxd[u].size();
//            if(ind < l) p.insert(maxd[u][ind]);
//            if(ind+1 < l) p.insert(maxd[u][ind+1]);
//            if(ind-1 >= 0) p.insert(maxd[u][ind-1]);
//            if(ind-2 >= 0) p.insert(maxd[u][ind-2]);
//        }
//        for(auto x : p) {
//            int l = i;
//            int r = x;
//            if(r<l) swap(r,l);
//            if(r-l < 2) continue;
//            check(l, r);
//        }
//    }
    ll cans=0;
    forn(i,0,n) {
        sort(all(ans[i]));
        forn(j,0,ans[i].size()) if(j==0 || ans[i][j]!=ans[i][j-1]) cans++;
    }
    cout<<cans;
}