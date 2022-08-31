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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    
    vpi ice;
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x,&y);
        ice.pb(mp(x,y));
    }
    sort(all(ice));
    vpi evx;
    forn(i,0,n) {
//        if(evx.empty() || evx.back().first != ice[i].first) {
            evx.pb(mp(ice[i].first + k, i));
            evx.pb(mp(ice[i].first, i));
//        }
    }
    vi u(n,0);
    sort(all(evx));
    multiset<pi> evy;
    vll ans(n+1,0);
    forn(proc,0,2*n-1) {
        int i = evx[proc].second;
        if(u[i] == 0) {
            evy.insert(mp(ice[i].second, 1));
            evy.insert(mp(ice[i].second+k, -1));
            u[i] = 1;
        }
        else {
            evy.erase(evy.find(mp(ice[i].second, 1)));
            evy.erase(evy.find(mp(ice[i].second+k, -1)));
            u[i] = 0;
        }
        ll krat = evx[proc+1].first - evx[proc].first;
        if(krat==0) continue;
        int num = 0;
        int prevy = 0;
        for(auto u : evy) {
            ans[num] += (u.first-prevy)*krat;
            prevy = u.first;
            num+=u.second;
        }
    }
    forn(i,1,n+1) printf("%lld ", ans[i]);
}