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
    ll sum = 0;
    Node(int val) : val(val), y(rng()), sum(val) {}
    void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
ll get_sum(Node* n) { return n ? n->sum : 0; }
void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    sum = get_sum(l) + get_sum(r) + val;
}

template<class F> void each(Node* n, F f) {
    if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
    if (n->val >= k) { // "n->val >= k" for lower_bound(k)
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

Node* ins(Node* t, Node* n) {
    auto pa = split(t, n->val);
    return merge(merge(pa.first, n), pa.second);
}

// end kactl

// ll isqrt(ll n){
//     ll x = n;
//     ll y = (x + 1) >> 1;
//     while(y < x){
//         x = y;
//         y = (x + n / x) >> 1;
//     }
//     return x;
// }

ll st_get(vll &st, int tl, int tr, int pos, int idx){
    if(tl == tr){
        return st[pos];
    }
    st[2 * pos] += st[pos];
    st[2 * pos + 1] += st[pos];
    st[pos] = 0;
    if(idx <= tl + (tr - tl) / 2){
        return st_get(st, tl, tl + (tr - tl) / 2, pos * 2, idx);
    }else{
        return st_get(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, idx);
    }
}

void st_add(vll &st, int tl, int tr, int pos, int left, int right, ll val){
    if(tr < left || right < tl){
        return;
    }
    if(left <= tl && tr <= right){
        st[pos] += val;
        return;
    }
    st_add(st, tl, tl + (tr - tl) / 2, pos * 2, left, right, val);
    st_add(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right, val);
}

const int A = 3e5 + 10;
// const int A = 10;

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vll ans(n);

    vll st(4*A);
    
    Node* root = new Node(v[0]);
    
    for(int j = 0; j*v[0] < A; j++){
        int l = j*v[0], r = min(A, (j+1)*v[0]-1);
        // debug(l, r);
        st_add(st, 0, A-1, 1, l, r, (ll) j*v[0]);
    }
    for(int i = 1; i < n; i++){
        ans[i] += ans[i-1];
        // x mod v[i]
        vector<Node*> sp;
        for(int j = v[i]; j < A; j+=v[i]){
            Node* t;
            tie(t, root) = split(root, j);
            sp.push_back(t);
        }
        sp.push_back(root);
        root = 0;
        for(int j = 0; j < sp.size(); j++){
            ans[i] += get_sum(sp[j]) - ((ll) cnt(sp[j]) * v[i] * j);
            root = merge(root, sp[j]);
        }

        // v[i] mod x
        // debug( i * v[i] - st_get(st, 0, A-1, 1, v[i]));
        // debug(st_get(st, 0, A-1, 1, v[i]));
        ans[i] += (ll) i * v[i] - st_get(st, 0, A-1, 1, v[i]);

        // add v[i] to st
        for(int j = 0; j*v[i] < A; j++){
            int l = j*v[i], r = min(A, (j+1)*v[i]-1);
            // debug(l, r);
            st_add(st, 0, A-1, 1, l, r, (ll) j*v[i]);
        }

        // v[i] mod x
        // vi multiple;
        // sp.clear();
        // int thres = isqrt(v[i]);
        // for(int j = 2; j <= thres+2; j++){
        //     Node* t;
        //     tie(t, root) = split(root, j);
        //     multiple.push_back(v[i] / (j-1));
        //     sp.push_back(t);
        // }
        // for(int j = thres; j >= 0; j--){
        //     Node* t;
        //     tie(t, root) = split(root, (v[i]/(j+1)+1));
        //     multiple.push_back(j+1);
        //     sp.push_back(t);
        // }
        // sp.push_back(root);
        // multiple.push_back(0);
        // root = 0;
        // for(int j = 0; j < sp.size(); j++){
        //     // ans[i] += get_sum(sp[j]) - (cnt(sp[j]) * v[i] * j);
        //     debug(multiple[j], cnt(sp[j]));
        //     ans[i] += (ll) cnt(sp[j]) * v[i] - (ll) multiple[j] * get_sum(sp[j]);
        //     root = merge(root, sp[j]);
        // }

        root = ins(root, new Node(v[i]));
        debug(root->sum);
    }
    debug(root->sum, root->val);
    debug(ans);
    for(ll i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}