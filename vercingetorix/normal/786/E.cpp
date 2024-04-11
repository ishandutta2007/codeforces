#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 300000;
const int INF = 1000000000;

struct edge {
    int a, b;
    int cap,flow;
};

int N;

int s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

int cur_ind = 1;
vvi vis(2);

void clear_all() {
    forn(i,0,MAXN) {
        d[i]=0;
        ptr[i]=0;
        q[i]=0;
        g[i].clear();
    }
    e.clear();
}

void add_edge (int a, int b, int cap) {
//    cout<<a<<' '<<b<<endl;
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, N * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
            to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, N * sizeof ptr[0]);
        while (1) {
            int pushed = dfs (s, INF);
            flow += pushed;
            if(pushed==0) break;
        }
    }
    return flow;
}
int ppl_start;
int n;
vi ret;
void go(int v, int dir) {
    if(v==0 || v==t) return;
    vis[dir][v] = 1;
    if(v >= ppl_start) dir = 0;
    if(v <= n-1) dir = 1;
    if(dir == 0) {
        if(!vis[0][ret[v]]) go(ret[v], 0);
    }
    else {
        for(auto x : g[v]) {
            int to = e[x].b;
            if(to > v && !vis[dir][to]) {
//                cout<<"from " << v <<" to " << to<<" dir "<<dir<<endl;
                go(to, dir);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    clear_all();
//    int n;
    vvi ch;
    vvpi nb;
    vi v_lvl;
    int par[15][20000];
    forn(i,0,15) forn(j,0,20000) par[i][j]=0;
    int ind[15][20000];
    
    vvi lvl;
    int num;
    scanf("%d %d", &n, &num);
    vi pind(n);
    v_lvl.resize(n);
//    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    
    int m=1;
    lvl[1].push_back(0);
    v_lvl[0]=1;
    par[0][0] = 0;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].push_back(mp(v,i));
        nb[v].push_back(mp(u,i));
        //xp;
    }
    int l=2;
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h].first]==0){
                    v_lvl[nb[v][h].first]=l;
                    lvl[l].push_back(nb[v][h].first);
                    m++;
                    ch[v].push_back(nb[v][h].first);
                    par[0][nb[v][h].first]=v;
                    pind[nb[v][h].first] = nb[v][h].second;
                }
            }
        }
        l++;
    }
    l--;
    vi d2(1,1);
    forn(i,0,15) d2.pb(d2.back()*2);
    forn(i,1,n) {
        add_edge(0, cur_ind, 1);
        ind[0][i] = cur_ind++;
    }
    forn(k,1,15) {
        forn(i,0,n) {
            int s2 = par[k-1][i];
            par[k][i] = par[k-1][s2];
            if(v_lvl[i] > d2[k]) {
                add_edge(ind[k-1][s2], cur_ind, d2[k-1]);
                add_edge(ind[k-1][i], cur_ind, d2[k-1]);
                ind[k][i] = cur_ind++;
            }
        }
    }
    ppl_start = cur_ind;
    s=0;
    t = ppl_start+num;
    N = t+1;
    forn(i,0,num) {
        add_edge(ppl_start+i, t, 1);
        int x,y;
        scanf("%d %d", &x, &y);
        x--; y--;
        if(v_lvl[x]>v_lvl[y]) swap(x,y);
        for(int lev = 14; lev >= 0; lev--) {
            if(v_lvl[y]-v_lvl[x] >= d2[lev]) {
                add_edge(ind[lev][y], ppl_start+i, 1);
                y=par[lev][y];
            }
        }
        for(int lev = 14; lev >= 0; lev--) {
            if(par[lev][x] != par[lev][y]) {
                add_edge(ind[lev][y], ppl_start+i, 1);
                add_edge(ind[lev][x], ppl_start+i, 1);
                x=par[lev][x];
                y=par[lev][y];
            }
        }
        if(x!=y) {
            add_edge(ind[0][y], ppl_start+i, 1);
            add_edge(ind[0][x], ppl_start+i, 1);
        }
    }
    int ans = dinic();
    printf("%d\n", ans);
    vis[0]=vi(N,0);
    vis[1]=vi(N,0);
    vi proc(n,1);
    for(auto x : g[0]) {
        if(e[x].flow > 0) {
//            cout<<e[x].b << " ";
            proc[e[x].b] = 0;
        }
    }
//    cout<<"guards"<<endl;
    ret.resize(N);
    forn(st,1,n) {
        if(proc[st] == 0) {
            int cur = st;
            while(cur < ppl_start) {
                for(auto x : g[cur]) {
                    if(e[x].flow > 0) {
                        e[x].flow--;
                        cur=e[x].b;
                        break;
                    }
                }
            }
            ret[cur] = st;
        }
    }
//    for(auto x : e) {
//        if(x.flow > 0 && x.b == t) cout<<x.a << ' ';
//    }
//    cout<<"ppl"<<endl;
    forn(i,1,n) {
        if(proc[i] && !vis[0][i]) {
//            cout<<"started from: " << i<<endl;
            go(i, 0);
        }
    }
    vi gr;
    forn(i,0,num) {
        if(vis[1][ppl_start+i]) gr.pb(i+1);
    }
    printf("%d", (int)gr.size());
    for(auto x : gr) printf(" %d", x);
    printf("\n");
    vi gur;
    forn(i,1,n) {
        if(!vis[0][i]) gur.pb(pind[i]);
    }
    printf("%d", (int)gur.size());
    for(auto x : gur) printf(" %d", x);
    printf("\n");
    
    
}