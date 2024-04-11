#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto& it:c)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(a) ((a).size())
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

struct Tree {
    typedef vi T;
    const T LOW = vi();
    T f(T a, T b) { 
        vi ans(a.size()+b.size());
        ans.resize(set_union(allof(a),allof(b),ans.begin())-ans.begin());
        ans.resize(unique(allof(ans))-ans.begin());
        while(ans.size()>10)ans.pop_back();
        return ans;
    }
    int n;
    vector<T> s;
    Tree() {}
    Tree(int m, T def) { init(m, def); }
    void init(int m, T def) {
        n = 1; while (n < m) n *= 2;
        s.assign(n + m, def);
        s.resize(2 * n, LOW);
        for (int i = n; i --> 1; )
            s[i] = f(s[i * 2], s[i*2 + 1]);
    }
    void update(int pos, T val) {
        pos += n;
        s[pos] = val;
        for (pos /= 2; pos >= 1; pos /= 2)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int a, int b) { return que(1, a, b, 0, n); }
    T que(int pos, int a, int b, int x, int y) {
        if (a >= b) return LOW;
        if (a == x && b == y) return s[pos];
        int m = (x + y) / 2;
        return f(que(2 * pos, a, min(b, m), x, m),
                que(2 * pos + 1, max(a, m), b, m, y));
    }
};

typedef vector<pair<int,vi> > vpi;
struct Node {
    int d, par, chain = -1, pos = -1;
    vi val;
};
struct Chain {
    int par;
    vector<int> nodes;
    Tree tree;
};
vector<vi> VVV;

struct HLD {
    typedef vi T;
    const T LOW = vi();
    T f(T &a, T b) { 
        vi ans(a.size()+b.size());
        ans.resize(set_union(allof(a),allof(b),ans.begin())-ans.begin());
        ans.resize(unique(allof(ans))-ans.begin());
        while(ans.size()>10)ans.pop_back();
        return a=ans;
    }
    vector<Node> V;
    vector<Chain> C;
    HLD(vector<vpi>& g) : V(sz(g)) {
        dfs(0, -1, g, 0);
        trav(c, C){
            c.tree.init(sz(c.nodes), LOW);
            for (int ni : c.nodes)
                c.tree.update(V[ni].pos, V[ni].val);
        }
    }
    void update(int node, T val) {
        Node& n = V[node];
        n.val=val;
        if (n.chain == -1) n.val = val;
        else C[n.chain].tree.update(n.pos, val);
    }
    int pard(Node& nod) {
        if (nod.par == -1) return -1;
        return V[nod.chain == -1 ? nod.par : C[nod.chain].par].d;
    }
    // query a l l edges between n1, n2
    pair<T, int> query(int i1, int i2) {
        T ans = LOW;
        while(i1 != i2) {
            Node n1 = V[i1], n2 = V[i2];
            if (n1.chain != -1 && n1.chain == n2.chain) {
                int lo = n1.pos, hi = n2.pos;
                if (lo > hi) swap(lo, hi);
                f(ans, C[n1.chain].tree.query(lo, hi));
                i1 = i2 = C[n1.chain].nodes[hi];
            } else {
                if (pard(n1) < pard(n2))
                    n1 = n2, swap(i1, i2);
                if (n1.chain == -1)
                    f(ans, n1.val), i1 = n1.par;
                else {
                    Chain& c = C[n1.chain];
                    f(ans, n1.pos ? c.tree.query(n1.pos, sz(c.nodes))
                            : c.tree.s[1]);
                    i1 = c.par;
                }
            }
        }
        return make_pair(ans, i1);
    }
    // query a l l nodes between n1, n2
    pair<T, int> query2(int i1, int i2) {
        pair<T, int> ans = query(i1, i2);
        f(ans.first, V[ans.second].val);
        return ans;
    }
    pii dfs(int at, int par, vector<vpi>& g, int d) {
        V[at].d = d; V[at].par = par;
        int sum = 1, ch, nod, sz;
        tuple<int,int,int> mx(-1,-1,-1);
        trav(e, g[at]){
            if (e.first == par){
                //e.second = VVV[at];
                continue;
            }
            tie(sz, ch) = dfs(e.first, at, g, d+1);
            V[e.first].val = e.second;
            sum += sz;
            mx = max(mx, make_tuple(sz, e.first, ch));
        }
        tie(sz, nod, ch) = mx;
        if (2*sz < sum) return pii(sum, -1);
        if (ch == -1) { ch = sz(C); C.emplace_back(); }
        V[nod].pos = sz(C[ch].nodes);
        V[nod].chain = ch;
        C[ch].par = at;
        C[ch].nodes.push_back(nod);
        return pii(sum, ch);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<vpi> g(n);
    rep(i,0,n-1){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        g[a].pb({b,vi()});
        g[b].pb({a,vi()});
    }
    VVV.resize(n);
    rep(i,1,m+1){
        int a;
        scanf("%d",&a);
        a--;
        if(VVV[a].size()<10)VVV[a].pb(i);
    }
    HLD hld(g);
    rep(i,0,n){
        hld.update(i,VVV[i]);    
    }
    rep(i,0,q){
        int v,u,k;
        scanf("%d%d%d",&v,&u,&k);
        u--,v--;
        auto p=hld.query2(u,v);
        k=min((int)p.first.size(),k);
        printf("%d ",k);
        rep(j,0,k)printf("%d ",p.first[j]);
        puts("");
    }
    return 0;
}