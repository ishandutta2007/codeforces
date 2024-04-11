#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(c,n);
    forn(i,0,n) c[i]--;
    vvi par(n);
    vvi ch(n);
    forn(i,0,n) {
        int k;
        read(k);
        while(k--) {
            int x;
            read(x);
            x--;
            ch[x].pb(i);
            par[i].pb(x);
        }
    }
    int ans = 1e9;
    forn(s,0,3) {
        vvi av(3);
        vi deg(n, 0);
        forn(i,0,n) deg[i] = par[i].size();
        forn(i,0,n) if(par[i].empty()) {
            av[c[i]].pb(i);
        }
        int cur = s;
        int done = 0;
        int cand = n;
        while(1) {
            while(!av[cur].empty()) {
                int v = av[cur].back();
                av[cur].pop_back();
                done++;
                for(auto x : ch[v]) {
                    deg[x]--;
                    if(deg[x] == 0) av[c[x]].pb(x);
                }
            }
            if(done == n) break;
            cand++;
            cur++;
            if(cur==3) cur =0;
        }
        ans = min(ans,cand);
        
    }
    cout<<ans;
    
}