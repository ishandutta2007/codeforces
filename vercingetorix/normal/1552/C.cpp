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
int n, k;
vi to;
int inter(pi a, pi b) {
    vi x;
    x.pb(a.first);
    x.pb(b.first);
    x.pb(a.second);
    x.pb(b.second);
    to[a.first] = 1;
    to[a.second] = 1;
    to[b.first] = 2;
    to[b.second] = 2;
    srt(x);
    if(to[x[0]] == to[x[2]]) return 1;
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d\n", &n, &k);
        vi used(2*n, 0);
        to.resize(2*n);
        vpi e;
        forn(i,0,k) {
            int x,y;
            scanf("%d %d", &x, &y);
            x--; y--;
            used[x] = 1;
            used[y] = 1;
            e.pb(mp(x,y));
        }
        vi lf;
        forn(i,0,2*n) if(used[i] == 0) lf.pb(i);
        forn(i,0,n-k) {
            e.pb(mp(lf[i], lf[i+n-k]));
        }
        int ans = 0;
        forn(i,0,n) forn(j,i+1,n) {
            ans += inter(e[i], e[j]);
        }
        printf("%d\n", ans);
        
        
    }
    
}