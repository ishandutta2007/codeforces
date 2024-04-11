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
int n,k;
const int A = 300500;
int parent[A];
vi lst[A];
int fix[A];
int opp[A];

void make_set (int v) {
    parent[v] = v;
    lst[v] = vi(1,v);
    fix[v] = -1;
    opp[v] = -1;
}

int find_set (int v) {
    return parent[v];
}
int bad = 0;

void simple_union(int a, int b) {
    a = parent[a];
    b = parent[b];
    if (a != b) {
        if(lst[a].size() < lst[b].size()) swap(a,b);
        for(auto x : lst[b]) {
//            if(parent[x^1] == a) bad++;
            parent[x] = a;
            lst[a].pb(x);
        }
        lst[b].clear();
        fix[parent[a]] = max(fix[a], fix[b]);
    }
}

void union_sets (int a, int b) {
    a = parent[a];
    b = parent[b];
    if(a==b) return;
    simple_union(a, b);
    int c = parent[a];
    int oa = opp[a];
    int ob = opp[b];
    if(opp[a] != -1 || opp[b] != -1) {
        int oc;
        if(opp[a] != -1 && opp[b] != -1) {
            simple_union(opp[a], opp[b]);
            oc = parent[oa];
        }
        if(oa != -1) oc = parent[oa];
        else oc = parent[ob];
        opp[c] = oc;
        opp[oc] = c;
        if(fix[c] != -1) fix[oc] = 1-fix[c];
        if(fix[oc] != -1) fix[c] = 1-fix[oc];
    }
}

void opp_sets(int a, int b) {
    a = parent[a];
    b = parent[b];
    if(opp[a] != -1) union_sets(opp[a], b);
    else if(opp[b] != -1) union_sets(opp[b], a);
    else {
        opp[a] = b;
        opp[b] = a;
        if(fix[a] != -1) fix[b] = 1-fix[a];
        if(fix[b] != -1) fix[a] = 1-fix[b];
    }
}

void fix_set(int a, int v) {
    a = parent[a];
    fix[a] = v;
    if(opp[a] != -1) fix[opp[a]] = 1-v;
}

int cnt(int a) {
    a = parent[a];
    if(fix[a] != -1) {
        if(fix[a] == 1) return fix[a] * int(lst[a].size());
        else if(opp[a] != -1) return lst[opp[a]].size();
        else return 0;
    }
    else if(opp[a] != -1) return min(lst[a].size(), lst[opp[a]].size());
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d %d\n", &n, &k);
    char c[300500];
    scanf("%s", c);
    vvi w(n);
    forn(i,0,k) {
        int m;
        scanf("%d", &m);
        forn(j,0,m) {
            int x;
            scanf("%d", &x);
            x--;
            w[x].pb(i);
        }
    }
    forn(i,0,k) make_set(i);
    forn(i,0,n) {
        if(w[i].size() == 1) {
            int v = w[i][0];
            bad -= cnt(v);
            if(c[i] == '0') fix_set(v, 1);
            else fix_set(v, 0);
            bad += cnt(v);
        }
        else if(w[i].size() == 2) {
            int v = w[i][0];
            int u = w[i][1];
            if(c[i] == '1' && parent[u] == parent[v]) {
                printf("%d\n", bad);
                continue;
            }
            if(c[i] == '0' && opp[parent[u]] == parent[v]) {
                printf("%d\n", bad);
                continue;
            }
            bad -= cnt(v);
            bad -= cnt(u);
            if(c[i] == '0') opp_sets(v, u);
            else union_sets(v, u);
            bad += cnt(v);
        }
        printf("%d\n", bad);
    }
    
    
}