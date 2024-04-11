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

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,w,h;
    scanf("%d %d %d", &n, &w, &h);
    set<int> apos;
    vi g(n), p(n), t(n);
    map<int, vpi> x;
    map<int, vpi> y;
    forn(i,0,n) {
        scanf("%d %d %d", &g[i], &p[i], &t[i]);
        apos.insert(t[i] - p[i]);
        if(g[i] == 1) x[t[i] - p[i]].pb(mp(p[i], i));
        else y[t[i] - p[i]].pb(mp(p[i],i));
    }
    vi xa(n), ya(n);
    
    for(auto d : apos) {
        int cx = x[d].size();
        int cy = y[d].size();
        sort(all(x[d]));
        sort(all(y[d]));
        reverse(all(y[d]));
        vi inds;
        for(auto u : y[d]) inds.pb(u.second);
        for(auto u : x[d]) inds.pb(u.second);
        forn(i,0,inds.size()) {
            int fr = inds[i];
            int to = inds[(i+cy)%(cx+cy)];
            if(g[to] == 1) {
                xa[fr] = p[to];
                ya[fr] = h;
            }
            else {
                xa[fr] = w;
                ya[fr] = p[to];
            }
        }
    }
    
    forn(i,0,n) printf("%d %d\n", xa[i], ya[i]);
    
}