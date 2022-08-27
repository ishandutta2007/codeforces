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
vvpi g;
ll n;
vll kra[2];
vi cost[2];
vi h;
vi lf;
ll sum;

void dfs(int v, int p) {
//    st[v] = 1;
    lf[v] = 0;
    int leaf = 1;
    for(auto u : g[v]) {
        if(u.first != p) {
            leaf= 0;
            h[u.first]= h[v]+1;
            dfs(u.first, v);
            
//            st[v] += st[u.first];
            lf[v] += lf[u.first];
            if(u.second > 0){
                kra[0].pb(lf[u.first]);
                cost[0].pb(u.second);
            }
            else {
                kra[1].pb(lf[u.first]);
                cost[1].pb(-u.second);
            }
        }
    }
    if(leaf) lf[v] ++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    char c[300500];
    while(t--) {
        kra[0].clear();
        cost[0].clear();
        kra[1].clear();
        cost[1].clear();
        sum = 0;
        ll s;
        scanf("%lld %lld\n", &n, &s);
        g= vvpi(n);
        h.resize(n);
        lf.resize(n);
        forn(i,0,n-1) {
            int u,v,w,c;
            scanf("%d %d %d %d" ,&u, &v, &w, &c);
            u--; v--;
            if(c==2) w = -w;
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        h[0] = 1;
        dfs(0,0);
        set<pll> todel[2];
        vll cool[2];
        forn(pt,0,2) {
            forn(i,0,kra[pt].size()) {
                sum += kra[pt][i]*cost[pt][i];
                todel[pt].insert(mp(kra[pt][i]*(cost[pt][i]/2) - kra[pt][i]*cost[pt][i], i));
            }
            while(1) {
                if(todel[pt].empty() || todel[pt].begin()->first == 0) break;
                int pdo = pt;
                auto it = todel[pt].begin();
                int i = it->second;
                cool[pt].pb(it->first);
                todel[pdo].erase(it);
                cost[pdo][i]/=2;
                todel[pdo].insert(mp(kra[pdo][i]*(cost[pdo][i]/2) - kra[pdo][i]*cost[pdo][i], i));
            }
        }
        int p1 = 0;
        while(p1<cool[0].size() &&  sum > s) sum+=cool[0][p1++];
        int ans = cool[0].size() + 2*cool[1].size();
        forn(p2,0,cool[1].size()+1) {
            if(sum <= s) ans =min(ans, p1+2*p2);
            if(p2<cool[1].size()) sum+=cool[1][p2];
            while(p1>0 && sum - cool[0][p1-1] <= s) sum -= cool[0][--p1];
        }
        printf("%d\n", ans);
        
    }
    
}