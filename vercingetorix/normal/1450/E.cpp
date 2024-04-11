#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int INF = 1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    vvpi g(n);
    scanf("%d %d", &n, &m);
    forn(i,0,m) {
        int u,v,b;
        scanf("%d %d %d", &u, &v, &b);
        u--; v--;
        g[u].pb(mp(v, b));
        g[v].pb(mp(u, -b));
    }
    int best = -1;
    vi ans;
    forn(s,0,n) {
        vector<int> d (n, INF),  p (n);
        d[s] = 0;
        priority_queue < pair<int,int> > q;
        q.push (make_pair (0, s));
        int br = 0;
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                len = g[v][j].second;
                if(len == 0) len = 1;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    if(d[to] < 0) {
                        br = 1;
                        break;
                    }
                    p[to] = v;
                    q.push (make_pair (-d[to], to));
                }
            }
            if(br) break;
        }
        forn(i,0,n) for(auto u : g[i]) {
            if(d[i] == d[u.first]) br = 1;
        }
        if(br) continue;
        int cand = 0;
        forn(i,0,n) cand = max(d[i], cand);
        if(cand > best) {
            best = cand;
            ans = d;
        }
    }
    if(best == -1) cout<<"NO";
    else {
        printf("YES\n");
        printf("%d\n", best);
        for(auto x : ans) printf("%d ", x);
    }

    
}