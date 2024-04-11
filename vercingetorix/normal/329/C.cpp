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
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

vvi g;
map<int, vi> comp;
vpi ans;
vi vis;
vi ord;
void dfs(int v) {
    vis[v] = 1;
    ord.pb(v);
    for(auto u : g[v]) {
        if(vis[u]) continue;
        dfs(u);
    }
}

int num(int v) {
    int e = 0;
    for(auto u : comp[v]) e+=g[u].size();
    return e/2;
}

void solve5(int v, bool act = true) {
    int s = -1;
    int e = 0;
    
    for(auto u : comp[v]) {
        e+=g[u].size();
        if(g[u].size() == 1) s = u;
    }
    if(s == -1) s = comp[v][0];
    ord.clear();
    dfs(s);
    e/=2;
    if(!act) return;
    forn(i,0,e) ans.pb(mp(ord[i], ord[(i+2)%ord.size()]));
}

void add(int v) {
    int e = 0;
    for(auto u : comp[v]) e+=g[u].size();
    e/=2;
    vpi modi;
    forn(i,0,e) {
        modi.pb(ans.back());
        ans.pop_back();
    }
    forn(i,0,e) {
        ans.pb(mp(comp[v][i], modi.back().first));
        ans.pb(mp(comp[v][i], modi.back().second));
        modi.pop_back();
    }
}
void no() {
    cout<<-1;
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    forn(i,0,n) make_set(i);
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
        union_sets(u, v);
    }
    
    forn(i,0,n) comp[find_set(i)].pb(i);
    vector<pair<pi, int>> q1;
    for(auto x : comp) q1.pb(mp(mp(x.second.size(), num(x.first)), x.first));
    srtrev(q1);
    vpi q;
    forn(i,0,q1.size()) {
        q.pb(mp(q1[i].first.first, q1[i].second));
    }
    vis = vi(n,0);
    int pt = 0;
    while(1) {
        if(q[pt].first >= 5) {
            solve5(q[pt].second);
            pt++;
        }
        else if(q[pt].first == 4) {
            int v = q[pt].second;
            solve5(v, false);
            if(q.size() == 1) {
                if(num(v) == 4) no();
                ans.pb(mp(ord[0], ord[2]));
                ans.pb(mp(ord[0], ord[3]));
                ans.pb(mp(ord[1], ord[3]));
                pt++;
                break;
            }
            int u = q[pt+1].second;
            if(q[pt+1].first <= 2) {
                ans.pb(mp(ord[0], ord[2]));
                ans.pb(mp(ord[1], ord[3]));
                forn(i,0,num(v)+num(u)-2) {
                    ans.pb(mp(ord[i], comp[u][i/2]));
                }
                pt+=2;
            }
            else if(q[pt+1].first == 4) {
                forn(i,0,4) {
                    ord.pb(comp[v][i]);
                    ord.pb(comp[u][i]);
                }
                forn(i,0,num(v)+num(u)) ans.pb(mp(ord[i], ord[(i+1)%8]));
                pt+=2;
            }
            else {
                forn(i,0,3) ord.pb(comp[u][i]);
                swap(ord[3], ord[4]);
                swap(ord[2], ord[6]);
                swap(ord[1], ord[2]);
                forn(i,0,num(v)+num(u)) ans.pb(mp(ord[i], ord[(i+1)%7]));
                pt+=2;
            }
        }
        else if(q[pt].first == 3) {
            int v = q[pt].second;
            if(q.size() == 1) no();
            int u = q[pt+1].second;
            if(q[pt+1].first == 3) {
                ord.clear();
                forn(i,0,3) {
                    ord.pb(comp[v][i]);
                    ord.pb(comp[u][i]);
                }
                forn(i,0,num(v)+num(u)) ans.pb(mp(ord[i], ord[(i+1)%6]));
                pt+=2;
            }
            else if(q[pt+1].first == 2) {
                ans.pb(mp(comp[v][0], comp[u][0]));
                ans.pb(mp(comp[v][1], comp[u][0]));
                ans.pb(mp(comp[v][0], comp[u][1]));
                if(num(v) == 3) ans.pb(mp(comp[v][1], comp[u][1]));
                pt+=2;
            }
            else {
                if(num(v) == 2) {
                    vi sm;
                    for(auto x : comp[v]) if(g[x].size() == 1) sm.pb(x);
                    ans.pb(mp(sm[0], sm[1]));
                    ans.pb(mp(sm[0], comp[u][0]));
                    pt+=2;
                }
                else {
                    if(q.size() == 2) no();
                    int s = q[pt+2].second;
                    ans.pb(mp(comp[v][0], comp[u][0]));
                    ans.pb(mp(comp[v][1], comp[u][0]));
                    ans.pb(mp(comp[v][2], comp[s][0]));
                    pt+=3;
                }
            }
        }
        else if(q[pt].first == 2) {
            int v = q[pt].second;
            if(q.size() == 1) no();
            int u = q[pt+1].second;
            if(q[pt+1].first == 2) {
                ans.pb(mp(comp[v][0], comp[u][0]));
                ans.pb(mp(comp[v][1], comp[u][1]));
            }
            else {
                ans.pb(mp(comp[v][0], comp[u][0]));
            }
            pt+=2;
        }
        break;
    }
    forn(i,pt,q.size()) add(q[i].second);
    for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
    
}