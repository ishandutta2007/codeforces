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

const int A = 100500;
int d[A];
int p[A];
int n,q;
int vis[A];
vi x;
int knap() {
    int sum = 0;
    for(auto xx : x) sum += xx;
    int L = sum+1;
    forn(i,0,L) d[i] = 0;
    d[0] = 1;
    srt(x);
    int pt = 0;
    while(pt<x.size()) {
        int ptr = pt+1;
        while(ptr<x.size() && x[pt] == x[ptr]) ptr++;
        int a = x[pt];
        int k = ptr-pt;
        for(int i = L-1-a; i>=0; i--) if(d[i]) {
            for(int j = i+a; j < min(L,i+k*a+1); j+=a) {
                if(d[j]) break;
                else {
                    d[j] = 1;
                    p[j] = a;
                }
            }
        }
        pt = ptr;
    }
    for(int i = sum/2; i>=0; i--) {
        if(d[i]) return sum-2*i;
    }
    return sum;
}
int par[A];
vi ch[A];
int lev[A];
int isl[A];

void dfs(int v) {
    if(ch[v].empty()) isl[v] = 1;
    for(auto u : ch[v]) {
        lev[u] = lev[v]+1;
        dfs(u);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,na;
    scanf("%d %d", &n, &na);
//    vi par(n,0);
//    vi lev(n,0);
//    vi isl(n,1);
    forn(i,1,n) {
        scanf("%d", &par[i]);
        
        par[i] --;
        ch[par[i]].pb(i);
//        lev[i] = lev[par[i]]+1;
//        isl[par[i]] = 0;
    }
    dfs(0);
    vi lb(n,0);
    vi vb(n,0);
    forn(i,0,n) {
        if(isl[i]) lb[lev[i]]++;
        else vb[lev[i]]++;
    }
    vvi bys(n+1);
    forn(i,0,n) if(lb[i]+vb[i]>0) {
        x.pb(lb[i]+vb[i]);
        bys[lb[i]+vb[i]].pb(i);
    }
    knap();
    vi col(n+1,1);
    vi pt(n+1,0);
    if(d[na] == 1) {
        vi toa;
        int m = na;
        while(m>0) {
            toa.pb(p[m]);
            m -= p[m];
        }
        for(auto x : toa) {
            col[bys[x][pt[x]++]] = 0;
        }
        printf("%d\n", x.size());
        forn(i,0,n) printf("%c", 'a' + col[lev[i]]);
    }
    else {
        int curlev = 0;
        int cura = 0;
        int curb = n;
        int nb = n-na;
        while(lb[curlev] + vb[curlev] +cura < na) {
            cura += lb[curlev] + vb[curlev];
            curb -= lb[curlev] + vb[curlev];
            curlev++;
        }
        curb -= lb[curlev] + vb[curlev];
        int fa = na - cura;
        int fb = nb - curb;
        forn(i,0,curlev) col[i] = 0;
        while(lb[curlev] < min(fa, fb)) {
            col[curlev] = 1;
            curb += lb[curlev] + vb[curlev];
            curlev++;
            curb -= lb[curlev] + vb[curlev];
            fb = nb - curb;
        }
        printf("%d\n", x.size() + 1);
        forn(i,0,n) {
            if(lev[i] != curlev) printf("%c", 'a' + col[lev[i]]);
            else {
                if(fa <= lb[curlev]) {
                    if(fa>0 && isl[i]) {
                        printf("a");
                        fa--;
                    }
                    else printf("b");
                }
                else {
                    if(fb>0 && isl[i]) {
                        printf("b");
                        fb--;
                    }
                    else printf("a");
                }
            }
        }
        
    }
    
    
}