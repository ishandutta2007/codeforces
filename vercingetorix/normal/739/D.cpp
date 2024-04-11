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
const int MAXN = 1000;
const int INF = 1000000000;

struct edge {
    int a, b;
    ll cap,flow;
};

int N,s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void clear_all() {
    forn(i,0,MAXN) {
        d[i]=0;
        ptr[i]=0;
        q[i]=0;
        g[i].clear();
    }
    e.clear();
}

void add_edge (int a, int b, ll cap) {
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

ll dfs (int v, ll flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        ll pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, N * sizeof ptr[0]);
        while (1) {
            ll pushed = dfs (s, INF);
            flow += pushed;
            if(pushed==0) break;
        }
    }
    return flow;
}

char ps[10], pw[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    vi p(n), w(n);
    forn(i,0,n) {
        scanf("%s %s\n", ps, pw);
        string sp = ps;
        string sw = pw;
        if(sp == "?") p[i] = -1;
        else p[i] = stoi(sp);
        if(sw == "?") w[i] = -1;
        else w[i] = stoi(sw);
//        cout<<p[i]<<endl<<w[i]<<endl<<endl;
    }
    map<pi,int> to;
    set<int> c;
    int maxu = 0;
    forn(i,0,n) {
        if(p[i] >=0 && w[i] >=0) to[mp(p[i], w[i])]++;
        if(w[i] >= 0) c.insert(w[i]);
        if(w[i] == -1) {
            maxu = max(maxu, p[i]);
        }
    }
    if(c.empty()) {
        c.insert(1);
    }
//    pi best = mp(-1, 1);
//    forn(test,1,301) {
//        int cn0 = 0;
//        int mu = -1;
//        forn(i,0,n) {
//            if(p[i] == -1 && w[i] == test) cn0++;
//            if(w[i]==test) mu = max(mu, p[i]);
//        }
//        forn(i,0,mu) if(to[mp(i, test)] == 0) cn0--;
//        int lol = mu;
//        if(cn0 >0) lol+=cn0;
//        best = max(best, mp(lol, test));
//    }
//    for(auto x : to) {
//        if (x.second > 0) {
//            best = max(best, x.first);
//        }
//    }
    int totcnt = 0;
    for(auto U : to) totcnt+=U.second;
    if(totcnt > n) {
        cout << -1;
        return 0;
    }
    for(auto l : c) {
        if(to[mp(0,l)] == 0) to[mp(0,l)]++;
        while(to[mp(0,l)]%l != 0) to[mp(0,l)]++;
    }
    
    forn(lad,1,301) {
        if(to[mp(0,lad)] == 0) continue;
        int camp = 0;
        forn(i,1,301) if(to[mp(i,lad)] > 0) camp = i;
        
        forn(i,camp+1, maxu+1) to[mp(i, lad)]++;
        
        set<pi> add;
        for(auto x : to) {
            if(x.second == 0) continue;
            int l = x.first.second;
            int d = x.first.first;
            forn(i,1,d) if(to[mp(i,l)] == 0) add.insert(mp(i,l));
        }
        for(auto x : add) to[x]++;
        vpi r;
        vpi tp(n, mp(-1,-1));
        forn(i,0,n) {
            if(p[i] >=0 && w[i]>=0) {
                to[mp(p[i], w[i])]--;
                tp[i] = mp(p[i], w[i]);
            }
        }
        for(auto x : to) {
            forn(i,0,x.second) r.pb(x.first);
        }
        forn(i,0,n) {
            if(p[i] >=0 && w[i]>=0) {
                to[mp(p[i], w[i])]++;
            }
        }
        forn(i,camp+1, maxu+1) to[mp(i, lad)]--;
        if (r.size() > n) {
            continue;
        }
        int rn = r.size();
        clear_all();
        N = 2 + rn + n;
        s = N-2;
        t = N-1;
        forn(i,0,rn) add_edge(s, i, 1);
        forn(i,0,n) if(tp[i] == mp(-1, -1)) add_edge(rn+i, t, 1);
        forn(i,0,rn) {
            forn(j,0,n) {
                if(tp[j] != mp(-1, -1)) continue;
                if(p[j] >= 0 && p[j] != r[i].first) continue;
                if(w[j] >= 0 && w[j] != r[i].second) continue;
                add_edge(i, rn+j, 1);
            }
        }
        if(dinic() < rn) {
            continue;
        }
        
        for(auto ed:e) {
            if(ed.a < rn && ed.b >= rn && ed.b < rn+n && ed.flow == 1) {
                tp[ed.b - rn] = r[ed.a];
            }
        }
        int cnt0 = 0;
        forn(i,0,n) {
            if(tp[i] == mp(-1, -1) && p[i] == 0) cnt0++;
        }
        forn(i,0,n) {
            if(tp[i] == mp(-1, -1) && p[i] == 0) tp[i]=mp(0,cnt0);
        }
        forn(i,0,n) {
            if(tp[i] == mp(-1,-1)) {
                if(p[i]==-1 && w[i]==-1) tp[i] =mp(0,1);
                else if(p[i] == -1) tp[i] = mp(1, w[i]);
                else if(w[i] == -1) tp[i] =mp(p[i], lad);
            }
        }
        vi ans(n);
        forn(l,1,301) {
            vi ind;
            forn(i,0,n) if(tp[i] == mp(0,l)) ind.pb(i);
            forn(i,0,ind.size()/l) {
                forn(j,0,l) {
                    ans[ind[i*l+j]] = ind[i*l + (j+1)%l] + 1;
                }
            }
        }
        forn(i,0,n) {
            if(tp[i].first != 0) {
                pi nd = tp[i];
                nd.first--;
                forn(j,0,n) if(tp[j] == nd) ans[i]=j+1;
            }
        }
        forn(i,0,n) cout<<ans[i]<<' ';
        return 0;
    }
    cout<<-1;
    return 0;
   
    
    
    
}