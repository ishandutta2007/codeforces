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
struct Node {
    Node *l = 0, *r = 0;
    int val, y, c = 1;
    ll s;
    int pos;
    Node(int val, int pos) : val(val), y(rng()), s(val), pos(pos) {}
    void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
ll sum(Node* n) { return n ? n->s : 0LL; }
void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    s = sum(l) + sum(r) + val;
}

template<class F> void each(Node* n, F f) {
    if (n) { each(n->l, f); f(n->val, n->pos); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
    if (n->val <= k) { // "n->val >= k" for lower_bound(k)
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    } else {
        auto pa = split(n->r, k); // and just "k"
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}

Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
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

struct Tree{
    Node* root;
    int start;
    ll value;
    Tree(Node* _root, int _start, ll _value) : root(_root), start(_start), value(_value) {}
};

void __print(Tree t){cerr << '{' << t.start << ',' << t.value << ',' << cnt(t.root) << '}';}

bool operator<(Tree a, Tree b){
    return a.start < b.start;
}

Tree insert(Tree t, int a, int b){
    // debug(t.start, a, cnt(t.root));
    // assert(t.start <= a && a <= t.start + cnt(t.root));
    auto sp = split(t.root, b);
    t.value += sum(sp.second);
    int new_pos = t.start + cnt(sp.first);
    t.value += (ll) b * (new_pos - a);
    debug(sum(sp.second), cnt(sp.second), a, b, new_pos, t.value);
    Node* new_node = new Node(b, a);
    t.root = merge(merge(sp.first, new_node), sp.second);
    return t;
}

Tree merge_trees(Tree a, Tree b){
    assert(a < b);
    assert(a.start + cnt(a.root) >= b.start);
    if(cnt(a.root) < cnt(b.root)){
        debug("swapping");
        b.value -= sum(b.root) * (b.start - a.start);
        b.start = a.start;
        swap(a, b);
    }
    debug(a.value);
    // merge b into a
    each(b.root, [&](int val, int pos){
        debug(pos, val);
        a = insert(a, pos, val);
    });
    return a;
}

void solve(){
    int n;
    cin >> n;
    set<Tree> trees;
    ll ans = 0;
    while(n--){
        debug(trees);
        int a, b;
        cin >> a >> b;
        Tree tmp = Tree(new Node(b, a), a, 0);
        auto it = trees.upper_bound(tmp);
        if(it != trees.begin() && prev(it)->start <= a && a <= prev(it)->start + cnt(prev(it)->root)){
            debug("merge into existing");
            it = prev(it);
            Tree t = insert(*it, a, b);
            ans -= it->value;
            trees.erase(it);
            ans += t.value;
            debug(t.value);
            it = trees.insert(t).first;
        }else{
            debug("insert new treap");
            ans += tmp.value;
            it = trees.insert(tmp).first;
        }
        debug(trees);
        auto nit = next(it);
        if(nit != trees.end() && it->start + cnt(it->root) >= nit->start){
            debug("merge two trees");
            Tree t = merge_trees(*it, *nit);
            ans -= it->value;
            ans -= nit->value;
            trees.erase(it);
            trees.erase(nit);
            ans += t.value;
            trees.insert(t);
        }
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}