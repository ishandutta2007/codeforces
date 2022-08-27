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

const int MAXN = 1001;
int n,m;
vvpi nb;
int toignore;
int used[MAXN];
int timer, tin[MAXN], fup[MAXN];
vi bridges;

void dfs (int v, int eind = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<nb[v].size(); ++i) {
        pi edge = nb[v][i];
        if(edge.second == toignore) continue;

        int to = edge.first;
        if (edge.second == eind)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, edge.second);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                bridges.pb(edge.second);
        }
    }
}

void find_bridges() {
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    int s,t;
    scanf("%d %d", &s,&t);
    s--;
    t--;
    
    
    nb.resize(n);
    vi cost(m);
    
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        cost[i] = w;
        if(u==v) continue;
        nb[u].push_back(mp(v,i));
        nb[v].push_back(mp(u,i));
    }
    deque<int> q;
    vpi par(n,mp(-1,-1));
    vi used1(n,0);
    q.pb(s);
    used1[s] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto u : nb[v]) {
            if(!used1[u.first]) {
                used1[u.first] = 1;
                q.pb(u.first);
                par[u.first] = mp(v, u.second);
            }
        }
    }
    if(par[t].first == -1) {
        cout<<0 << endl << 0;
        return 0;
    }
    int cur = t;
    vi cand;
    while(cur != s) {
        cand.pb(par[cur].second);
        cur = par[cur].first;
    }
    const int INF = 2010010010;
    int ans = INF;
    vi del;
    for(auto del1 : cand) {
        int miss = del1;
        q.clear();
        vpi par2(n,mp(-1,-1));
        vi used2(n,0);
        q.pb(s);
        used2[s] = 1;
        while(!q.empty()) {
            int v = q.front();
            q.pop_front();
            for(auto u : nb[v]) {
                if(u.second == del1) continue;
                if(!used2[u.first]) {
                    used2[u.first] = 1;
                    q.pb(u.first);
                    par2[u.first] = mp(v, u.second);
                }
            }
        }
        if(par2[t].first == -1) {
            if(cost[del1] < ans) {
                ans = cost[del1];
                del = vi(1,del1);
            }
        }
        else {
            toignore = del1;
            forn(i,0, MAXN) used[i]= 0;
            forn(i,0, MAXN) tin[i]= 0;
            forn(i,0, MAXN) fup[i]= 0;
            bridges.clear();
            find_bridges();
            vi isbridge(m,0);
            for(auto x : bridges) isbridge[x] = 1;
            vi cand2;
            cur = t;
            while(cur != s) {
                cand2.pb(par2[cur].second);
                cur = par2[cur].first;
            }
            for(auto x : cand2) {
                if(isbridge[x]) {
                    if(cost[del1] + cost[x] < ans) {
                        ans = cost[del1] + cost[x];
                        del = {del1, x};
                    }
                }
            }
        }
    }
    
    if(ans == INF) {
        cout<<-1;
        return 0;
    }
    else {
        cout<<ans<<endl;
        cout<<del.size()<<endl;
        if(del.size() == 1) cout<<1+del[0]<<endl;
        else cout<<1+del[0]<<' '<<1+del[1]<<endl;
        return 0;
    }
    
    
}