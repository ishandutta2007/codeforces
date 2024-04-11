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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int A = 100500;
class dsu {
public:
    int parent[A];
    set<int> ver[A];
    set<int> pars;
    void make_set (int v) {
        parent[v] = v;
        ver[v].clear();
        ver[v].insert(v);
        pars.insert(v);
    }
    
    int find_set (int v) {
        return parent[v];
    }
    
    void union_sets (int a, int b) {
        a = parent[a];
        b = parent[b];
        if(ver[b].size() > ver[a].size()) swap(a,b);
        for(auto x : ver[b]) {
            parent[x] = a;
            ver[a].insert(x);
        }
        ver[b].clear();
        pars.erase(b);
    }
};

vpi ans;
dsu a[2];
int n,m1,m2;
void ttry(int i, int j) {
    if(i==j) return;
    if(a[0].find_set(i) != a[0].find_set(j) && a[1].find_set(i) != a[1].find_set(j)) {
        ans.pb(mp(i,j));
        m1++;
        m2++;
        a[0].union_sets(i,j);
        a[1].union_sets(i,j);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m1, &m2);
    int m[2];
    m[0] = m1;
    m[1] = m2;
    
    forn(it,0,2) {
        forn(i,0,n) a[it].make_set(i);
        forn(i,0,m[it]) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            a[it].union_sets(u, v);
        }
    }
    while(m1 < n-1 && m2 < n-1) {
        vi nn;
        forn(i,0,2) {
            auto it = a[i].pars.begin();
            nn.pb(*it);
            it++;
            nn.pb(*it);
        }
        forn(i,0,4) forn(j,i+1,4) ttry(nn[i], nn[j]);
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
}