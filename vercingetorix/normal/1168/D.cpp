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
const int A = 150500;
int par[A];
int vpar[A];
int vci[A];
vi ch[A];
int c[A];
int mcnt[26][A];
int mchcnt[2][26][A];
int smax[A];
int numbad = 0;
int h[A];
int badtree = 0;

void dfs1(int v) {
    if(ch[v].size() == 1) {
        vpar[ch[v][0]] = vpar[v];
        vci[ch[v][0]] = vci[v];
    } else if(ch[v].size() == 2) {
        vci[ch[v][0]] = 0;
        vci[ch[v][1]] = 1;
    }
    h[v] = 0;
//    for(auto u : ch[v]) {
    forn(it,0,ch[v].size()) {
        int u = ch[v][it];
        dfs1(u);
        if(h[v] != 0 && h[v] != h[u] + 1) badtree = 1;
        h[v] = h[u] + 1;
        forn(i,0,26) mchcnt[it][i][v] = mcnt[i][u];
        if(c[u] != -1) mchcnt[it][c[u]][v] += 1;
        forn(i,0,26) mcnt[i][v] = max(mcnt[i][v], mcnt[i][u]);
        if(c[u] != -1) mcnt[c[u]][v] = max(mcnt[c[u]][v], mcnt[c[u]][u] + 1);
    }
    forn(i,0,26) smax[v] += mcnt[i][v];
    if(smax[v] > h[v]) numbad++;
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d\n", &n, &q);
    par[0] = 0;
    vpar[0] = 0;
    forn(i,1,n) {
        char cc;
        scanf("%d %c", &par[i], &cc);
        if(cc == '?') c[i] = -1;
        else c[i] = cc-'a';
        par[i]--;
        ch[par[i]].pb(i);
        vpar[i] = par[i];
    }
    dfs1(0);
    forn(i,0,q) {
        int v;
        char cc;
        scanf("%d %c", &v, &cc);
        v--;
        if(badtree) {
            printf("Fou\n");
            continue;
        }
        int dec = c[v];
        int inc = -1;
        if(cc!='?') inc = cc-'a';
        c[v] = inc;
        if(dec != inc) {
            int cur = v;
            while(cur != 0) {
                int ind = vci[cur];
                cur = vpar[cur];
                if(smax[cur] > h[cur]) numbad--;
                if(dec != -1) {
                    int dwas = mcnt[dec][cur];
                    mchcnt[ind][dec][cur]--;
                    mcnt[dec][cur] = max(mchcnt[0][dec][cur], mchcnt[1][dec][cur]);
                    if(mcnt[dec][cur] < dwas) {
                        smax[cur]--;
                    }
                    else dec = -1;
                }
                if(inc != -1) {
                    int iwas = mcnt[inc][cur];
                    mchcnt[ind][inc][cur]++;
                    mcnt[inc][cur] = max(mchcnt[0][inc][cur], mchcnt[1][inc][cur]);
                    if(mcnt[inc][cur] > iwas) {
                        smax[cur]++;
                    }
                    else inc = -1;
                }
                if(smax[cur] > h[cur]) numbad++;
            }
        }
        if(numbad > 0) printf("Fou\n");
        else {
            printf("Shi ");
            int ans = 0;
            forn(i,0,26) ans += (i+1)*(mcnt[i][0] + h[0] - smax[0]);
            printf("%d\n", ans);
        }
    }
    
    
}