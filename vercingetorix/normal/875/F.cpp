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
int parent[MAXN];
int en[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
    en[v] = 0;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    en[a]++;
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        en[a] += en[b];
        en[b] = 0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) make_set(i);
    vector<pair<int, pi>> pr;
    forn(i,0,m) {
        int a,b,w;
        scanf("%d %d %d", &a, &b, &w);
        pr.pb(mp(w, mp(a-1, b-1)));
    }
    sort(all(pr));
    reverse(all(pr));
    ll ans = 0;
    for(auto x : pr) {
        int w = x.first;
        int a = find_set(x.second.first);
        int b = find_set(x.second.second);
        if(a == b) {
            if(lst[a].size() >= en[a] + 1) {
                ans += w;
                en[a]++;
            }
        }
        else {
            if(lst[a].size() + lst[b].size() >= en[a] + en[b] + 1) {
                union_sets(a, b);
                ans += w;
            }
        }
    }
    cout << ans;
}