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
int n;
vvi a;
vi g[2][5500];
vi gr[2][5500];
vi mm[2][5500];
int n2;
int m;
vi win[2];
vi vis;

void play(int t) {
    vi q;
    vi cnt(m, 0);
    forn(i,0,m) {
        if(g[t][i].empty()) q.pb(i);
        else cnt[i] = g[t][i].size();
    }
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        win[t][v] = 2;
        for(auto u : g[t][v]) if(win[t][u] == 2) win[t][v] = 1;
        for(auto u : gr[t][v]) {
            cnt[u]--;
            if(win[t][v] == 2) {
//                if(mm[t][u] == -1) mm[t][u] = v;
                mm[t][u].pb(v);
                cnt[u] = min(0, cnt[u]);
            }
            if(cnt[u] == 0) {
                q.pb(u);
                
            }
        }
    }
}

int loc;
int curpos;
int curv;

void go(int to, bool scream = false) {
    int l = curv;
    int r = to;
    if(l>r) curpos = n*n+r*n+l-n;
    else curpos = l*n + r-n;
    if(scream) printf("%d\n", to+1);
    if(scream) fflush(stdout);
    vis[to] = 1;
    curv = to;
}

void make_move() {
    int pt = 0;
    int to;
    while(1) {
        int u = mm[loc][curpos][pt];
        to = n+u%n;
        if(u>=n*n) to = (u-n*n)/n;
        if(vis[to]) pt++;
        else break;
    }
//    while(vis[mm[loc][curpos][pt]]) pt++;
//    int u = mm[loc][curpos][pt];
//    int to = n+u%n;
//    if(u>=n*n) to = (u-n*n)/n;
    go(to, true);
//    for(auto u : g[loc][curpos]) if(win[loc][u] == 2) {
//        int to = n+u%n;
//        if(u>=n*n) to = (u-n*n)/n;
//        if(vis[v]) continue;
//        go(to, true);
//        return;
//    }
}

bool read_move() {
    int to;
    scanf("%d", &to);
    if(to == -2) exit(0);
    if(to<0) return false;
    to--;
    go(to);
    return true;
}

void init() {
    forn(inc,0,2) {
        forn(i,0,n) {
            if(win[inc][2*n*n+i] == 2) {
                printf("A\n");
                loc = inc;
                if(inc == 0) printf("D %d\n", i+1);
                else printf("I %d\n", i+1);
                curpos = 2*n*n+i;
                curv = i;
                vis[curv] = 1;
                fflush(stdout);
                return;
            }
        }
        forn(i,0,n) {
            if(win[inc][2*n*n+n+i] == 2) {
                printf("A\n");
                loc = inc;
                if(inc == 0) printf("I %d\n", n+i+1);
                else printf("D %d\n", n+i+1);
                curpos = 2*n*n+n+i;
                curv = i+n;
                vis[curv] = 1;
                fflush(stdout);
                return;
            }
        }
    }
    printf("B\n");
    fflush(stdout);
    char c;
    int v;
    scanf("%c", &c);
    while(c!='I' && c!='D') scanf("%c", &c);
    scanf("%d",&v);
    v--;
    curv = v;
    vis[v] =1;
    curpos = v + 2*n*n;
    if(c == 'D' && v < n) loc = 0;
    else if(c == 'I' && v >= n) loc = 0;
    else loc = 1;
    make_move();
}

void name_ver(int v) {
    if(v >= 2*n2) {
        printf("(start %d)", v-2*n2+1);
    }
    else if(v<n2) {
        printf("(%d to %d)", v/n+1, n+v%n+1);
    }
    else {
        v-=n2;
        printf("(%d to %d)", n+v%n+1, v/n+1);
    }
}

void name_g(int t) {
    forn(v,0,m) {
        name_ver(v); printf(" %d\n", win[t][v]);
    }
    forn(v,0,m) {
        for(auto u : g[t][v]) {
            name_ver(v); printf(" to "); name_ver(u); printf("\n");
        }
    }
}

void solve() {
    scanf("%d\n", &n);
    vis = vi(2*n,0);
    n2 = n*n;
    a = vvi(n, vi(n));
    forn(i,0,n) forn(j,0,n) scanf("%d", &a[i][j]);
    m = 2*n*n+2*n;
    forn(inc,0,2) forn(j,0,2*n*n+2*n) {
        g[inc][j].clear();
        gr[inc][j].clear();
    }
// inc 0    -> > -<     inc 1   <- > ->
    forn(inc, 0, 2) {
        forn(i,0,m) mm[inc][i].clear();
        win[inc] = vi(m, 0);
        forn(i,0,n) forn(j,0,n) {
            int v = i*n+j;
            forn(i2,0,n) if((inc == 0 && a[i2][j] < a[i][j]) || (inc == 1 && a[i2][j] > a[i][j])) g[inc][v].pb(n2+i2*n+j);
            int v2 = n2+i*n+j;
            forn(j2,0,n) if((inc == 0 && a[i][j] < a[i][j2]) || (inc == 1 && a[i][j] > a[i][j2])) g[inc][v2].pb(i*n+j2);
        }
        forn(i,0,n) {
            forn(j,0,n) g[inc][2*n*n + i].pb(i*n+j);
        }
        forn(j,0,n) {
            forn(i,0,n) g[inc][2*n*n + n + j].pb(n2 + i*n + j);
        }
        forn(i,0,m) for(auto u : g[inc][i]) gr[inc][u].pb(i);
        play(inc);
    }
//    name_g(0);
    init();
//    return;
    while(read_move()) make_move();
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int ta;
    read(ta);
    while(ta--) {
        solve();
    }
    
    
}