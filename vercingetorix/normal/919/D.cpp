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
const int A= 300000;
vector<int> g[A]; // 
bool used[A];
vector<int> ans;
int n;
void dfs (int v) {
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

int d[A][26];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d\n", &n, &m);
    string s;
    getline(cin, s);
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        if(u==v) {
            cout<<-1;
            return 0;
        }
        g[u].pb(v);
    }
    topological_sort();
    vi pos(n,-1);
    forn(i,0,n) pos[ans[i]] = i;
    int res = 0;
    for(int i = n-1; i>=0; i--) {
        int v = ans[i];
        d[v][s[v]-'a'] = max(d[v][s[v]-'a'], 1);
        for(auto u : g[v]) {
            if(pos[u] < i) {
                cout<<-1;
                return 0;
            }
            d[v][s[v]-'a'] = max(d[v][s[v]-'a'], d[u][s[v]-'a'] + 1);
            forn(c,0,26) {
                d[v][c] = max(d[u][c], d[v][c]);
                res = max(res, d[v][c]);
            }
            
        }
    }
    cout<<res;
}