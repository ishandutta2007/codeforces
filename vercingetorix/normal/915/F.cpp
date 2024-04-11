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

const int MAXN = 1000000;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
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
    readv(a,n);
    vvi nb(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        nb[u].pb(v);
        nb[v].pb(u);
    }
    ll sum = 0;
    vpi x;
    forn(i,0,n) x.pb(mp(a[i], i));
    vi pos(n);
    sort(all(x));
    forn(i,0,n) pos[x[i].second] = i;
    
    forn(i,0,n) make_set(i);
    forn(i,0,n) {
        int v = x[i].second;
        vll cs;
        for(auto u : nb[v]) {
            if(pos[u] > pos[v]) continue;
            cs.pb(lst[find_set(u)].size());
            union_sets(u, v);
        }
        ll num = 0;
        ll tot = 0;
        for(auto x : cs) tot+=x;
        for(auto x : cs) num+=x*(tot-x);
        num/=2;
        num+=tot+1;
        sum+=num*ll(x[i].first);
    }
    forn(i,0,n) make_set(i);
    reverse(all(x));
    forn(i,0,n) {
        int v = x[i].second;
        vll cs;
        for(auto u : nb[v]) {
            if(pos[u] < pos[v]) continue;
            cs.pb(lst[find_set(u)].size());
            union_sets(u, v);
        }
        ll num = 0;
        ll tot = 0;
        for(auto x : cs) tot+=x;
        for(auto x : cs) num+=x*(tot-x);
        num/=2;
        num+=tot+1;
        sum-=num*ll(x[i].first);
    }
    cout<<sum;
   
    
}