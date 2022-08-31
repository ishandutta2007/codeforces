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
int go[200100];
int num[200100];
set<int> e[200100];
int n,m,k;
int ans = 0;
void kill(int v) {
    if(go[v] == 0) return;
    go[v] = 0;
    ans --;
    for(auto u : e[v]) {
        num[u] --;
        e[u].erase(v);
    }
    for (auto u : e[v]) {
        if(num[u] < k && go[u] == 1) kill(u);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    read(m);
    read(k);
    vpi ed;
    forn(i,0,m) {
        int u,v;
        read(u); read(v);
        u--; v--;
        e[u].insert(v);
        e[v].insert(u);
        num[u] ++;
        num[v] ++;
        ed.pb(mp(u,v));
    }
    forn(i,0,n) go[i] = 1;
    ans = n;
    forn(i,0,n) if(num[i] < k) kill(i);
    vi res;
    res.pb(ans);
    reverse(all(ed));
    for(auto px : ed) {
        int u = px.first;
        int v = px.second;
        if(go[u] == 1 && go[v] == 1) {
            e[u].erase(v);
            e[v].erase(u);
            num[u] --;
            num[v] --;
            if (num[u] < k) kill(u);
            if (num[v] < k) kill(v);
        }
        res.pb(ans);
    }
    res.pop_back();
    reverse(all(res));
    forn(i,0,m) printf("%d\n", res[i]);
}