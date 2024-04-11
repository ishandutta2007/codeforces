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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int MAXN = 100000;
class DSU {
public:
    struct story {
        story(int tp, int ind, int val) : tp(tp), ind(ind), val(val) {};
        int tp;
        int ind;
        int val;
    };
    DSU(int n) {
        forn(i,0,n) {
            make_set(i);
        }
    }
    int nb[MAXN];
    int parent[MAXN];
    int rk[MAXN];
    vector<story> hist;
    
    void make_set (int v) {
        parent[v] = v;
        rk[v] = 0;
        nb[v] = -1;
    }
    
    int find_set (int v, bool pers) {
        if (v == parent[v])
            return v;
        int np = find_set(parent[v], pers);
        if(pers && (np != parent[v])) hist.emplace_back(1, v, parent[v]);
        return parent[v] = np;
    }
    
    int union_sets_basic(int a, int b, bool pers) {
        a = find_set (a,pers);
        b = find_set (b,pers);
        if (a != b) {
            if (rk[a] < rk[b])
                swap (a, b);
            if(pers) hist.emplace_back(1, b, parent[b]);
            parent[b] = a;
            if (rk[a] == rk[b]) {
                if (pers) hist.emplace_back(2, a, rk[a]);
                ++rk[a];
            }
        }
        return a;
    }
    
    bool union_sets (int a, int b, bool pers) {
        a = find_set(a,pers);
        b = find_set(b,pers);
        if(a == b) return false;
        int ua = a;
        int ub = b;
        if (nb[b] != -1) ua = union_sets_basic(a, nb[b], pers);
        if (nb[a] != -1) ub = union_sets_basic(b, nb[a], pers);
        if (nb[ua] != ub) {
            if (pers) hist.emplace_back(0,ua,nb[ua]);
            nb[ua] = ub;
        }
        if (nb[ub] != ua) {
            if (pers) hist.emplace_back(0,ub,nb[ub]);
            nb[ub] = ua;
        }
        return true;
    }
    
    void undo() {
        reverse(all(hist));
        for(auto x : hist) {
            if (x.tp == 0) {
                nb[x.ind] = x.val;
            }
            else if(x.tp == 1) {
                parent[x.ind] = x.val;
            }
            else if(x.tp == 2) {
                rk[x.ind] = x.val;
            }
        }
        hist.clear();
    }
};



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    vpi e(q);
    forn(i,0,q) {
        scanf("%d %d", &e[i].first, &e[i].second);
        e[i].first--;
        e[i].second--;
    }
    
    int A = 300;
    set<pi> cur;
    int s = 0;
    while(s < q) {
        set<pi> base = cur;
        forn(i,s,min(s+A,q)) {
            if(base.find(e[i]) != base.end()) base.erase(e[i]);
        }
        set<pi> add = cur;
        for (auto x : base) add.erase(x);
        DSU dsu(n);
        bool dd = true;
        for(auto x : base) {
            dd = dd & dsu.union_sets(x.first, x.second, false);
            if(!dd) break;
        }
        
        forn(i,s,min(s+A,q)) {
            if(add.find(e[i]) != add.end()) add.erase(e[i]);
            else add.insert(e[i]);
            bool dcur = dd;
            for (auto x : add) {
                if(!dcur) break;
                dcur = dcur & dsu.union_sets(x.first, x.second, true);
            }
            if(dcur) printf("YES\n");
            else printf("NO\n");
            dsu.undo();
        }
        swap(cur, base);
        for(auto x : add) cur.insert(x);
        s += A;
    }
    
}