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


const int INF =1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int l,r;
    cin>>l>>r;
    r-=(l-1);
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    vvpi g(23);
    int num = 0;
    forn(i,2,22) {
        forn(j,i+1,22) {
            g[i].pb(mp(j, d2[21-j]));
        }
        g[i].pb(mp(22, 1));
    }
    
//    forn(i,1,21) {
//        forn(j,i+1,22) {
//            g[i].pb(mp(j, d2[20-i]));
//        }
//    }
    int F = r;
    vi bits;
    forn(i,0,20) if(F&d2[i]) bits.pb(i);
//    reverse(all(bits));
    int cur = F;
    forn(j,0,bits.size()) {
        if(j+1==bits.size()) continue;
        int cbit = bits[j+1];
        g[0].pb(mp(21-bits[j], cur-d2[bits[j]]));
        cur-=d2[bits[j]];
    }
    int bb = bits.back();
    g[0].pb(mp(22, 1));
    g[0].pb(mp(1, 1));
//    forn(i,0,bb) g[0].pb(mp(21-i, d2[i]));
    if(bb>0) {
        forn(i,1,bb) g[1].pb(mp(21-i, d2[i] - 1));
        g[1].pb(mp(22,1));
//        g[0].pb(mp(1, 1));
//        g[1].pb(mp(1, d2[bb]-1));
    }
    forn(i,0,g[0].size()) g[0][i].second += l-1;
    printf("YES\n");
    int cnt = 0;
    forn(i,0,23) cnt+=g[i].size();
    printf("%d %d\n", 23, cnt);
    forn(i,0,23) for(auto x : g[i]) {
        printf("%d %d %d\n", i+1, x.first+1, x.second);
    }
 
}