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

vector<pi> g[101]; // 
bool used[101];
vector<int> ans;
int n;
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
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
int d[120][120][26];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    forn(i,0,m) {
        int u,v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        u--; v--;
        g[u].pb(mp(v,int(c-'a')));
    }
    topological_sort();
    for(int i = n-1; i>=0; i--) {
        for(int j = n-1; j>=i; j--) {
            forn(s,0,26) {
                int v = ans[i];
                int u = ans[j];
                int winvu = 0;
                int winuv = 0;
                for(auto x : g[v]) if(x.second >= s && d[u][x.first][x.second] == 0) d[v][u][s] = 1;
                for(auto x : g[u]) if(x.second >= s && d[v][x.first][x.second] == 0) d[u][v][s] = 1;
            }
        }
    }
    string res = "BA";
    forn(i,0,n) {
        forn(j,0,n) printf("%c", res[d[i][j][0]]);
        printf("\n");
    }
    
}