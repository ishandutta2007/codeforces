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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n;
        read(n);
        vvi a(2, vi(n));
        forn(i,0,n) scanf("%d", &a[0][i]);
        forn(i,0,n) scanf("%d", &a[1][i]);
        vvpi g(n+1);
        forn(i,0,n) {
            g[a[0][i]].pb(mp(a[1][i], i));
            g[a[1][i]].pb(mp(a[0][i], i));
        }
        int can = 1;
        vi ans;
        forn(i,1,n+1) if(g[i].size() != 2) can = 0;
        if(can == 0) {
            printf("-1\n");
            continue;
        }
        vvi g2(n);
        forn(i,1,n+1) {
            int u = g[i][0].second;
            int v = g[i][1].second;
            g2[u].pb(v);
            g2[v].pb(u);
        }
        vi vis(n,0);
        forn(i,0,n) {
            if(vis[i] == 0) {
                vis[i] = 1;
                int cur = i;
                vi ord(1,i);
                while(1) {
                    if(vis[g2[cur][0]] == 0) {
                        cur = g2[cur][0];
                        ord.pb(cur);
                        vis[cur] = 1;
                    }
                    else if(vis[g2[cur][1]] == 0) {
                        cur = g2[cur][1];
                        ord.pb(cur);
                        vis[cur] = 1;
                    }
                    else break;
                }
                vi sw1;
                vi sw2;
                forn(i,0,ord.size()){
                    if(i == 0 || a[0][ord[i-1]] == a[0][ord[i]] || a[1][ord[i-1]] == a[1][ord[i]]) {
                        sw1.pb(ord[i]);
                        swap(a[0][ord[i]], a[1][ord[i]]);
                    }
                    else sw2.pb(ord[i]);
                }
                if(sw1.size() > sw2.size()) for(auto x : sw2) ans.pb(x);
                else for(auto x : sw1) ans.pb(x);
            }
            
        }
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x+1);
        printf("\n");
        
        
    }
    
    
}