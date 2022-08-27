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
    scanf("%d %d", &n,&k);
    vi l(n), r(n);
    set<int> es;
    vpi ev;
    int best = 0;
    int lb = 2e9;
    int rb = -lb;
    forn(i,0,n) {
        scanf("%d %d", &l[i], &r[i]);
        ev.pb(mp(l[i], r[i]));
        es.insert(l[i]);
        es.insert(r[i]);
    }
    vi q;
    for(auto u : es) q.pb(u);
    sort(all(ev));
    int pt = 0;
    multiset<int> rend;
    int curl = -lb;
    forn(i,0,k) {
        rend.insert(ev[i].second);
        curl = ev[i].first;
        pt++;
    }
    
    while(1) {
        if((*rend.begin()) - curl+1 > best) {
            lb = curl;
            rb= *rend.begin();
            best =(*rend.begin()) - curl+1;
        }
        if(pt == ev.size()) break;
        curl = ev[pt].first;
        rend.insert(ev[pt].second);
        rend.erase(rend.begin());
        pt++;
    }
    vi ans;
    forn(i,0,n) {
        if(l[i] <= lb && r[i] >= rb) ans.pb(i+1);
        if(ans.size() == k) break;
    }
    printf("%d\n", best);
    for(auto x : ans) printf("%d ", x);
    
}