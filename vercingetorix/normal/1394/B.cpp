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
int num = 0;
vvi ban;
vvi code(10, vi(10,-1));
int n,m,k;
vi conf(45,0);
int ans = 0;

void go(int l) {
    if(l==k+1) {
        ans++;
        return;
    }
    forn(p,1,l+1) {
        int cc = code[l][p];
        if(conf[cc] > 0) continue;
        if(ban[cc][cc]) continue;
        forn(i,0,num) if(ban[cc][i]) conf[i]++;
        go(l+1);
        forn(i,0,num) if(ban[cc][i]) conf[i]--;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m, &k);
    vvpi g(n);
    vvi grev(n);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--;v--;
        g[u].pb(mp(w, v));
        grev[v].pb(u);
    }
    forn(i,0,n) sort(all(g[i]));
    
    
    forn(i,1,10) forn(j,1,i+1) code[i][j] = num++;
    ban = vvi(num, vi(num, 0));
    forn(i,0,n) {
        vi cnt(num, 0);
        for(auto v : grev[i]) {
            int deg = g[v].size();
            int pt = -1;
            forn(j,0,deg) {
                if(g[v][j].second == i) {
                    pt = j+1;
                    break;
                }
            }
            cnt[code[deg][pt]]++;
        }
        forn(cd,0,num) {
            if(cnt[cd] > 1) ban[cd][cd] = 1;
            forn(cd2,cd+1,num) {
                if(cnt[cd] >0 &&cnt[cd2]>0) {
                    ban[cd][cd2] = 1;
                    ban[cd2][cd] = 1;
                }
            }
        }
    }
    go(1);
    cout<<ans;
}