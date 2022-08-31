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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

vvi gr;

vi fr;
vll cost;

void dfs(int v) {
    fr[v] = 1;
    for(auto u : gr[v]) {
        if(!fr[u]) {
            cost[u] += cost[v];
            dfs(u);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi a(n);
    forn(i,1,n) scanf("%d", &a[i]);
    gr.resize(n);
    fr.resize(n);
    cost.resize(n);
    forn(i,1,n) {
        int s = i+a[i];
        if(s >= n) {
            fr[i] = 1;
            cost[i] = a[i];
        }
        else if(s - a[s] < 0) {
            cost[i] = a[i] + a[s];
            fr[i] = 1;
        }
        else if(s-a[s] > 0) {
            gr[s-a[s]].pb(i);
            cost[i] = a[i] + a[s];
        }
    }
    forn(i,0,n) if(fr[i]) dfs(i);
    forn(i,1,n) {
        int s = i;
        if(s - a[s] < 0) printf("%d\n", i+a[s]);
        else if(s==a[s]) printf("-1\n");
        else if(fr[s-a[s]]) printf("%lld\n", cost[s-a[s]] + i + a[s]);
        else printf("-1\n");
    }
    
}