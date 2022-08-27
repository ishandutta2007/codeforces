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
const ll INF = 100000ll * 100000ll * 100000ll;

vector<deque<ll>> girls;

class streew {
public:
    vll t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, ll add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += add;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        }
    }
    
    ll get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};

class streemin {
public:
    vector<pair<ll, int>> t;
    vll tmod;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            tmod.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr) {
            t[v] = mp(girls[a[tl]].front(), a[tl]);
            tmod[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
            tmod[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, ll add) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
//            t[v].first += add;
            tmod[v] += add;
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            pair<ll, int> tv2(t[v*2]);
            tv2.first += tmod[v*2];
            pair<ll, int> tv21(t[v*2+1]);
            tv21.first += tmod[v*2+1];
            t[v] = min(tv2, tv21);
        }
    }
    
    pair<ll, int> get (int v, int tl, int tr, int l, int r) {
        if(l>r) {
            return mp(INF, -1);
        }
        if (l == tl && tr == r) {
            auto res = t[v];
            res.first += tmod[v];
            return res;
        }
        int tm = (tl + tr) / 2;
        auto res = min(get(v*2, tl, tm, l, min(r,tm)),
                   get(v*2+1, tm+1, tr, max(l,tm+1), r));
        res.first += tmod[v];
        return res;
    }
};
vector<streemin> hld;
int n;
vvi ch, nb;
vi par, v_lvl;
vvi lvl;


vi trav;
vi pos, rpos;
vi st;

void bfs1(int v) {
    pos[v] = trav.size();
    trav.pb(v);
    for(auto u : ch[v]) bfs1(u);
    rpos[v] = trav.size()-1;
}

vvi path;
vpi whichpath;

void dfshld(int v, int pind) {
    if (pind == -1) {
        pind = path.size();
        path.pb(vi());
    }
    
    whichpath[v] = mp(pind, (int)path[pind].size());
    path[pind].pb(v);
    for(auto u : ch[v]) {
        if (2*st[u] >= st[v]) dfshld(u, pind);
        else dfshld(u, -1);
    }
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,q;
    scanf("%d %d %d", &n, &m, &q);
    pos.resize(n);
    rpos.resize(n);
    v_lvl.resize(n);
    whichpath.resize(n);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    girls.resize(n);
    
    int mm=1;
    lvl[1].push_back(0);
    v_lvl[0]=1;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    int l=2;
    
    while(mm<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    mm++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    
    forn(i,1,m+1) {
        int x;
        scanf("%d", &x);
        x--;
        girls[x].pb(i);
    }
    forn(i,0,n) girls[i].pb(INF);
    bfs1(0);
    st.resize(n);
    forn(i,0,n) st[i] = rpos[i] - pos[i] + 1;
    streew w;
    vi wbase(n,0);
    w.build(wbase, 1, 0, n-1);
    
    dfshld(0,-1);
    
    for(auto & pt : path) {
        hld.pb(streemin());
        hld.back().build(pt, 1, 0, (int)pt.size() - 1);
    }
    
    forn(i,0,q) {
//        cout<<"------------\n";
//        forn(aa,0,3) {
//            forn(bb,0,3) {
//                cout<<girls[aa][bb]<< ' ';
//            }
//            cout<<endl;
//        }
//        cout<<"------------\n";
        int tp;
        scanf("%d", &tp);
        if(tp == 2) {
            int v;
            int kk;
            scanf("%d %d", &v, &kk);
            v--;
            ll k = kk;
            w.update(1, 0, n-1, pos[v], rpos[v], k);
            // get hld
            pi pt = whichpath[v];
            hld[pt.first].update(1, 0, (int)path[pt.first].size()-1, pt.second, (int)path[pt.first].size()-1, k);
        }
        else if(tp==1) {
            int u,v,k;
            scanf("%d %d %d", &u,&v,&k);
            u--;
            v--;
            vi ans;
            int uorig = u;
            int vorig = v;
            while(k>0) {
                u = uorig;
                v = vorig;
                pair<ll, int> best = mp(INF, -1);
                while(!(pos[u] <= pos[v] && pos[v] <= rpos[u])) {
                    pi wp =whichpath[u];
                    if(wp.second == 0) {
                        best = min(best, mp(girls[u].front() + w.get(1, 0, n-1, pos[u]), u));
                        u = par[u];
                    }
                    else {
                        int upar = path[wp.first][0];
                        if (pos[upar] <= pos[v] && pos[v] <= rpos[upar]) {
                            int l = 0;
                            int r = wp.second;
                            while(r-l>1) {
                                int med = (r+l)/2;
                                int um = path[wp.first][med];
                                if(pos[um] <= pos[v] && pos[v] <= rpos[um]) l = med;
                                else r = med;
                            }
                            int bper = hld[wp.first].get(1,0,(int)path[wp.first].size()-1,l,wp.second).second;
                            if(bper != -1) best = min(best, mp(girls[bper].front() + w.get(1, 0, n-1, pos[bper]), bper));
                            u= path[wp.first][l];
                        }
                        else {
                            int bper = hld[wp.first].get(1,0,(int)path[wp.first].size()-1,0,wp.second).second;
                            if(bper != -1) best = min(best, mp(girls[bper].front() + w.get(1, 0, n-1, pos[bper]), bper));
                            u = par[upar];
                        }
                    }
                }
                swap(u,v);
                while(!(pos[u] <= pos[v] && pos[v] <= rpos[u])) {
                    pi wp =whichpath[u];
                    if(wp.second == 0) {
                        best = min(best, mp(girls[u].front() + w.get(1, 0, n-1, pos[u]), u));
                        u = par[u];
                    }
                    else {
                        int upar = path[wp.first][0];
                        if (pos[upar] <= pos[v] && pos[v] <= rpos[upar]) {
                            int l = 0;
                            int r = wp.second;
                            while(r-l>1) {
                                int med = (r+l)/2;
                                int um = path[wp.first][med];
                                if(pos[um] <= pos[v] && pos[v] <= rpos[um]) l = med;
                                else r = med;
                            }
                            int bper = hld[wp.first].get(1,0,(int)path[wp.first].size()-1,l,wp.second).second;
                            if(bper != -1) best = min(best, mp(girls[bper].front() + w.get(1, 0, n-1, pos[bper]), bper));
                            u= path[wp.first][l];
                        }
                        else {
                            int bper = hld[wp.first].get(1,0,(int)path[wp.first].size()-1,0,wp.second).second;
                            if(bper != -1) best = min(best, mp(girls[bper].front() + w.get(1, 0, n-1, pos[bper]), bper));
                            u = par[upar];
                        }
                    }
                }
//                if(uorig == vorig) {
                best = min(best, mp(girls[u].front() + w.get(1, 0, n-1, pos[u]), u));
//                }
                if(best.first < INF) {
                    int up = best.second;
                    ans.pb(girls[up].front());
                    ll fix = girls[up][1] - girls[up][0];
                    girls[up].pop_front();
                    pi upp = whichpath[up];
                    hld[upp.first].update(1,0,(int)path[upp.first].size()-1,upp.second,upp.second, fix);
                    k--;                }
                else {
                    break;
                }
            }
            printf("%d", ans.size());
            for(auto u : ans) printf(" %d", u);
            printf("\n");
        }
    }
    
    
}