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
#include <stack>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int INF = 1000000000;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
//    cin>>n>>m;
    scanf("%d %d", &n,&m);
    vector < vector < pair<int,int> > > g (n);
    forn(i,0,m) {
        int x,y,l;
        //cin>>x>>y>>l;
        scanf("%d %d %d", &x,&y,&l);
        x--;
        y--;
        g[x].pb(mp(y,l));
        g[y].pb(mp(x,l));
    }
    vvi ans(n, vi(n,0));
    //
    
    forn(s,0,n) {
        vector<int> d (n, INF);
        vvi p(n);
        d[s] = 0;
        vector<char> u (n);
        for (int i=0; i<n; ++i) {
            int v = -1;
            for (int j=0; j<n; ++j)
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            if (d[v] == INF)
                break;
            u[v] = true;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                len = g[v][j].second;
                if (d[v] + len == d[to]) {
                    p[to].pb(v);
                }
                else if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to].clear();
                    p[to].pb(v);
                }
            }
        }
//        forn(t,s+1,n) {
//            int cnt = 0;
//            list<int> dom;
//            dom.pb(t);
//            vi used(n,0);
//            while(dom.size() > 0) {
//                int u = dom.front();
//                dom.pop_front();
//                for(auto v: p[u]) {
//                    cnt++;
//                    if(!used[v]) {
//                        used[v]=1;
//                        dom.pb(v);
//                    }
//                }
//            }
//            ans[s][t] = cnt;
//        }
        vpi sv;
        forn(i,0,n) {
            if(i==s) continue;
            sv.pb(mp(d[i], i));
        }
        sort(all(sv));
        vector<vll> pr(n, vll(10,0));
        for(auto x:sv) {
            int u = x.second;
            pr[u][u/60] |= (1ll<<(u%60));
            for(auto y : p[x.second]) forn(i,0,10) pr[u][i] |= pr[y][i];
        }
        //if(s==0)forn(t,s+1,n) cout<<pr[t][0]<<" "; cout<<endl;
        forn(t,s+1,n) forn(i,0,10) forn(j,0,62) if(pr[t][i]&(1ll<<j)) ans[s][t]+=(int)p[60*i+j].size();
    }
    forn(s,0,n) forn(t,s+1,n) cout<<ans[s][t]<<" ";
}