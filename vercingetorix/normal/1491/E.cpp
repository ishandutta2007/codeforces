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
vi f(2,1);
map<int, int> tof;
int n;
vi st;
vi par;
vvi ch;
vi ban;
vector<set<int>> g;
vi tuk;
int root;
int curs;
void dfs(int v, int p, int nd = -1) {
    st[v] = 1;
    par[v] = p;
    for(auto u : g[v]) {
        if( u==p) continue;
        dfs(u, v, nd);
        st[v] += st[u];
    }
    if(nd!=-1 && st[v] == f[nd]) tuk.pb(v);
    if(root == -1 && 2*st[v] >= curs) root = v;
}
bool test(int v, int s) {
    if(s<=3) return true;
    curs = f[s];
    root = -1;
    dfs(v, v);
    v = root;
    tuk.clear();
    dfs(v,v,s-2);
    vi ctuk = tuk;
    vi ptuk;
    for(auto x : ctuk) ptuk.pb(par[x]);
    if(!ctuk.empty())
    forn(i,0,1) {
        int dd = ctuk[i];
        int pdd = ptuk[i];
        ban[pdd] = 1;
        g[dd].erase(pdd);
        bool s1 = test(dd, s-2);
        g[dd].insert(pdd);
        ban[pdd] = 0;
        if(s1) {
            ban[dd] = 1;
            g[pdd].erase(dd);
            bool s2 = test(v, s-1);
            g[pdd].insert(dd);
            ban[dd] = 0;
            if(s2) return true;
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,2,30) f.pb(f[i-1] + f[i-2]);
    forn(i,0,30) tof[f[i]] = i;
    scanf("%d", &n);
    st.resize(n);
    par.resize(n);
    g.resize(n);
    ban = vi(n,0);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    int kul = tof[n];
    if(kul == 0) {
        cout<<"NO\n";
        return 0;
    }
    forn(i,0,n) {
        if(g[i].size() >= kul) {
            cout<<"NO\n";
            return 0;
        }
    }
    if(test(0, kul)) cout<<"YES";
    else cout<<"NO";
    
}