#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <map>
#include <stdio.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

/*int xmin[2000][500];
int xmax[2000][500];
int num[2000][500];*/
int mindels[2][2001];
string s,p;
ll mod = 100000000000001;
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    //cin>>n>>m;
    scanf("%d %d", &n, &m);
    vector<vi> nb(n+1);
    vb parsed(n+1, false);
  // vi truepar(n+1, -1);
    vi v_lvl(n+1, -1);
    vi par(n+1, -1);
    vi out_e(n+1, 0);
    int a, b;
    vector<pair<int,int> > roads;
    vi roots;
    vvi comps(n+1);
    vi comp_edges(n+1);
    vi odd_vert(n+1);
    vi need_in;
    vi need_out;
    vector<pair<int, int> > ans;
    vi root(n+1);
    map<pair<int, int>, bool> road_used;
    map<pair<int, int>, int> roads_num;
    for (int i = 0; i < m; i++) {
        //cin >> a >> b;
        scanf("%d %d", &a, &b);
        roads.pb(mp(a,b));
        road_used[mp(a,b)] = false;
        road_used[mp(b,a)] = false;
        roads_num[mp(a,b)]++;
        roads_num[mp(b,a)]++;
        nb[a].pb(b);
        nb[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!parsed[i]) {
            roots.pb(i);
            deque<int> dfs;
            dfs.pb(i);
            parsed[i] = true;
            par[i] = i;
            v_lvl[i] = 1;
            root[i] = i;
            comps[i].pb(i);
            while (dfs.size() > 0) {
                int v = dfs.back();
                int h = v_lvl[v] + 1;
                dfs.pop_back();
                for (int j = 0; j < nb[v].size(); j++) {
                    if (!parsed[nb[v][j]]) {
                        parsed[nb[v][j]] = true;
                        v_lvl[nb[v][j]] = h;
                        root[nb[v][j]] = i;
                        comps[i].pb(nb[v][j]);
                        dfs.pb(nb[v][j]);
                        par[nb[v][j]] = v;
                        road_used[mp(v, nb[v][j])] = true;
                        road_used[mp(nb[v][j], v)] = true;
                        roads_num[mp(v, nb[v][j])]--;
                        roads_num[mp(nb[v][j], v)]--;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        comp_edges[root[roads[i].first]]++;
        if(roads_num[roads[i]] > 0) {
            roads_num[roads[i]] --;
            roads_num[mp(roads[i].second, roads[i].first)] --;
            ans.pb(roads[i]);
            out_e[roads[i].first]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if((nb[i].size()) % 2 == 1) odd_vert[root[i]]++;
    }
    //cout<<"par  "; for(auto a: par) cout<<a<<" "; cout<<endl;
    //cout<<"roots  "; for(auto a: roots) cout<<a<<" "; cout<<endl;
    //cout<<"odd_vert  "; for(auto a: odd_vert) cout<<a<<" "; cout<<endl;
    //cout<<"comp_edges  "; for(auto a: comp_edges) cout<<a<<" "; cout<<endl;
    for (int i=0; i<roots.size(); i++) {
        int x = roots[i];
        vector<pair<int, int> > ccomp;
        int csize = comps[x].size();
        for(int j=0; j<comps[x].size(); j++) {
            ccomp.pb(mp(v_lvl[comps[x][j]], comps[x][j]));
        }
        sort(all(ccomp));
        reverse(all(ccomp));
        int nin, nout;
        if(comp_edges[x] %2 == 0) {
            nin = odd_vert[x]/ 2;
            nout = odd_vert[x]/ 2;
            if(nin%2 == 1) {
                nin++;
                nout--;
                if(need_in.size()>need_out.size()) swap(nin, nout);
            }
        }
        else {
            if(odd_vert[x] == 0) {
                ans.pb(mp(x,x));
                out_e[x]++;
            }
            nin = odd_vert[x]/ 2;
            nout = odd_vert[x]/ 2;
            if(nin%2 == 0) {
                nin++;
                nout--;
                if(need_in.size()>need_out.size()) swap(nin, nout);
            }
        }
        //comp
        int odd_cnt=0;
        for(int j=0; j<csize-1; j++) {
            int v = ccomp[j].second;
            if (nb[v].size() % 2 == 0) {
                if((out_e[v] % 2) == 0) {
                    ans.pb(mp(par[v], v));
                    out_e[par[v]]++;
                }
                else {
                    ans.pb(mp(v, par[v]));
                    out_e[v]++;
                }
            }
            else {
                odd_cnt++;
                if(odd_cnt<=nin) {
                    if((out_e[v] % 2) == 0) {
                        ans.pb(mp(par[v], v));
                        out_e[par[v]]++;
                    }
                    else {
                        ans.pb(mp(v, par[v]));
                        out_e[v]++;
                    }
                    need_in.pb(v);
                }
                else {
                    if((out_e[v] % 2) == 1) {
                        ans.pb(mp(par[v], v));
                        out_e[par[v]]++;
                    }
                    else {
                        ans.pb(mp(v, par[v]));
                        out_e[v]++;
                    }    
                    need_out.pb(v);
                }
            }
        }
        if (odd_cnt < odd_vert[x]) {
            if (nin > odd_cnt) {
                need_in.pb(x);
            }
            else {
                need_out.pb(x);
            }
        }
    }
    while((need_in.size()>0)&&(need_out.size()>0)) {
        ans.pb(mp(need_out.back(), need_in.back()));
        need_in.pop_back();
        need_out.pop_back();
    }
    if(need_in.size()>0) {
        int u=need_in[0];
        int w=need_in[1];
        ans.pb(mp(u,w));
        ans.pb(mp(u,u));
    }
    if(need_out.size()>0) {
        int u=need_out[0];
        int w=need_out[1];
        ans.pb(mp(w,u));
        ans.pb(mp(u,u));
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

}