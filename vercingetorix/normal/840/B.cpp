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
const int MAXN = 400000;
int parent[MAXN];
int rk[MAXN];

void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
vvpi nb;
vi cnt;
vi ans;
int dfs1(int v, int p) {
    int tot = 0;
    for(auto u : nb[v]) {
        if(u.first == p) continue;
        int k = dfs1(u.first, v);
        if (k%2==1) ans.pb(u.second);
        tot += k;
    }
    return tot + cnt[v];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    int cp = 0, cm = 0, c0 = 0;
    vi a(n);
    forn(i,0,n) {
        make_set(i);
        scanf("%d", &a[i]);
        if(a[i] == -1) cm++;
        else if(a[i] == 0) c0++;
        else cp++;
    }
    if(cm == 0 && cp%2 == 1) {
        cout<<-1;
        return 0;
    }
    nb.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(find_set(u) == find_set(v)) continue;
        nb[u].pb(mp(v,i+1));
        nb[v].pb(mp(u,i+1));
        union_sets(u, v);
    }
    cnt = vi(n,0);
    forn(i,0,n) {
        if(a[i] == 1) cnt[i] = 1;
    }
    if(cp %2==1) {
        forn(i,0,n) {
            if(a[i] == -1) {
                cnt[i] = 1;
                break;
            }
        }
    }
    dfs1(0,-1);
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d\n", x);
    
    
}