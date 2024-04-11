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

struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;
    
    vector<int> stack;
    vector<bool> in_stack;
    
    vector<vector<int>> components;
    vector<int> which_component;
    
    SCC(int v = 0) {
        init(v);
    }
    
    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }
    
    void init(int v) {
        V = v;
        adj.assign(V, {});
    }
    
    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = int(adj.size());
    }
    
    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }
    
    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;
        
        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }
        
        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.emplace_back();
            vector<int> &component = components.back();
            int x;
            
            do {
                //                assert(!stack.empty());
                x = stack.back();
                stack.pop_back();
                in_stack[x] = false;
                which_component[x] = int(components.size()) - 1;
                component.push_back(x);
            } while (x != node);
        }
    }
    
    void build() {
        tour_index.assign(V, -1);
        low_link.resize(V);
        which_component.assign(V, -1);
        
        stack.clear();
        stack.reserve(V);
        in_stack.assign(V, false);
        tour = 0;
        
        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};
        
        for (int i = 0; i < V; i++)
            if (tour_index[i] < 0)
                dfs(i);
    }
};
struct two_sat {
    int n = 0;
    vector<vector<int>> adj;
    vector<bool> assignment;
    SCC scc;
    
    int inv(int var) {
        return var ^ 1;
    }
    
    int new_var() {
        adj.emplace_back();
        adj.emplace_back();
        return 2 * n++;
    }
    
    void implies(int a, int b) {
        adj[a].push_back(b);
        adj[inv(b)].push_back(inv(a));
    }
    
    void either(int a, int b) {
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
    }
    
    void set_value(int a) {
        adj[inv(a)].push_back(a);
    }
    
    void equal(int a, int b) {
        implies(a, b);
        implies(inv(a), inv(b));
    }
    
    void unequal(int a, int b) {
        implies(a, inv(b));
        implies(inv(a), b);
    }
    
    // Warning: this only creates an implication in the negative direction. It is still possible for
    // a = b = true with and_var = false. In particular, it does not work to call set_value on inv(and_var).
    int create_and(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(result, a);
        implies(result, b);
        return result;
    }
    
    // Warning: this only creates an implication in the positive direction. It is still possible for
    // a = b = false with or_var = true. In particular, it does not work to call set_value on or_var.
    int create_or(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(a, result);
        implies(b, result);
        return result;
    }
    
    int create_at_most_one(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        either(inv(a), inv(b));
        return create_or(a, b);
    }
    
    template<typename T_iterable>
    int create_at_most_one(const T_iterable &vars) {
        int aux = -1;
        
        for (int var : vars)
            aux = create_at_most_one(aux, var);
        
        return aux;
    }
    
    bool solve() {
        scc.init(adj);
        scc.build();
        
        for (int i = 0; i < n; i++)
            if (scc.which_component[2 * i] == scc.which_component[2 * i + 1])
                return false;
        
        assignment.resize(2 * n);
        vector<bool> done(n, false);
        
        // Tarjan's algorithm provides the SCCs in reverse topological order.
        for (auto &component : scc.components)
            for (int x : component) {
                assignment[x] = !done[x / 2];
                done[x / 2] = true;
            }
        
        //        for (int i = 0; i < n; i++)
        //            assert(assignment[2 * i] ^ assignment[2 * i + 1]);
        
        return true;
    }
};

bool eq(const vi & a, const vi & b) {
    return a == b || a == vi({b[1], b[0]});
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    map<string, string> neg;
    neg["and"] = "nand"; neg["nand"] = "and"; neg["or"] = "nor"; neg["nor"] = "or";
    int n,m,k;
    cin>>n>>m>>k;
    vs op1(m), op2(k);
    vvi mask1(m), mask2(k);
    string msk;
    forn(i,0,m) {
        cin>>op1[i]>>msk;
        forn(j,0,msk.size()) if(msk[j] == 'x') mask1[i].pb(j);
    }
    forn(i,0,k) {
        cin>>op2[i]>>msk;
        forn(j,0,msk.size()) if(msk[j] == 'x') mask2[i].pb(j);
    }
    forn(i,0,m) {
        op1.pb(neg[op1[i]]);
        mask1.pb(mask1[i]);
    }
    forn(i,0,k) {
        if(op2[i] == "nor") {
            op2[i] = "and";
            mask2[i][0] += m;
            mask2[i][1] += m;
        }
        if(op2[i] == "nand") {
            op2[i] = "or";
            mask2[i][0] += m;
            mask2[i][1] += m;
        }
    }
    int f0 = 0, f1 = 0;
    vi tp1, tp2;
    int add = 0;
    forn(i,0,k) {
        if(op2[i] == "and") {
            if(op1[mask2[i][0]][0] == 'n' && op1[mask2[i][1]][0] == 'n') {
                add++;
                continue;
            }
            if(op1[mask2[i][0]][0] != 'n' && op1[mask2[i][1]][0] != 'n') {
                add++;
                continue;
            }
            if(op1[mask2[i][0]].back() == op1[mask2[i][1]].back()) {
                if(!eq(mask1[mask2[i][0]], mask1[mask2[i][1]])) add++;
                else f0++;
                continue;
            }
            if(op1[mask2[i][0]][0] == 'n') swap(mask2[i][0], mask2[i][1]);
            if(op1[mask2[i][0]] == "or") {
                add++;
                continue;
            }
            else {
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) swap(mask1[mask2[i][1]][0],mask1[mask2[i][1]][1]);
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) swap(mask1[mask2[i][0]][0],mask1[mask2[i][0]][1]);
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) swap(mask1[mask2[i][1]][0],mask1[mask2[i][1]][1]);
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) add++;
                else tp1.pb(i);
            }
        }
        else {
            if(op1[mask2[i][0]][0] == 'n' && op1[mask2[i][1]][0] == 'n') {
                add++;
                continue;
            }
            if(op1[mask2[i][0]][0] != 'n' && op1[mask2[i][1]][0] != 'n') {
                add++;
                continue;
            }
            if(op1[mask2[i][0]].back() == op1[mask2[i][1]].back()) {
                if(!eq(mask1[mask2[i][0]], mask1[mask2[i][1]])) add++;
                else f1++;
                continue;
            }
            if(op1[mask2[i][0]][0] == 'n') swap(mask2[i][0], mask2[i][1]);
            if(op1[mask2[i][0]] == "or") {
                add++;
                continue;
            }
            else {
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) swap(mask1[mask2[i][1]][0],mask1[mask2[i][1]][1]);
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) swap(mask1[mask2[i][0]][0],mask1[mask2[i][0]][1]);
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) swap(mask1[mask2[i][1]][0],mask1[mask2[i][1]][1]);
                if(mask1[mask2[i][0]][0] != mask1[mask2[i][1]][0]) add++;
                else tp2.pb(i);
            }
        }
    }
    int ans = 0;
    two_sat t1;
    forn(i,0,n) t1.new_var();
    for(auto ind : tp1) {
        int i1 = mask2[ind][0];
        int i2 = mask2[ind][1];
        t1.implies(mask1[i1][0]*2, mask1[i1][1]*2);
        t1.implies(mask1[i1][0]*2+1, mask1[i2][1]*2+1);
    }
    if(f0 || !t1.solve()) ans = max(ans, f0+(int)tp1.size());

    two_sat t2;
    forn(i,0,n) t2.new_var();
    for(auto ind : tp2) {
        int i1 = mask2[ind][0];
        int i2 = mask2[ind][1];
        t2.implies(mask1[i1][0]*2, mask1[i1][1]*2+1);
        t2.implies(mask1[i1][0]*2+1, mask1[i2][1]*2);
    }
    if(f1 || !t2.solve()) ans = max(ans, f1+(int)tp2.size());
    
    if(ans == 0) cout<<-1;
    else cout<<k-ans;
    
}