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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

struct Node{
    int lo, hi;
    ll val, madd = 0;
    Node *l, *r;

    void update(){
        val = min(l->val, r->val);
    }

    Node(int lo, int hi, vll &v) : lo(lo), hi(hi) {
        if(lo + 1 == hi){
            val = v[lo];
        }else{
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid, v);
            r = new Node(mid, hi, v);
            update();
        }
    }

    void add(int L, int R, ll num){
        // debug(lo, hi, L, R, num);
        if(hi <= L || R <= lo || L >= R) return;
        if(L <= lo && hi <= R){
            val += num;
            madd += num;
            return;
        }
        push();
        l->add(L, R, num);
        r->add(L, R, num);
        update();
    }

    ll query(int L, int R){
        // debug(lo, hi, L, R);
        if(hi <= L || R <= lo || L >= R) return 1e18;
        if(L <= lo && hi <= R){
            return val;
        }
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    
    void push(){
        if(madd != 0){
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
};

void dfs1(int u, vector<vpii> &children, vll &d, ll cur, vi &leaves, vi &ridx){
    d[u] = cur;
    bool leaf = true;
    ridx[u] = u + 1;
    for(pii p : children[u]){
        dfs1(p.first, children, d, cur + p.second, leaves, ridx);
        ridx[u] = ridx[p.first];
        leaf = false;
    }
    if(leaf){
        leaves.push_back(u);
    }
}

void dfs2(int u, vector<vpii> &children, vector<vector<pair<pii, int>>> &queries, vi &leaves, vi &ridx, Node* st, vll &ans){
    debug(u);
    for(pii p : children[u]){
        int lo = p.first, hi = ridx[p.first];
        // all leaves in [lo, hi)
        int l = lower_bound(leaves.begin(), leaves.end(), lo) - leaves.begin();
        int r = lower_bound(leaves.begin(), leaves.end(), hi) - leaves.begin();
        debug(l, r, p.second);
        st->add(l, r, -2*p.second);
        st->add(0, leaves.size(), p.second);
        dfs2(p.first, children, queries, leaves, ridx, st, ans);
        st->add(0, leaves.size(), -p.second);
        st->add(l, r, 2*p.second);
    }
    for(auto p : queries[u]){
        int lo, hi, idx;
        tie(lo, hi) = p.first;
        idx = p.second;
        int l = lower_bound(leaves.begin(), leaves.end(), lo) - leaves.begin();
        int r = lower_bound(leaves.begin(), leaves.end(), hi) - leaves.begin();
        debug(idx, l, r);
        ans[idx] = st->query(l, r);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    
    vector<vpii> children(n);
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--;
        children[x].push_back({i, y});
    }
    debug(children);

    vll dist(n);
    vi leaves;
    vi ridx(n);
    dfs1(0, children, dist, 0, leaves, ridx);

    debug(leaves);
    debug(ridx);

    vll d;
    for(int i : leaves){
        d.push_back(dist[i]);
    }
    debug(d);
    Node* st = new Node(0, (int) d.size(), d);

    // {{l, r}, idx}
    vector<vector<pair<pii, int>>> queries(n);
    for(int i = 0; i < q; i++){
        int v, l, r;
        cin >> v >> l >> r;
        v--;l--;
        queries[v].push_back({{l, r}, i});
    }

    vll ans(q);
    dfs2(0, children, queries, leaves, ridx, st, ans);

    for(ll i : ans) cout << i << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}