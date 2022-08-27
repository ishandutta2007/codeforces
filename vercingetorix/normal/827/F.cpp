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

vector<pair<pi, int>> e[1000000];
int pt[1000000];
vi l,r;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int INF = 2e9;
    int n,m;
    scanf("%d %d", &n, &m);
    vi tmin(n, INF);
    l.resize(m);
    r.resize(m);
    vi t(2*n, -1);
    t[0] = 0;
    set<pi> ev;
    ev.insert(mp(0,0));
    forn(i,0,m) {
        int u,v;
        scanf("%d %d %d %d", &u, &v, &l[i], &r[i]);
        u--; v--;
        e[2*u].pb(mp(mp(l[i], r[i]), 2*v+1));
        e[2*u+1].pb(mp(mp(l[i], r[i]), 2*v));
        e[2*v].pb(mp(mp(l[i], r[i]), 2*u+1));
        e[2*v+1].pb(mp(mp(l[i], r[i]), 2*u));
    }
    forn(i,0,2*n) sort(all(e[i]));
    while(!ev.empty()) {
        int v = ev.begin() -> second;
        int curt = ev.begin() -> first;
        tmin[v/2] = min(tmin[v/2], curt);
        ev.erase(ev.begin());
        while(pt[v] < e[v].size() && e[v][pt[v]].first.first <= t[v]) {
            auto x = e[v][pt[v]];
            pt[v]++;
            int tgo = max(curt, x.first.first);
            if(tgo % 2 != curt % 2) tgo++;
            if(tgo >= x.first.second) continue;
            int nt = tgo+1;
            int to = x.second;
            ev.insert(mp(nt, to));
            t[to] = max(t[to], x.first.second);
            if(t[to]%2 != nt%2) t[to]--;
        }
    }
    int ans = tmin[n-1];
    if(ans == INF) ans = -1;
    cout<<ans;
}