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

int ban;
vector<int> g[1001]; // 
vector<int> grev[1001];
bool used[1001];
vector<int> ans;
int n;
void dfs (int v) {
    if(v==ban) return;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    vpi e;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        grev[v].pb(u);
        e.pb(mp(u,v));
    }
    vi pos(n,0);
    forn(i,0,n) {
        ban = i;
        forn(j,0,n) used[j] = 0;
        ans.clear();
        topological_sort();
        if(ans.size() < n-1) {
            continue;
        }
        forn(j,0,n-1) pos[ans[j]] = j;
        int bad= 0;
        for(auto x : e) {
            if(x.first == ban || x.second == ban) continue;
            if(pos[x.first] > pos[x.second]) {
                bad= 1;
                break;
            }
        }
        if(bad) continue;
        vi l, r;
        for(auto x : grev[i]) l.pb(pos[x]);
        for(auto x : g[i]) r.pb(pos[x]);
        sort(all(l));
        sort(all(r));
        if(l.size()<2 || r.size()<2 || l.back() < r[0]) {
            cout<<"YES";
            return 0;
        }
        int nl = l.size();
        int nr = r.size();
        if(l[nl-2] < r[0] || l[nl-1] < r[1]) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
   
    
}