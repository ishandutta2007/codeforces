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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

struct Node {
    Node *l = 0, *r = 0;
    int val, y, c = 1;
    int madd = 0;
    Node(int val) : val(val), y(rng()) {}
    void recalc();
    void push();
    void add(int num){
        val += num;
        madd += num;
    }
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }
void Node::push(){
    if(madd != 0){
        if(l) l->add(madd);
        if(r) r->add(madd);
        madd = 0;
    }
}

template<class F> void each(Node* n, F f) {
    if (n) { n->push(); each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split_value(Node* n, int k) {
    if (!n) return {};
    n->push();
    if (n->val >= k) { // "n->val >= k" for lower_bound(k)
        auto pa = split_value(n->l, k);
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    } else {
        auto pa = split_value(n->r, k); // and just "k"
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}

pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
    n->push();
    if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    } else {
        auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}

Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    l->push();
    r->push();
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->recalc();
        return r;
    }
}

Node* ins(Node* t, Node* n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.first, n), pa.second);
}

const int INF = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vpii intervals;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y+1});
    }
    Node* root = new Node(0);
    for(int i = 0; i < n; i++){
        root = merge(root, new Node(INF));
    }

    for(int i = 0; i < n; i++){
        int l, r;
        tie(l, r) = intervals[i];
        Node* more;
        Node* less;
        tie(root, more) = split_value(root, r-1);
        tie(less, root) = split_value(root, l);
        if(root) root->add(1);
        more = split(more, 1).second;
        Node* nn = new Node(l);
        root = merge(less, merge(nn, merge(root, more)));
    }
    // each(root, [&] (int val) {debug(val);});
    cout << cnt(split_value(root, INF).first)-1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}