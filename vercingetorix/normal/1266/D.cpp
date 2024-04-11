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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vll diff(n,0);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        diff[u] += w;
        diff[v] -= w;
    }
    vpll out, in;
    forn(i,0,n) {
        if(diff[i] > 0) out.pb(mp(i, diff[i]));
        else if(diff[i] < 0) in.pb(mp(i, -diff[i]));
    }
    vpi res;
    vll s;
    while(!out.empty()) {
        while(!out.empty() && out.back().second == 0) out.pop_back();
        while(!in.empty() && in.back().second == 0) in.pop_back();
        if(out.empty()) break;
        ll val = min(out.back().second, in.back().second);
        res.pb(mp(out.back().first+1, in.back().first+1));
        s.pb(val);
        out.back().second-=val;
        in.back().second-=val;
    }
    printf("%d\n", (int)s.size());
    forn(i,0,s.size()) {
        printf("%d %d %lld\n", res[i].first, res[i].second, s[i]);
    }
    
}