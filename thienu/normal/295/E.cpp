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


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// treap practice, using kactl as reference
struct Node{
    Node* l = 0;
    Node* r = 0;
    int val, c = 1;
    ll s = val, d = 0;
    ll priority;
    Node(int val) : val(val), priority(rng()) {};

    void recalc();
};

int cnt(Node* n){
    return n ? n -> c : 0;
}

ll sum(Node* n){
    return n ? n -> s : 0LL;
}

ll diff(Node* n){
    return n ? n -> d : 0LL;
}

void Node::recalc(){
    c = cnt(l) + cnt(r) + 1LL;
    s = sum(l) + sum(r) + (ll) val;
    d = diff(l) + diff(r) + (cnt(l)+1) * sum(r) - (cnt(r)+1) * sum(l) + (cnt(l) - cnt(r)) * (ll) val;
}

// splits, left side up to but not including value k
pair<Node*, Node*> split(Node* n, int k){
    if(!n) return {};
    if(n->val >= k){
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    }else{
        auto pa = split(n->r, k);
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}

Node* merge(Node* l, Node* r){
    if(!l) return r;
    if(!r) return l;
    if(l->priority > r->priority){
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    }else{
        r->l = merge(l, r->l);
        r->recalc();
        return r;
    }
}

Node* insert(Node* n, int val){
    auto pa = split(n, val);
    Node* new_node = new Node(val);
    return merge(merge(pa.first, new_node), pa.second);
}

Node* erase(Node* n, int val){
    // alternative
    auto pa = split(n, val);
    auto pb = split(pa.second, val+1);
    debug(cnt(pa.first), cnt(pb.second));
    return merge(pa.first, pb.second);


    // if(n->val == val){
    //     // Node* m = n;
    //     // debug("merging", cnt(n->l), cnt(n->r));
    //     n = merge(n->l, n->r);
    //     if(n) n->recalc();
    //     return n;
    //     // delete m;
    // }else{
    //     if(val < n->val){
    //         n->l = erase(n->l, val);
    //     }else{
    //         n->r = erase(n->r, val);
    //     }
    //     n->recalc();
    //     return n;
    // }
}

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n); each(n->r, f); }
}

void solve(){
    int n;
    cin >> n;
    vi pts(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i];
    }
    Node* treap = 0;
    for(int i = 0; i < n; i++){
        treap = insert(treap, pts[i]);
    }
    debug(sum(treap), diff(treap));
    int q;
    cin >> q;
    while(q--){
        debug(cnt(treap));
        // each(treap, [&](Node* n){debug(n->val, cnt(n), cnt(n->l), cnt(n->r), sum(n), diff(n));});
        int t;
        cin >> t;
        if(t == 1){
            int p, d;
            cin >> p >> d;
            p--;
            // add d to pts[p]
            int a = pts[p];
            int b = pts[p] + d;
            debug(pts, a, b);
            pts[p] = b;
            // upd treap
            treap = erase(treap, a);
            treap = insert(treap, b);
        }else{
            int l, r;
            cin >> l >> r;
            debug(pts);
            auto pa = split(treap, l);
            auto pb = split(pa.second, r+1);
            // each(pb.first, [&](Node* n){debug(n->val, cnt(n), cnt(n->l), cnt(n->r), sum(n), diff(n));});
            cout << diff(pb.first) << endl;
            treap = merge(merge(pa.first, pb.first), pb.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}