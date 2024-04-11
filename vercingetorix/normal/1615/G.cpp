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
const int A = 1000;
int done[A];
int filldone[A];

int parent[A];
int rk[A];
int cnt[A];
int ver[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    cnt[v] = 0;
    ver[v] = 1;
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
        cnt[a] += cnt[b]+1;
        ver[a] += ver[b];
    }
    else cnt[a] ++;
}

vpi g[A];
int acount[A];
vi fr;
int n;
vi a;

void add_edge(int u, int v, int ind) {
    union_sets(u, v);
    g[u].pb(mp(v, ind));
    if(u!=v) g[v].pb(mp(u, ind));
}
int vis[A];
vpi path;
vpi e0;

bool dfs(int v, int p) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(u.second == p) continue;
        if(vis[u.first]) {
            path.pb(mp(v, u.second));
            return true;
        }
        if(dfs(u.first, u.second)) {
            path.pb(mp(v, u.second));
            return true;
        }
    }
    return false;
}

void fillsad(int ind) {
    int l = e0[ind].first;
    int r = e0[ind].second;
    for(int i = l; i<r; i+=2) {
        a[i] = fr.back();
        a[i+1] = fr.back();
        fr.pop_back();
    }
}

void fillhappy(int ind) {
    int l = e0[ind].first;
    int r = e0[ind].second;
    for(int i = l+1; i<r; i+=2) {
        a[i] = fr.back();
        a[i+1] = fr.back();
        fr.pop_back();
    }
    a[l] = a[l-1];
    a[r] = a[r+1];
    done[a[l]] = 1;
    done[a[r]] = 1;
}

void fill1(int ind, int val) {
    int l = e0[ind].first;
    int r = e0[ind].second;
    if(a[l-1] == val) {
        for(int i = l+1; i<r; i+=2) {
            a[i] = fr.back();
            a[i+1] = fr.back();
            fr.pop_back();
        }
        a[l] = val;
    }
    else {
        for(int i = l; i<r; i+=2) {
            a[i] = fr.back();
            a[i+1] = fr.back();
            fr.pop_back();
        }
        a[r] = val;
    }
    done[val] = 1;
}

void dfsfill(int v) {
    filldone[v] = 1;
    for(auto u : g[v]) {
        if(filldone[u.first]) continue;
        if(!done[u.first]) {
            fill1(u.second, u.first);
        }
        dfsfill(u.first);
    }
}

const int MAXN = A; //       

int ne;
vector<int> ge[MAXN];
int match[MAXN], p[MAXN], base[MAXN], q[MAXN];
bool blossom[MAXN];
vector<bool> used;

void mark_path (int v, int b, int children) {
    while (base[v] != b) {
        blossom[base[v]] = blossom[base[match[v]]] = true;
        p[v] = children;
        children = match[v];
        v = p[match[v]];
    }
}

int lca (int a, int b) {
    bool used[MAXN] = { 0 };
    //    a  ,    
    for (;;) {
        a = base[a];
        used[a] = true;
        if (match[a] == -1)  break; //   
        a = p[match[a]];
    }
    //    b,     
    for (;;) {
        b = base[b];
        if (used[b])  return b;
        b = p[match[b]];
    }
}

int find_path (int root) {
    used.assign(ne, false);
    memset (p, -1, sizeof p);
    for (int i=0; i<ne; ++i)
        base[i] = i;
    
    used[root] = true;
    int qh=0, qt=0;
    q[qt++] = root;
    while (qh < qt) {
        int v = q[qh++];
        for (size_t i=0; i<ge[v].size(); ++i) {
            int to = ge[v][i];
            if (base[v] == base[to] || match[v] == to)  continue;
            if (to == root || match[to] != -1 && p[match[to]] != -1) {
                int curbase = lca (v, to);
                memset (blossom, 0, sizeof blossom);
                mark_path (v, curbase, to);
                mark_path (to, curbase, v);
                for (int i=0; i<ne; ++i)
                    if (blossom[base[i]]) {
                        base[i] = curbase;
                        if (!used[i]) {
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
            }
            else if (p[to] == -1) {
                p[to] = v;
                if (match[to] == -1)
                    return to;
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}

vector<pi> edmonds_matching() {
    memset (match, -1, sizeof match);
    for (int i=0; i<ne; ++i)
        if (match[i] == -1) {
            int v = find_path (i);
            while (v != -1) {
                int pv = p[v],  ppv = match[pv];
                match[v] = pv,  match[pv] = v;
                v = ppv;
            }
        }
    vpi ret;
    forn(i,0,ne){
        if(match[i] > i) ret.pb(mp(i,match[i]));
    }
    return ret;
}

map<pi, int> to;
map<pi, pi> to2;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    for(auto x : a) acount[x] = 1;
    forn(i,1,n+1) if(i>=A || acount[i] == 0) fr.pb(i);
    forn(i,1,n) if(a[i]==a[i-1]) done[a[i]] = 1;
    int last = -1;
    
    forn(i,0,n) {
        if(a[i] != 0) {
            if(last != i-1) e0.pb(mp(last+1, i-1));
            last = i;
        }
    }
    if(last != n-1) e0.pb(mp(last+1,n-1));
    forn(i,0,A) make_set(i);
    forn(it,0,e0.size()) {
        int l = e0[it].first;
        int r = e0[it].second;
        if((r-l)%2 == 0) {
            if(l==0 || done[a[l-1]]) {
                for(int i = l; i<r; i+=2) {
                    a[i] = fr.back();
                    a[i+1] = fr.back();
                    fr.pop_back();
                }
                if(r != n-1) {
                    a[r] = a[r+1];
                    done[a[r+1]] = 1;
                }
                else a[r] = 1;
                swap(e0[it], e0.back());
                e0.pop_back();
                it--;
            }
            else if(r == n-1 || done[a[r+1]]) {
                for(int i = l+1; i<r; i+=2) {
                    a[i] = fr.back();
                    a[i+1] = fr.back();
                    fr.pop_back();
                }
                if(l != 0) {
                    a[l] = a[l-1];
                    done[a[l-1]] = 1;
                }
                else a[l] = 1;
                swap(e0[it], e0.back());
                e0.pop_back();
                it--;
            }
            else if(a[l-1] == a[r+1]) {
                for(int i = l; i<r; i+=2) {
                    a[i] = fr.back();
                    a[i+1] = fr.back();
                    fr.pop_back();
                }
                if(r != n-1) {
                    a[r] = a[r+1];
                    done[a[r+1]] = 1;
                }
                else a[r] = 1;
                swap(e0[it], e0.back());
                e0.pop_back();
                it--;
            }
        }
        else {
            if(l==0 || r==n-1 || done[a[l-1]] || done[a[r+1]] || a[l-1] == a[r+1]) {
                for(int i = l; i<r; i+=2) {
                    a[i] = fr.back();
                    a[i+1] = fr.back();
                    fr.pop_back();
                }
                swap(e0[it], e0.back());
                e0.pop_back();
                it--;
            }
        }
    }
    forn(it,0,e0.size()) {
        int l = e0[it].first;
        int r = e0[it].second;
        if((r-l)%2 == 0) {
            if(done[a[l-1]]) add_edge(a[r+1], a[r+1], it);
            else if(done[a[r+1]]) add_edge(a[l-1], a[l-1], it);
            else add_edge(a[l-1], a[r+1], it);
        }
    }
    forn(i,1,A) if(filldone[i] == 0 && find_set(i) == i && cnt[i] >= ver[i]) {
        if(dfs(i, -1)) {
            for(auto x : path) {
                fill1(x.second, x.first);
            }
            path.clear();
            dfsfill(i);
        }
    }
    forn(it,0,e0.size()) {
        int l = e0[it].first;
        int r = e0[it].second;
        if((r-l)%2 == 1) {
            if(done[a[l-1]] == 1 || done[a[r+1]] == 1) fillsad(it);
            else {
                int u = find_set(a[l-1]);
                int v = find_set(a[r+1]);
                if(u==v) fillsad(it);
                else {
                    ge[u].pb(v);
                    ge[v].pb(u);
                    to[mp(u,v)] = it;
                    to[mp(v,u)] = it;
                    to2[mp(u,v)] = mp(a[l-1], a[r+1]);
                    to2[mp(v,u)] = mp(a[l-1], a[r+1]);
                }
            }
        }
    }
    ne = A;
    auto ret = edmonds_matching();
    for(auto x : ret) {
        int u = x.first;
        int v = x.second;
        int ind = to[mp(u,v)];
        fillhappy(ind);
        dfsfill(to2[mp(u,v)].first);
        dfsfill(to2[mp(u,v)].second);
    }
    forn(i,0,A) {
        if(done[i] && filldone[i] == 0) dfsfill(i);
    }
    forn(i,0,A) {
        if(g[i].size() == 1 && done[i] == 0) {
            fill1(g[i][0].second, i);
            dfsfill(i);
        }
    }
    forn(it,0,e0.size()) {
        int l = e0[it].first;
        int r = e0[it].second;
        if(a[l]!=0) continue;
        if((r-l)%2==1) fillsad(it);
        else {
            if(done[a[l-1]]) {
                fill1(it, a[r+1]);
                dfsfill(a[l-1]);
            }
            else if(done[a[r+1]]) {
                fill1(it, a[l-1]);
                dfsfill(a[r+1]);
            }
            else {
                fill1(it, a[l-1]);
                dfsfill(a[l-1]);
            }
        }
    }
    forn(i,0,n) printf("%d ", a[i]);
    
}