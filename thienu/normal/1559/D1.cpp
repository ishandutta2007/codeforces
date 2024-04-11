#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void take_input(int m, vvi &adj){
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int cc(int n, vvi &adj, vvi &comps, vi &comp_num){
    comps.clear();
    comp_num.resize(n);
    fill(comp_num.begin(), comp_num.end(), -1);
    vi vis(n);
    queue<int> q;
    int ccnt = 0;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        vi comp;
        q.push(i);
        comp.push_back(i);
        comp_num[i] = ccnt;
        vis[i] = 1;
        while(!q.empty()){
            // debug(q.size());
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(vis[v]) continue;
                vis[v] = 1;
                q.push(v);
                comp.push_back(v);
                comp_num[v] = ccnt;
            }
        }
        ccnt++;
        comps.push_back(comp);
    }
    return ccnt;
}

struct Node{
    set<pii> s;
    int cnum;
    Node(int comp_num){
        cnum = comp_num;
    }

    bool add(int u, int pos){
        auto it = s.lower_bound({u, 0});
        if(it == s.end() || it->first > u){
            s.insert({u, pos});
            return true;
        }
        return false;
    }

    size_t size(){
        return s.size();
    }

    bool convert(int from, int to){
        auto it = s.lower_bound({from, 0});
        int its = it->second;
        s.erase(it);
        return add(to, its);
    }
};
void __print(Node* x) {cerr << '{' << x->cnum << ",{"; for(pii a : x->s) cerr << '{' << a.first << ',' << a.second << "},"; cerr << "}}"; }

vector<set<Node*>> has_num;
vi num_cnt;
set<Node*> s;
set<Node*> mult;

void merge(Node* x, Node* y, int a, int b){
    debug(x, y, a, b);
    if(x->size() < y->size()) swap(x, y);
    for(pii p : y->s){
        has_num[p.first].erase(y);
        num_cnt[p.first]--;
        if(x->add(p.first, p.second)){
            has_num[p.first].insert(x);
            num_cnt[p.first]++;
        }
    }
    s.erase(y);
    mult.erase(y);
    if(num_cnt[a] < num_cnt[b]) swap(a, b);
    for(Node* n : has_num[b]){
        if(n->convert(b, a)){
            has_num[a].insert(n);
            num_cnt[a]++;
        }
        mult.erase(n);
        if(n->size() > 1) mult.insert(n);
    }
    has_num[b].clear();
    num_cnt[b] = 0;
    mult.erase(x);
    if(x->size() > 1) mult.insert(x);
}

pii merge_something(Node* x, Node* y){
    if(x->size() < y->size()) swap(x, y);
    int a = (x->s.begin())->first, b = (y->s.begin())->first;
    int u = (x->s.begin())->second, v = (y->s.begin())->second;
    if(a == b){
        assert(x->size() > 1);
        a = next(x->s.begin())->first;
        u = next(x->s.begin())->second;
    }
    merge(x, y, a, b);
    debug(s);
    debug(u, v);
    return {u, v};
}

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vvi adj1(n), adj2(n);
    take_input(m1, adj1);
    take_input(m2, adj2);
    vvi comps1, comps2;
    vi comp_num1, comp_num2;
    int ccnt1 = cc(n, adj1, comps1, comp_num1);
    int ccnt2 = cc(n, adj2, comps2, comp_num2);
    debug(comps1, comp_num1, comps2, comp_num2);
    if(ccnt1 > ccnt2){
        swap(ccnt1, ccnt2);
        swap(comps1, comps2);
        swap(comp_num1, comp_num2);
        swap(m1, m2);
        swap(adj1, adj2);
    }
    has_num.resize(ccnt2);
    num_cnt.resize(ccnt2);
    for(int i = 0; i < ccnt1; i++){
        Node* c = new Node(i);
        for(int j : comps1[i]){
            if(c->add(comp_num2[j], j)){
                has_num[comp_num2[j]].insert(c);
                num_cnt[comp_num2[j]]++;
            }
        }
        s.insert(c);
    }
    for(auto x : s){
        if(x->size() > 1){
            mult.insert(x);
        }
    }
    // debug((*(s.begin()))->s);
    debug(s, mult);

    vpii ans;
    while(s.size() > 1){
        Node* x;
        Node* y;
        if(!mult.empty()){
            x = *mult.begin();
        }else{
            x = *s.begin();
        }
        y = *s.begin();
        if(x == y){
            y = *next(s.begin());
        }
        ans.push_back(merge_something(x, y));
    }
    cout << ans.size() << endl;
    for(pii p : ans){
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}