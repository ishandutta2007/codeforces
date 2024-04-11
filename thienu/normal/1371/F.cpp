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
const int INF = 1e9 + 7;
// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
struct Node {
    Node *l = 0, *r = 0;
    int val, y, c = 1;
    int d = 0, lo, hi;
    Node(int val) : val(val), lo(val), hi(val), y(rng()) {}
    void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
int diff(Node* n) {return n ? n->d : 0; }
int min(Node* n) {return n ? n->lo : INF; }
int max(Node* n) {return n ? n->hi : -INF; }

void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    lo = l ? min(l) : val;
    hi = r ? max(r) : val;
    d = max({0, diff(l), diff(r), l ? val - max(l) : 0, r ? min(r) - val : 0});
}

template<class F> void each(Node* n, F f) {
    if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
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

pair<Node*, Node*> split_value(Node* n, int k) {
    if (!n) return {};
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

void add_toggle(Node* &t1, Node* &t2, int where){
    debug("add", where);
    Node *t1f, *t1s, *t2f, *t2s;
    tie(t1f, t1s) = split_value(t1, where);
    tie(t2f, t2s) = split_value(t2, where);
    Node* nn = new Node(where);
    // debug(max(t1f), max(t2f), min(t1s));
    if(max(t1f) > max(t2f)){
        debug("merge into 2");
        t2f = merge(t2f, nn);
    }else{
        debug("merge into 1");
        t1f = merge(t1f, nn);
    }
    t1 = merge(t1f, t2s);
    t2 = merge(t2f, t1s);
}

void rem_toggle(Node* &t1, Node* &t2, int where){
    debug("rem", where);
    Node *t1f, *t1s, *t2f, *t2s;
    tie(t1f, t1s) = split_value(t1, where);
    tie(t2f, t2s) = split_value(t2, where);
    t1s = split_value(t1s, where+1).second;
    t2s = split_value(t2s, where+1).second;
    t1 = merge(t1f, t2s);
    t2 = merge(t2f, t1s);
}

void toggle(Node* &t1, Node* &t2, int where, vi &exists){
    if(exists[where]){
        rem_toggle(t1, t2, where);
    }else{
        add_toggle(t1, t2, where);
    }
    debug(cnt(t1), cnt(t2));
    exists[where] ^= 1;
}

void solve(){
    int n, q;
    cin >> n >> q;
    n++;
    string s;
    cin >> s;
    s = '>' + s + '<';
    vi changes = {(int)(-1e9)};
    vi exists(n);
    for(int i = 0; i < n; i++){
        if(s[i] != s[i+1]){
            changes.push_back(i);
            exists[i] = 1;
        }
    }
    changes.push_back(1e9);
    debug(changes);

    Node* t1 = 0;
    Node* t2 = 0;
    for(int i = 0, t = 1; i < changes.size(); i++, t^=1){
        if(t) t1 = merge(t1, new Node(changes[i]));
        else t2 = merge(t2, new Node(changes[i]));
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        toggle(t1, t2, x-1, exists);
        toggle(t1, t2, y, exists);
        Node *left, *right;
        debug("s");
        tie(t1, right) = split_value(t1, y);
        tie(left, t1) = split_value(t1, x);
        debug(exists);
        debug(diff(t1), max(t1), min(t1));
        if(cnt(t1) == 0){
            cout << y-x+1 << '\n';
        }else{
            cout << max({diff(t1), y-max(t1), min(t1)-x+1}) << '\n';
        }
        t1 = merge(merge(left, t1), right);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}