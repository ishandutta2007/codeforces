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

class stree_set {
    public:
    set<int> t[400000];
    int s;
    void build (int n,int v, int tl, int tr) {
        if(v==1) {
//            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
        t[v].insert(tl);
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2];
            for(auto x : t[v*2+1]) t[v].insert(x);
        }
    }
    
    void del (int v, int tl, int tr, int pos) {
        t[v].erase(pos);
        if (pos == tl && tr == pos) {
            
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) del(v*2, tl, tm, pos);
            else del(v*2+1, tm+1, tr, pos);
        }
    }
    
    set<int> get (int v, int tl, int tr, int l, int r) {
        if(l>r) return set<int>();
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        set<int> res=get (v*2, tl, tm, l, min(r,tm));
        set<int> res2=get(v*2+1, tm+1, tr, max(l,tm+1), r);
        if(res2.size()>res.size()) swap(res,res2);
        for(auto x : res2)  res.insert(x);
        return res;
    }
};

class stree_otr {
    public:
    set<int> t[400000];
    int s;
    void build (int n,int v, int tl, int tr) {
        if(v==1) {
//            t.resize(n * 4);
            s = n;
        }
    }
    
    set<int> get (int v, int tl, int tr, int pos) {
        if (pos == tl && tr == pos) {
            return t[v];
        }
        else {
            set<int> res;
            int tm = (tl + tr) / 2;
            if(pos<=tm) res =get(v*2, tl, tm, pos);
            else res =get(v*2+1, tm+1, tr, pos);
            for(auto x : t[v]) res.insert(x);
            return res;
        }
    }
    
    void add (int v, int tl, int tr, int l, int r, int num) {
        if(l>r) return;
        if (tl == l && tr == r){
            t[v].insert(num);
            return;
        }
        int tm = (tl + tr) / 2;
        add(v*2, tl, tm, l, min(r,tm),num);
        add(v*2+1, tm+1, tr, max(l,tm+1), r,num);
    }
    
    void rem (int v, int tl, int tr, int l, int r, int num) {
        if(l>r) return;
        if (tl == l && tr == r){
            t[v].erase(num);
            return;
        }
        int tm = (tl + tr) / 2;
        rem(v*2, tl, tm, l, min(r,tm),num);
        rem(v*2+1, tm+1, tr, max(l,tm+1), r,num);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const ll INF = 1e18;
    int n,m,s;
    scanf("%d %d %d", &n, &m, &s);
    vector<vector<pair<pi, ll>>> e(n);
    stree_otr otr;
    otr.build(n, 1, 0, n-1);
    vector<pair<pi, pll>> e3;
    forn(i,0,m) {
        int t;
        scanf("%d", &t);
        if(t==1) {
            int u,v,d;
            scanf("%d %d %d", &v, &u, &d);
            v--;
            u--;
            e[v].pb(mp(mp(u,u), (ll)d));
        }
        else if(t==2) {
            int v,l,r,d;
            scanf("%d %d %d %d", &v, &l, &r, &d);
            v--;
            l--; r--;
            e[v].pb(mp(mp(l,r), (ll)d));
        }
        else if(t==3){
            int v,l,r,d;
            scanf("%d %d %d %d", &v, &l, &r, &d);
            v--;
            l--; r--;
            int num = e3.size();
            e3.pb(mp(mp(l,r),mp(v,d)));
            otr.add(1, 0, n-1, l, r, num);
        }
    }
    stree_set vleft;
    vleft.build(n, 1, 0, n-1);
    s--;
    vll d(n, INF);
//    d[0] = 0;
    set<pair<ll, pi>> q;
    q.insert(mp(0, mp(s,s)));
    while(!q.empty()) {
        auto x = *q.begin();
        q.erase(q.begin());
        if(x.second.second!=x.second.first) {
            auto what = vleft.get(1, 0, n-1, x.second.first, x.second.second);
            for(auto v : what) {
                vleft.del(1, 0, n-1, v);
                if(d[v] > x.first) {
                    q.insert(mp(x.first, mp(v,v)));
                }
            }
        }
        else {
            int v = x.second.first;
            if(d[v] <= x.first) continue;
            d[v] = x.first;
            auto what = otr.get(1, 0, n-1, v);
            for(auto y : what) {
                int to = e3[y].second.first;
                ll w = e3[y].second.second;
                otr.rem(1, 0, n-1, e3[y].first.first, e3[y].first.second, y);
                q.insert(mp(x.first+w, mp(to,to)));
            }
            for(auto y : e[v]) {
                q.insert(mp(x.first+y.second, y.first));
            }
        }
        
    }
    forn(i,0,n) if(d[i]==INF) d[i] = -1;
    forn(i,0,n) printf("%lld ", d[i]);
    
    
}