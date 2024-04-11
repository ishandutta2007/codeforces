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
vpi e;
vector<map<int,int>> best;
vi lux;
int L,n,p,t;
vi l;
vi r;
int greed(int i, int st) {
    int s = st - l[i];
    int tos = r[i] - st;
    if(tos < p) {
        if(i<n-1) return lux[i+1];
        else return 0;
    }
    int res;
    if(best[i][s%p] != 0) {
        res = best[i][s%p] - s/p;
    }
    else {
        
        res = tos / p;
        int x = st + res*p + t;
        auto it = lower_bound(all(e), mp(x,0));
        if(it != e.end()) {
            int ind = it->second;
            if(it->first == l[ind]) res+=lux[ind];
            else {
                res += greed(ind, x);
            }
        }
        best[i][s%p] = res + s/p;
    }
    if(i<n-1) res = max(res, lux[i+1]);
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d %d", &L, &n,&p,&t);
   
    int ans = 0;
    best.resize(n);
    l.resize(n);
    r.resize(n);
    lux.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &l[i], &r[i]);
        e.pb(mp(l[i],i));
        e.pb(mp(r[i],i));
    }
    
    for(int i = n-1; i>=0; i--) {
        lux[i] = greed(i, l[i]);
        ans = max(ans, lux[i]);
    }
    cout<<ans;
    
}