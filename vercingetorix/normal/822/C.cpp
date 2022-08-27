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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,x;
    scanf("%d %d", &n, &x);
    int A = 200000;
    vvi re(A+1);
    vvi le(A+1);
    vi l(n), r(n), c(n);
    vector<multiset<int>> cost(A+1);
    forn(i,0,n) {
        scanf("%d %d %d", &l[i], &r[i], &c[i]);
        re[r[i]].pb(i);
        le[l[i]].pb(i);
        cost[r[i]-l[i]+1].insert(c[i]);
    }
    const int INF = 2e9 + 100;
    int ans = INF;
    forn(i,0,A) {
        for(auto ind : le[i]) cost[r[ind]-l[ind]+1].erase(cost[r[ind]-l[ind]+1].find(c[ind]));
        for(auto ind : re[i]) {
            int len = r[ind]-l[ind]+1;
            if(len < x && !cost[x-len].empty()) ans = min(ans, c[ind] + *cost[x-len].begin());
        }
    }
    if(ans == INF) ans = -1;
    cout<<ans;
    
}