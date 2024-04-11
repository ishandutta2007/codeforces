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

const int MAXN = 100000;
vi cap;
vvi gcap;
bool bad = false;
vi vis;
void dfs(int v) {
    vis[v] = 1;
    for(auto u : gcap[v]) if(!vis[u]) {
        if(cap[u] == -1) {
            bad = true;
        }
        if(cap[u] != 1) {
            cap[u] = 1;
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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n);
    vi l(n);
    forn(i,0,n) {
        scanf("%d", &l[i]);
        a[i].resize(l[i]);
        forn(j,0,l[i]) scanf("%d", &a[i][j]);
    }
    cap = vi (m+1,0);
    vis = vi (m+1,0);
    gcap = vvi (m+1);
    forn(i,0,n-1) {
        int pt = 0;
        while(pt<min(l[i], l[i+1]) && a[i][pt] == a[i+1][pt]) pt++;
        if(pt >= min(l[i], l[i+1])) {
            if(l[i] > l[i+1]) {
                printf("No");
                return 0;
            }
        }
        else {
            if(a[i][pt] > a[i+1][pt]) {
                if(cap[a[i][pt]] == -1 || cap[a[i+1][pt]] == 1) {
                    printf("No");
                    return 0;
                }
                cap[a[i][pt]] = 1;
                cap[a[i+1][pt]] = -1;
            }
            else {
                gcap[a[i+1][pt]].pb(a[i][pt]);
            }
        }
    }
    forn(i,1,m+1) if(cap[i] == 1 && !vis[i]) dfs(i);
    if(bad) {
        printf("No");
        return 0;
    }
    vi ans;
    forn(i,1,m+1) if(cap[i] == 1) ans.pb(i);
    printf("Yes\n");
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d ", x);
}