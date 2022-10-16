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

// learning https://usaco.guide/adv/segtree-beats/

struct Node {
    int lo, hi, mid;
    ll sum;
    int sz;
    int maxi;
    Node *l, *r;
    Node(vi &v, int lo, int hi) : lo(lo), hi(hi) {
        sz = hi - lo;
        mid = lo + (hi - lo) / 2;
        if(lo + 1 == hi){
            sum = v[lo];
            maxi = v[lo];
        }else{
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            update();
        }
    }

    void update(){
        assert(lo + 1 < hi);
        sum = l->sum + r->sum;
        maxi = max(l->maxi, r->maxi);
    }

    ll get_sum(int a, int b){
        if(b <= lo || hi <= a) return 0;
        if(a <= lo && hi <= b) return sum;
        return l->get_sum(a, b) + r->get_sum(a, b);
    }

    void set(int pos, int val){
        if(sz == 1){
            sum = val;
            maxi = val;
        }else{
            if(pos < mid) {
                l->set(pos, val);
            }else{
                r->set(pos, val);
            }
            update();
        }
    }

    void mod(int a, int b, int x){
        if(b <= lo || hi <= a) return;
        if(sz == 1){
            set(lo, sum % x);
        }else if(a <= lo && hi <= b && maxi < x){
            // do nothing
        }else{
            l->mod(a, b, x);
            r->mod(a, b, x);
            update();
        }
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    Node* tree = new Node(v, 0, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            l--;
            ll res = tree->get_sum(l, r);
            cout << res << endl;
        }else if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            tree->mod(l, r, x);
        }else if(type == 3){
            int k, x;
            cin >> k >> x;
            k--;
            tree->set(k, x);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}