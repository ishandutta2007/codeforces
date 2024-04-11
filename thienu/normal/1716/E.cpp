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
    Node *l, *r;
    int lo, mid, hi;
    int depth;
    ll full, pref, suf, internal;
    Node(int lo, int hi, vi &v) : lo(lo), hi(hi){
        int mid = lo + (hi - lo) / 2;
        if(lo + 1 == hi){
            depth = -1;
            full = v[lo];
            pref = max(v[lo], 0);
            suf = max(v[lo], 0);
            internal = max(v[lo], 0);
        }else{
            l = new Node(lo, mid, v);
            r = new Node(mid, hi, v);
            depth = l->depth + 1;
            calc();
        }
    }

    void calc(){
        full = l->full + r->full;
        pref = max(l->pref, l->full + r->pref);
        suf = max(r->suf, r->full + l->suf);
        internal = max({l->internal, r->internal, l->suf + r->pref});
    }

    void swap_children(int swap_depth){
        debug(lo, hi, depth, swap_depth);
        if(swap_depth == depth){
            swap(l, r);
            calc();
            return;
        }
        l->swap_children(swap_depth);
        r->swap_children(swap_depth);
        calc();
    }

    vll get_list(){
        if(lo + 1 == hi) return vector<ll>{full};
        else{
            vll x = l->get_list();
            vll y = r->get_list();
            for(int i : y){
                x.push_back(i);
            }
            return x;
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vi v(1 << n);
    for(int i = 0; i < (1 << n); i++){
        cin >> v[i];
    }

    Node* tree = new Node(0, 1 << n, v);
    debug(tree->internal);

    int current = 0;
    vll answers(1 << n);
    answers[current] = tree->internal;
    for(int msk = 1; msk < (1 << n); msk++){
        debug(current, tree->get_list(), tree->internal);
        int b = __builtin_ctz(msk);
        int d = n - b - 1;
        debug(msk, d);
        tree->swap_children(d);
        current ^= (1 << b);
        answers[current] = tree->internal;
    }
    debug(answers);

    int q;
    cin >> q;
    current = 0;
    while(q--){
        int d;
        cin >> d;
        int b = n - d - 1;
        current ^= (1 << b);
        cout << answers[current] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}