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

const int MAXN = 100000;
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

vi l;
vvpi nb;
void dfsl(int v, int p) {
    for(auto u : nb[v]) {
        if(u.first == p) continue;
        l[u.first] = l[v] ^ u.second;
        dfsl(u.first, v);
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
    l.resize(n);
    vpi e;
    vi w;
    forn(i,0,n) make_set(i);
    nb.resize(n);
    forn(i,0,m) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        if(find_set(u) == find_set(v)) {
            e.pb(mp(u,v));
            w.pb(c);
        }
        else {
            nb[u].pb(mp(v, c));
            nb[v].pb(mp(u, c));
            union_sets(u, v);
        }
    }
    l[0] = 0;
    dfsl(0, -1);
    vi cycle;
    forn(i,0,e.size()) {
        cycle.pb(l[e[i].first] ^ l[e[i].second] ^ w[i]);
    }
    int pt = 0;
    vi beat;
    for(int bit = 30; bit >=0; bit--) {
        bool can = false;
        for(int i = pt; i < cycle.size(); i++) {
            if(cycle[i] & (1<<bit)) {
                can = true;
                swap(cycle[i], cycle[pt]);
                break;
            }
        }
        if(can) {
            beat.pb(bit);
            forn(i,pt+1,cycle.size()) {
                if(cycle[i] & (1<<bit)) cycle[i] ^= cycle[pt];
            }
            pt++;
        }
    }
    int ans = l[n-1];
    forn(i,0,pt) {
        if(ans & (1<<beat[i])) ans ^= cycle[i];
    }
    cout<<ans;
    
    
}