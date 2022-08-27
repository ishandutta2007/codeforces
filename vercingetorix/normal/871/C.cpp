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

const int MAXN = 200000;
vector<int> lst[MAXN];
int ecnt[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
    ecnt[v] = 0;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    ecnt[a] ++;
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
        ecnt[a] += ecnt[b];
        ecnt[b] = 0;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    map<int, vpi> xtoy, ytox;
    vpi e;
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        xtoy[x].pb(mp(y,i));
        ytox[y].pb(mp(x,i));
        e.pb(mp(x,y));
    }
    int cnt = 0;
    map<int, int> xtoi, ytoi;
    for(auto x : xtoy) xtoi[x.first] = cnt++;
    for(auto y : ytox) ytoi[y.first] = cnt++;
    forn(i,0,cnt) make_set(i);
    for(auto a : e) union_sets(xtoi[a.first], ytoi[a.second]);
    ll ans = 1;
    forn(i,0,cnt) {
        ll cand = 1;
        forn(j,0,lst[i].size()) cand = (cand*2)%mod;
        if(ecnt[i] < lst[i].size()) cand--;
        ans = ans*cand%mod;
    }
    cout<<ans;
    
}