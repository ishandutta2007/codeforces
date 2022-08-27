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
const int N = 1000010;
int parent[N+1];
int rk[N+1];
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    
    int n,q;
    scanf("%d %d", &n, &q);
    readv(a,n);
    vvi ap(n);
    for(auto x : pr) make_set(x);
    forn(i,0,n) {
        int u = a[i];
        while(u!=1) {
            int d = mindiv[u];
            ap[i].pb(d);
            while(u % d ==0) u /= d;
        }
        forn(j,0,ap[i].size()) forn(k,j+1,ap[i].size()) union_sets(ap[i][j], ap[i][k]);
    }
    set<pi> can1;
    forn(i,0,n) {
        int u = a[i] + 1;
        vi x(1, ap[i][0]);
        while(u!=1) {
            int d = mindiv[u];
            x.pb(d);
            while(u % d ==0) u /= d;
        }
        forn(j,0,x.size()) forn(k,j+1,x.size()) {
            int p1 = find_set(x[j]);
            int p2 = find_set(x[k]);
            if(p2<p1) swap(p1,p2);
            can1.insert(mp(p1,p2));
        }
    }
    forn(i,0,q) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        int p1 = find_set(ap[u][0]);
        int p2 = find_set(ap[v][0]);
        if(p2 < p1) swap(p1, p2);
        if(p1 == p2) printf("0\n");
        else if(can1.find(mp(p1, p2)) != can1.end()) printf("1\n");
        else printf("2\n");
    }
    
}