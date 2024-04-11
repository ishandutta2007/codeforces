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
int n,m;
int orient(int a, int b, int c) {
    vpi u;
    u.pb(mp(a,0));
    u.pb(mp(b,1));
    u.pb(mp(c,2));
    srt(u);
    int inv = 0;
    forn(i,0,3) forn(j,i+1,3) if(u[i].second > u[j].second) inv++;
    return inv%2;
}
bool eq(pi a, pi b) {
    if(a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second) return true;
    return false;
}

vvi g;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    g.resize(m);
    vpi e;
    forn(i,0,m) {
        int a,b;
        scanf("%d %d", &a, &b);
        e.pb(mp(a,b));
    }
    forn(i,0,m) forn(j,i+1,m) {
        if(orient(e[i].first, e[i].second, e[j].first) != orient(e[i].first, e[i].second, e[j].second) && !eq(e[i], e[j])) {
            g[i].pb(j);
            g[j].pb(i);
        }
    }
    
    vector<char> part (m, -1);
    bool ok = true;
    vector<int> q (m);
    for (int st=0; st<m; ++st)
        if (part[st] == -1) {
            int h=0, t=0;
            q[t++] = st;
            part[st] = 0;
            while (h<t) {
                int v = q[h++];
                for (size_t i=0; i<g[v].size(); ++i) {
                    int to = g[v][i];
                    if (part[to] == -1)
                        part[to] = !part[v],  q[t++] = to;
                    else
                        ok &= part[to] != part[v];
                }
            }
        }
    if(ok == false) cout<<"Impossible";
    else forn(i,0,m) if(part[i] == 0) cout<<'i'; else cout<<'o';
    
}