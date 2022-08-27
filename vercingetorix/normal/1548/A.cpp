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
vector<set<int>> g;

int test(int i) {
    if(g[i].empty()) return 1;
    else {
        auto it =  g[i].end();
        it--;
        if(*it < i) return 1;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g = vector<set<int>>(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ans = 0;
    forn(i,0,n) {
        ans += test(i);
    }
    int q;
    read(q);
    while(q--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 3) printf("%d\n", ans);
        else {
            int u,v;
            scanf("%d %d\n", &u, &v);
            u--; v--;
            ans -= test(u) + test(v);
            if(tp == 1) {
                g[u].insert(v);
                g[v].insert(u);
            }
            else {
                g[u].erase(v);
                g[v].erase(u);
            }
            ans += test(u) + test(v);
        }
    }
    
}