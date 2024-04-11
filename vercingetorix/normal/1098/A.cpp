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
vi p;
vvi ch;
vi a;
vi s;
int can = 1;
void dfs(int v) {
    if(v == 0) a[v] = s[v];
    else {
        if(s[v] >= 0) a[v] = s[v] - s[p[v]];
        else {
            if(ch[v].empty()) a[v] = 0;
            else {
                s[v] = s[ch[v][0]];
                for(auto u : ch[v]) s[v] = min(s[v], s[u]);
                if(s[v] < s[p[v]]) {
                    printf("-1\n");
                    exit(0);
                }
                a[v] = s[v] - s[p[v]];
            }
        }
    }
    for(auto u : ch[v]) dfs(u);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    p.resize(n);
    ch.resize(n);
    a.resize(n);
    s.resize(n);
    forn(i,1,n) {
        scanf("%d", &p[i]);
        p[i]--;
        ch[p[i]].pb(i);
    }
    forn(i,0,n) scanf("%d", &s[i]);
//    readv(s,n);
    dfs(0);
    ll ans=  0;
    for(auto x  : a) ans+=x;
    cout<<ans;
//    a[0] = s[0];
//    int ans = s[0];
    
    
}